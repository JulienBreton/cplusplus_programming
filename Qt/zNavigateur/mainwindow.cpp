#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    //Attache le layout global au centralwidget pour que lorsque la fenêtre est redimentionnée son contenu le soit aussi.
    ui->centralwidget->setLayout(ui->vLayoutFenetre);

    //Création de la QTabWidget qui va contenir les onglets.
    //On l'attache à un layout vertical situé sous le layout horizontal de la toolBar de navigation.
    m_tabOnglets = new QTabWidget();
    ui->hLayoutTab->addWidget(m_tabOnglets);

    ui->menuHistorique->setStyleSheet("QMenu { menu-scrollable: 1; }");

    //On créé le .ini
    m_sSettingsFile = QApplication::applicationDirPath() + "/zNavigo.ini";
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);

    //On crée le premier onglet ainsi que la webView qu'il contient.
    ouvrirTab();

    connecterDatabase();

    //Programmation du déclenchement des slots du menu.
    connect(ui->actionOuvrirOnglet, SIGNAL(triggered()), this, SLOT(ouvrirTab()));
    connect(ui->actionFermerOnglet, SIGNAL(triggered()), this, SLOT(fermerTab()));
    connect(ui->actionPageprecedente, SIGNAL(triggered()), this, SLOT(allerPagePrecedente()));
    connect(ui->actionPageSuivante, SIGNAL(triggered()), this, SLOT(allerPageSuivante()));
    connect(ui->actionActualiser, SIGNAL(triggered()), this, SLOT(rechargerPage()));
    connect(ui->actionArreter, SIGNAL(triggered()), this, SLOT(stopChargement()));
    connect(ui->actionAccueil, SIGNAL(triggered()), this, SLOT(allerAccueil()));
    connect(ui->actionAllerURL, SIGNAL(triggered()), this, SLOT(allerURL()));
    connect(ui->actionAProposDezNavigo, SIGNAL(triggered()), this, SLOT(afficherAProposzNavigo()));
    connect(ui->actionAProposDeQt, SIGNAL(triggered()), this, SLOT(afficherAProposQt()));
    connect(ui->actionChercher, SIGNAL(triggered()), this, SLOT(chercherDansPageWeb()));
    connect(ui->actionOptions, SIGNAL(triggered()), this, SLOT(editerOptions()));
    connect(ui->actionAjouter_aux_favoris, SIGNAL(triggered()), this, SLOT(ajouterAuxFavoris()));
    connect(ui->actionSupprimerFavoris, SIGNAL(triggered()), this, SLOT(supprimerDesFavoris()));
    connect(ui->actionViderHistorique, SIGNAL(triggered()), this, SLOT(supprimerHistorique()));

    //Programmation du déclenchement des boutons de la toolBar de navigation.
    connect(ui->btPrecedent, SIGNAL(clicked()), this, SLOT(allerPagePrecedente()));
    connect(ui->btSuivant, SIGNAL(clicked()), this, SLOT(allerPageSuivante()));
    connect(ui->btActualiser, SIGNAL(clicked()), this, SLOT(rechargerPage()));
    connect(ui->btStopChargement, SIGNAL(clicked()), this, SLOT(stopChargement()));
    connect(ui->btHome, SIGNAL(clicked()), this, SLOT(allerAccueil()));
    connect(ui->btAllerURL, SIGNAL(clicked()), this, SLOT(allerURL()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ouvrirTab()
{
    //Définition du nouvel onglet.
    QWidget * onglet = new QWidget();

    QVBoxLayout * layoutOnglet = new QVBoxLayout();

    QWebEngineView * nouvelleWebView = new QWebEngineView();

    layoutOnglet->addWidget(nouvelleWebView);

    onglet->setLayout(layoutOnglet);

    m_tabOnglets->addTab(onglet, "nouvel onglet");
    //On passe sur le nouvel onglet.
    m_tabOnglets->setCurrentIndex(m_tabOnglets->indexOf(onglet));

    //On récupère l'url de la page d'accueil dans le .ini
    settings = new QSettings(m_sSettingsFile, QSettings::IniFormat);
    QUrl urlAccueil(settings->value("urlAccueil","").toString());
    nouvelleWebView->setUrl(urlAccueil);
    actualiserBarreURL(urlAccueil);

    updateTaillePolice(nouvelleWebView);

    QProgressBar * loadingBar = new QProgressBar();
    layoutOnglet->addWidget(loadingBar);

    connect(nouvelleWebView, SIGNAL(loadProgress(int)), loadingBar, SLOT(setValue(int)));
    connect(nouvelleWebView, SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
    connect(nouvelleWebView, SIGNAL(urlChanged(QUrl)), this, SLOT(actualiserBarreURL(QUrl)));

    connect(m_tabOnglets, SIGNAL(currentChanged(int)), this, SLOT(actualiserApresChangementOnglet(int)));
}

void MainWindow::fermerTab()
{
    //On garde toujours un onglet actif.
    if(m_tabOnglets->count() > 1)
    {
        m_tabOnglets->removeTab(m_tabOnglets->currentIndex());
    }
}

void MainWindow::allerPagePrecedente()
{
    if(webViewActive() != nullptr)
    {
        webViewActive()->back();
    }
}

void MainWindow::allerPageSuivante()
{

    if(webViewActive() != nullptr)
    {
        webViewActive()->forward();
    }
}

void MainWindow::rechargerPage()
{
    if(webViewActive() != nullptr)
    {
        webViewActive()->reload();
    }
}

void MainWindow::stopChargement()
{
    if(webViewActive() != nullptr)
    {
        webViewActive()->stop();
    }
}

void MainWindow::allerAccueil()
{
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    QUrl urlAccueil(settings.value("urlAccueil","").toString());

    if(webViewActive() != nullptr)
    {
        webViewActive()->setUrl(urlAccueil);
    }
}

QWebEngineView * MainWindow::webViewActive()
{
    //On regarde sur quel onglet on est.
    QWidget * ongletActif = m_tabOnglets->currentWidget();

    //On récupére le QWebEngineView associé à l'onglet.
    QWebEngineView * webCourrant = ongletActif->findChild<QWebEngineView *>();

    return webCourrant;
}

void MainWindow::allerURL()
{
    QUrl url(ui->barreURL->text());

    if(webViewActive() != nullptr && url.isValid())
    {
        webViewActive()->setUrl(url);
    }
}

void MainWindow::afficherAProposzNavigo()
{
    QMessageBox msgBox;
    msgBox.about(this, "zNavigo", "Navigateur zNavigo\nJulien Breton\nFévrier 2020.");
}

void MainWindow::afficherAProposQt()
{
    QMessageBox msgBox;
    msgBox.aboutQt(this);
}

void MainWindow::actualiserTitreOnglet(QString titrePage)
{
    //La difficulté ici est d'actualiser le titre du bon onglet.
    //En effet ce n'est pas obligatoirement l'onglet courant qui contient la page en cours de chargement
    //car l'utilisateur a très bien pu changer d'onglet après avoir lancé le chargement.
    //Il faut donc déterminer dans quel onglet est la page que l'on charge et ainsi actualiser le titre de l'onglet qui va bien.

    //On réduite le titre de la page.
    titrePage.remove(30);

    //On récupére l'objet qui a émis le signal (c'est une QWebEngineView).
    QObject* obj = sender();

    //On convertit cet obj en QWebEngineView pour pouvoir en obtenir son parent (qui est l'onglet qui contient la QWebEngineView).
    QWebEngineView * webCourrant = qobject_cast<QWebEngineView *>(obj);
    QObject * parentDeWebCourant = webCourrant->parent();
    QWidget * ongletDeWebCourant = qobject_cast<QWidget *>(parentDeWebCourant);

    //On met le titre de la page Web comme titre de l'onglet où la page Web est chargée.
    m_tabOnglets->setTabText(m_tabOnglets->indexOf(ongletDeWebCourant), titrePage);

   setTitreFenetreNavigateur();

   obtenirHistorique();
}

void MainWindow::actualiserBarreURL(const QUrl & url)
{
    ui->barreURL->setText(url.toString());
}

void MainWindow::actualiserApresChangementOnglet(int index)
{
    //On change d'onglet donc on met à jour le titre de la fenêtre du navigateur avec le titre de la page Web en cours.
    setTitreFenetreNavigateur();

    //On actualise aussi la barre de saisie de l'URL.
    actualiserBarreURL(webViewActive()->url());

    //On met à jour la taille de la police.
    updateTaillePolice(webViewActive());
}

void MainWindow::setTitreFenetreNavigateur()
{
    setWindowTitle(webViewActive()->title()+" - zNavigo");
}

void MainWindow::obtenirHistorique()
{
    m_historique = webViewActive()->history()->items();

    if(m_historique.last().title() != "")
    {
        QAction * actionHisto = ui->menuHistorique->addAction(m_historique.last().title()+" [URL]: "+m_historique.last().url().toString());
        connect(actionHisto, SIGNAL(triggered()), this, SLOT(ajouterURLActionHisto()));
    }
}

void MainWindow::ajouterURLActionHisto()
{
    QObject* obj = sender();

    QAction * action = qobject_cast<QAction *>(obj);
    QString textAction = action->text();
    QStringList list = textAction.split(" [URL]: ");
    QString URL = list[1];

    webViewActive()->setUrl(URL);
}

void MainWindow::chercherDansPageWeb()
{
    bool ok = false;
    QString search = QInputDialog::getText(this, tr("Recherche"),
                                           tr("Recherche:"), QLineEdit::Normal,
                                           "", &ok);
    webViewActive()->findText(search);
}

void MainWindow::editerOptions()
{
    fntOptions options(this);

    options.exec();

    updateTaillePolice(webViewActive());
}

QString MainWindow::getChemiFichierIni()
{
    return m_sSettingsFile;
}

void MainWindow::updateTaillePolice(QWebEngineView * pageActive)
{
    QWebEngineSettings *defaultSettings = pageActive->settings();
    defaultSettings->setFontSize(QWebEngineSettings::MinimumFontSize,settings->value("taillePolice","").toInt());
}

bool MainWindow::connecterDatabase()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
         //qDebug() << "Driver SQLite dispo OK!!!";

         QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

         db.setDatabaseName("favoris");

         if(!db.open())
         {
            qWarning() << "ERROR: " << db.lastError();
            return false;
         }
         else
         {
            //qDebug() << "Ouverture de la base OK!!!";

            QSqlQuery query("CREATE TABLE IF NOT EXISTS favoris (id INTEGER PRIMARY KEY, libelle TEXT, url TEXT)");

            if(!query.isActive())
            {
                qWarning() << "ERROR: " << query.lastError().text();
                return false;
            }

            //if(!query.exec("INSERT INTO favoris(libelle) VALUES('Eddie Guerrero')"))
            //  qWarning() << "ERROR: " << query.lastError().text();

            populateFavoris();

         }

         return true;
    }

    //qDebug() << "Driver SQLite absent KO!!!";
    return false;
}

void MainWindow::ajouterAuxFavoris()
{
    QSqlQuery query;

    if(!query.exec("INSERT INTO favoris (libelle, url) VALUES ('"+webViewActive()->title()+"', '"+webViewActive()->url().toString()+"')"))
      qWarning() << "ERROR: " << query.lastError().text();

    QAction * actionFavoris = ui->menuFavoris->addAction(webViewActive()->title());
    connect(actionFavoris, SIGNAL(triggered()), this, SLOT(allerUrlFavoris()));
}

void MainWindow::populateFavoris()
{
    QSqlQuery query;
    query.prepare("SELECT libelle FROM favoris");

    if(!query.exec())
            qWarning() << "Erreur lors du populate!!" << query.lastError().text();

    while(query.next())
    {
        //qDebug() << "Résultat select : " << query.value(0).toString();
        QAction * actionFavoris = ui->menuFavoris->addAction(query.value(0).toString());
        connect(actionFavoris, SIGNAL(triggered()), this, SLOT(allerUrlFavoris()));
    }
}

void MainWindow::allerUrlFavoris()
{
    QObject* obj = sender();

    QAction * action = qobject_cast<QAction *>(obj);
    //QString textAction = action->text();
    //qDebug() << "Nom de l'action cliqué : " << action->text();
    QString url = getURLFavoris(action->text());

    webViewActive()->setUrl(url);
}

QString MainWindow::getURLFavoris(QString libelleFavoris)
{
    QSqlQuery query;
    query.prepare("SELECT url FROM favoris WHERE libelle = ?");
    query.addBindValue(libelleFavoris);

    if(!query.exec())
        qWarning() << "MainWindow::getURLFavoris - ERROR: " << query.lastError().text();

    if(query.first())
    {
        //qDebug() << "URL trouvée dans la base : " << query.value(0).toString();
        return query.value(0).toString();
    }
    else
       return "Pas d'URL associée au libellé";
}

void MainWindow::supprimerDesFavoris()
{
    //Récupérer l'URL en cours
    QUrl urlAsupprimer = webViewActive()->url();

    //Chercher l'URL dans la base
    QSqlQuery query;
    query.prepare("DELETE FROM favoris WHERE url = '"+urlAsupprimer.toString()+"'");
    //qDebug() << "URL à supprimer" << urlAsupprimer.toString();

    //Supprimer les entrées de la base qui ont cette url
    if(!query.exec())
        qWarning() << "MainWindow::supprimerDesFavoris - ERROR: " << query.lastError().text();

    QList<QAction *> actionsFavoris;

    actionsFavoris = ui->menuFavoris->actions();

    for(int i = 3; i < actionsFavoris.size(); i++)
    {
        //qDebug() << "Action à supprimer : " << actionsFavoris[i]->text();
        ui->menuFavoris->removeAction(actionsFavoris[i]);
    }

    //Mettre à jour la liste des favoris.
    populateFavoris();
}

void MainWindow::supprimerHistorique()
{
    QList<QAction *> actionsHisto;

    actionsHisto = ui->menuHistorique->actions();

    for(int i = 2; i < actionsHisto.size(); i++)
    {
        //qDebug() << "Action à supprimer : " << actionsHisto[i]->text();
        ui->menuHistorique->removeAction(actionsHisto[i]);
    }
}
