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

    QListView *vueClients = new QListView;

    listeClientsConnectes << "Pas d'utilisateurs connectés";
    modeleClients = new QStringListModel(listeClientsConnectes);
    vueClients->setModel(modeleClients);
    layout->addWidget(vueClients);

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
    //qDebug() << QTime::currentTime() << " - nouvelleConnexion --------DEBUT--------";

    client *nouveauClient = new client();

    nouveauClient->setClientTcpSocket(serveur->nextPendingConnection());
    clients << nouveauClient;

    etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                         + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));

    connect(nouveauClient->getClientTcpSocket(), SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient->getClientTcpSocket(), SIGNAL(disconnected()), this, SLOT(deconnexionClient()));

    //qDebug() << QTime::currentTime() << " - nouvelleConnexion --------FIN--------";
}

void FenServeur::donneesRecues()
{
    //qDebug() << QTime::currentTime() << " - donneesRecues --------DEBUT--------";

    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == nullptr) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
    {
        //qDebug() << QTime::currentTime() << " - donneesRecues : le QTcpSocket du client est nullptr";
        return;
    }

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
    {
        //qDebug() << QTime::currentTime() << " - donneesRecues : Arrêt de la méthode, on n'a pas tout reçu";
        return;
    }

    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
    QString message;
    in >> message;

    if(clients.last()->getPseudo() == "")
    {
        //qDebug() << QTime::currentTime() << " - donneesRecues : on ne connait pas le pseudo";
        //Si le pseudo est déjà utilisé on retourne un message d'erreur au client.
        if(!verifierUnicitePseudo(message))
        {
            //qDebug() << QTime::currentTime() << " - donneesRecues : le pseudo est déjà utilisé";

            //On indique on client qu'il ne peut pas utiliser ce pseudo.
            envoyerAUnClient("<strong> Ce pseudo est déjà utilisé. </strong>", clients.last()->getClientTcpSocket());
            //On ferme la connexion pour que le client se connecte avec un autre pseudo.
            clients.last()->getClientTcpSocket()->close();
            clients.removeOne(clients.last());
            //Remise de la taille du message à 0 pour permettre la réception des futurs messages
            tailleMessage = 0;
            return;
        }
        else
        {
            //Le pseudo n'est pas déjà utilisé donc on ajoute le client aux clients connectés.
            nbrClients++;
            etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                                 + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));
            listeClientsConnectes.removeOne("Pas d'utilisateurs connectés");
            listeClientsConnectes << message; //C'est le peudo du nouveau client.
            listeClientsConnectes.removeDuplicates();
            modeleClients->setStringList(listeClientsConnectes);//Actualise la liste des clients affichée.
            clients.last()->setPseudo(message);
            //qDebug() << QTime::currentTime() << " - donneesRecues : on a le pseudo : "+clients.last()->getPseudo();

            //On récupère la liste des clients connectés pour l'envoyé aux clients.
            QString pseudoClients = "";

            for(int i=0; i<listeClientsConnectes.size(); i++)
            {
                //On sépare les pseudos pour pouvoir les découper coté client.
                pseudoClients += listeClientsConnectes[i]+"/";
            }

            //On indique aux clients qu'un nouveau client s'est connecté et on envoie la liste des clients.
            envoyerATous("<em>"+clients.last()->getPseudo()+tr(" vient de se connecter.</em>")+"-DEBUT-"+pseudoClients);
        }
    }
    else //Là c'est un message dans la discussion.
    {
        // 2 : on renvoie le message à tous les clients
        envoyerATous(message);
    }

    // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
    tailleMessage = 0;

    //qDebug() << QTime::currentTime() << " - donneesRecues --------FIN--------";
}

void FenServeur::deconnexionClient()
{
    //qDebug() << QTime::currentTime() << " - deconnexionClient --------DEBUT--------";

    // On détermine quel client se déconnecte
    QTcpSocket *socket = determinerClientEnCours();
    if (socket == nullptr) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    //On cherche dans les clients celui qui a pour socket celle qui a demandé la déconnexion.
    for(int i = 0; i <clients.size(); i++)
    {

        if(socket == clients[i]->getClientTcpSocket())
        {
            listeClientsConnectes.removeOne(clients[i]->getPseudo());

            //Si plus de clients connectés
            if(listeClientsConnectes.empty())
            {
                listeClientsConnectes << "Pas d'utilisateurs connectés";
            }

            //Actualise la liste des clients affichée sur le serveur.
            modeleClients->setStringList(listeClientsConnectes);

            QString pseudoClients = "";

            //On récupère la liste des clients encore connectés pour l'envoyer aux clients.
            for(int i=0; i<listeClientsConnectes.size(); i++)
            {
                pseudoClients += listeClientsConnectes[i]+"/";
            }

            envoyerATous("<em>"+clients[i]->getPseudo()+tr(" vient de se déconnecter</em>")+"-FIN-"+pseudoClients);
            clients.removeOne(clients[i]);
            nbrClients--;

            etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.")
                                 + tr("<br />Il y a ")+QString::number(nbrClients)+tr(" clients connectés."));

            socket->deleteLater();
        }
    }

    //qDebug() << QTime::currentTime() << " - deconnexionClient --------FIN--------";
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

bool FenServeur::verifierUnicitePseudo(QString PseudoNouveauClient)
{
    if(listeClientsConnectes.contains(PseudoNouveauClient))
    {
        return false;
    }

    return true;
}

void FenServeur::envoyerAUnClient(const QString &message, QTcpSocket *socket)
{
    // Préparation du paquet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << static_cast<quint16>(0); // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << static_cast<quint16> (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message

    // On détermine quel client
    //QTcpSocket *socket = determinerClientEnCours();
    if (socket == nullptr) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    for(int i = 0; i <clients.size(); i++)
    {
        if(socket == clients[i]->getClientTcpSocket())
        {
            //qDebug() << "envoyerAUnClient : envoi du message";
            clients[i]->getClientTcpSocket()->write(paquet);
        }
    }
}

QTcpSocket * FenServeur::determinerClientEnCours()
{
    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    return socket;
}
