#include "fenclient.h"
#include "ui_fenclient.h"

FenClient::FenClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FenClient)
{
    ui->setupUi(this);

    ui->boutonEnvoyer->setDisabled(true);
    ui->message->setDisabled(true);
    ui->message->setDisabled(true);

    ui->pseudo->setFocus();

    m_boutonCouleur = new QPushButton("Changer la couleur");
    m_boutonCouleur->setDisabled(true);
    m_boutonPolice = new QPushButton("Changer la police");
    m_boutonPolice->setDisabled(true);
    m_boutonSmiley = new QPushButton("Ajouter un smiley");
    m_boutonSmiley->setDisabled(true);

    ui->hLayoutPseudo->addWidget(ui->label_3, 6, nullptr);
    ui->hLayoutPseudo->addWidget(ui->pseudo, 6, nullptr);
    ui->layoutButtons->addWidget(ui->boutonEnvoyer, 6, nullptr);
    ui->layoutButtons->addWidget(m_boutonCouleur, 6, nullptr);
    ui->layoutButtons->addWidget(m_boutonPolice, 6, nullptr);
    ui->layoutButtons->addWidget(m_boutonSmiley, 6, nullptr);

    QListView *vueClients = new QListView;

    listeClientsConnectes << "Vous n'êtes pas connecté au serveur.";
    modeleClients = new QStringListModel(listeClientsConnectes);
    vueClients->setModel(modeleClients);
    vueClients->setDisabled(true);
    ui->layoutButtons->addWidget(vueClients);

    QRegExp rx("^[a-zA-Z0-9]+$");
    QRegExpValidator * pseudoValidator = new QRegExpValidator(rx, ui->pseudo);
    ui->pseudo->setValidator(pseudoValidator);

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    connect(m_boutonCouleur, SIGNAL(clicked()), this, SLOT(changerCouleur()));
    connect(m_boutonPolice, SIGNAL(clicked()), this, SLOT(changerPolice()));
    connect(m_boutonSmiley, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));

    tailleMessage = 0;
    sMessageAEnvoye = "";
}

FenClient::~FenClient()
{
    delete ui;
}

// Tentative de connexion au serveur
void FenClient::on_boutonConnexion_clicked()
{
    if(ui->pseudo->text().size() < 3)
    {
         QMessageBox::warning(this, "Votre pseudo", "La taille minimale du pseudo est de 3 caractères alphanumériques.");
         return;
    }

    // On annonce sur la fenêtre qu'on est en train de se connecter
    ui->listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    ui->boutonConnexion->setEnabled(false);

    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ui->serveurIP->text(), ui->serveurPort->value()); // On se connecte au serveur demandé

    ui->boutonEnvoyer->setDisabled(false);
    ui->message->setDisabled(false);
    ui->pseudo->setDisabled(true);
    m_boutonCouleur->setDisabled(false);
    m_boutonPolice->setDisabled(false);
    m_boutonSmiley->setDisabled(false);

}

// Envoi d'un message au serveur
void FenClient::on_boutonEnvoyer_clicked()
{

    if(ui->message->toPlainText() == "")
    {
         QMessageBox::warning(this, "Votre message", "Vous devez saisir un message.");
         return;
    }

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = tr("<strong>") + ui->pseudo->text() +tr("</strong> : ") + ui->message->toHtml();

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    ui->message->clear(); // On vide la zone d'écriture du message
    ui->message->setFocus(); // Et on remet le curseur à l'intérieur
}

