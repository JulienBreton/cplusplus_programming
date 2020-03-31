#include "fenserveur.h"
#include "ui_fenserveur.h"

FenServeur::FenServeur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FenServeur)
{
    ui->setupUi(this);

    nbrClients = 0;

    // Création et disposition des widgets de la fenêtre
    etatServeur = new QLabel;
    boutonQuitter = new QPushButton(tr("Quitter"));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    layout->addWidget(boutonQuitter);
    setLayout(layout);

    QListView *vueCliens = new QListView;

    listeClientsConnectes << "Pas d'utilisateurs connectés";
    QStringListModel * modeleClients = new QStringListModel(listeClientsConnectes);
    vueCliens->setModel(modeleClients);
    layout->addWidget(vueCliens);

    setWindowTitle(tr("ZeroChat - Serveur"));

    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
        etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a été démarré correctement
        etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                             + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }

    tailleMessage = 0;
}

FenServeur::~FenServeur()
{
    delete ui;
}

void FenServeur::nouvelleConnexion()
{
    client *nouveauClient = new client();

    nouveauClient->setClientTcpSocket(serveur->nextPendingConnection());
    clients << nouveauClient;
    nbrClients++;

    etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                         + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));

    connect(nouveauClient->getClientTcpSocket(), SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient->getClientTcpSocket(), SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

void FenServeur::donneesRecues()
{
    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == nullptr) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    // Si tout va bien, on continue : on récupère le message
    QDataStream in(socket);

    if (tailleMessage == 0) // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
    {
        if (socket->bytesAvailable() < static_cast<int>(sizeof(quint16))) // On n'a pas reçu la taille du message en entier
             return;

        in >> tailleMessage; // Si on a reçu la taille du message en entier, on la récupère
    }

    // Si on connaît la taille du message, on vérifie si on a reçu le message en entier
    if (socket->bytesAvailable() < tailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;


    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
    QString message;
    in >> message;

    if(clients.last()->getPseudo() == "")
    {
        listeClientsConnectes << message;
        clients.last()->setPseudo(message);
        envoyerATous("<em>"+clients.last()->getPseudo()+tr(" vient de se connecter.</em>"));
    }
    else
    {
        // 2 : on renvoie le message à tous les clients
        envoyerATous(message);
    }

    // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
    tailleMessage = 0;
}

void FenServeur::deconnexionClient()
{
    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == nullptr) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    //On cherche dans les clients celui qui a pour socket celle qui a demandé la déconnexion.
    for(int i = 0; i <clients.size(); i++)
    {

        if(socket == clients[i]->getClientTcpSocket())
        {
             envoyerATous("<em>"+clients[i]->getPseudo()+tr(" vient de se déconnecter</em>"));
            clients.removeOne(clients[i]);
            nbrClients--;

            etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                                 + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));

            socket->deleteLater();
        }
    }
}

void FenServeur::envoyerATous(const QString &message)
{
    // Préparation du paquet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << static_cast<quint16>(0); // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << static_cast<quint16> (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message

    // Envoi du paquet préparé à tous les clients connectés au serveur
    for (int i = 0; i < clients.size(); i++)
    {
         clients[i]->getClientTcpSocket()->write(paquet);
    }

}