// On a reçu un paquet (ou un sous-paquet)
void FenClient::donneesRecues()
{
    /* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    */
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
    QString messageRecu;
    in >> messageRecu;

    if(messageRecu.contains("-DEBUT-"))
    {
        QStringList messageConnexion =  messageRecu.split("-DEBUT-");
        messageRecu = messageConnexion[0];
        listeClientsConnectes.removeOne("Vous n'êtes pas connecté au serveur.");
        listeClientsConnectes << messageConnexion[1];
        QStringList pseudosUers = messageConnexion[1].split("/");
        pseudosUers.removeDuplicates();
        modeleClients->setStringList(pseudosUers);
    }

    if(messageRecu.contains("-FIN-"))
    {
        QStringList messageConnexion =  messageRecu.split("-FIN-");
        messageRecu = messageConnexion[0];
        listeClientsConnectes << messageConnexion[1];
        QStringList pseudosUers = messageConnexion[1].split("/");
        modeleClients->setStringList(pseudosUers);
    }

    // On affiche le message sur la zone de Chat
    ui->listeMessages->append(messageRecu);

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void FenClient::connecte()
{
    envoyerPseudo();
    ui->listeMessages->append(tr("<em>Connexion réussie !</em>"));
    ui->boutonConnexion->setEnabled(true);
}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void FenClient::deconnecte()
{
    ui->listeMessages->append(tr("<em>Déconnecté du serveur</em>"));
}

// Ce slot est appelé lorsqu'il y a une erreur
void FenClient::erreurSocket(QAbstractSocket::SocketError erreur)
{
    QStringList pseudosUsers;

    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            ui->listeMessages->append(tr("<em>ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.</em>"));
            ui->boutonEnvoyer->setDisabled(true);
            ui->message->setDisabled(true);
            ui->pseudo->setDisabled(false);
            m_boutonCouleur->setDisabled(true);
            m_boutonPolice->setDisabled(true);
            m_boutonSmiley->setDisabled(true);
            pseudosUsers.clear();
            pseudosUsers << "Vous n'êtes pas connecté au serveur.";
            modeleClients->setStringList(pseudosUsers);
            break;
        case QAbstractSocket::ConnectionRefusedError:
            ui->listeMessages->append(tr("<em>ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port.</em>"));
            ui->boutonEnvoyer->setDisabled(true);
            ui->message->setDisabled(true);
            ui->pseudo->setDisabled(false);
            m_boutonCouleur->setDisabled(true);
            m_boutonPolice->setDisabled(true);
            m_boutonSmiley->setDisabled(true);
            pseudosUsers.clear();
            pseudosUsers << "Vous n'êtes pas connecté au serveur.";
            modeleClients->setStringList(pseudosUsers);
            break;
        case QAbstractSocket::RemoteHostClosedError:
            ui->listeMessages->append(tr("<em>ERREUR : le serveur a coupé la connexion.</em>"));
            ui->boutonEnvoyer->setDisabled(true);
            ui->message->setDisabled(true);
            ui->pseudo->setDisabled(false);
            m_boutonCouleur->setDisabled(true);
            m_boutonPolice->setDisabled(true);
            m_boutonSmiley->setDisabled(true);
            pseudosUsers.clear();
            pseudosUsers << "Vous n'êtes pas connecté au serveur.";
            modeleClients->setStringList(pseudosUsers);
            break;
        default:
            ui->listeMessages->append(tr("<em>ERREUR : ") + socket->errorString() + tr("</em>"));
            ui->boutonEnvoyer->setDisabled(true);
            ui->message->setDisabled(true);
            ui->pseudo->setDisabled(false);
            m_boutonCouleur->setDisabled(true);
            m_boutonPolice->setDisabled(true);
            m_boutonSmiley->setDisabled(true);
            pseudosUsers.clear();
            pseudosUsers << "Vous n'êtes pas connecté au serveur.";
            modeleClients->setStringList(pseudosUsers);
    }

    ui->boutonConnexion->setEnabled(true);
}

void FenClient::envoyerPseudo()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = ui->pseudo->text();

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

    ui->message->clear(); // On vide la zone d'écriture du message
    ui->message->setFocus(); // Et on remet le curseur à l'intérieur
}

void FenClient::changerCouleur()
{
    QColorDialog * lesCouleurs = new QColorDialog();

    QColor couleur = lesCouleurs->getColor(Qt::white, this);

    //It returns an invalid (see QColor::isValid()) color if the user cancels the dialog.
    if(couleur.isValid())
    {
        ui->message->setTextColor(couleur);
    }

}

void FenClient::changerPolice()
{
    bool ok = false;

    QFont police = QFontDialog::getFont(&ok, QFont("Times", 12), ui->message, "Choisissez une police");

    if (ok)
    {
        QString texteSelectionne = ui->message->textCursor().selectedText();

        if(ui->message->textCursor().selectedText() != "")
        {
            ui->message->setCurrentFont(police);
        }
    }
}

void FenClient::ajouterSmiley()
{
    smiley * fenSmiley = new smiley();

    int result = fenSmiley->exec();

    fenSmiley->getSmileyChoisi();

    if(result == QDialog::Accepted)
    {
        if(fenSmiley->getSmileyChoisi() != "")
        {
            QString message = ui->message->toHtml();
            ui->message->setText(message+fenSmiley->getSmileyChoisi());
        }
    }

}
