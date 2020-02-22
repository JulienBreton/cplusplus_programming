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

    //On crée le premier onglet ainsi que la webView qu'il contient.
    ouvrirTab();

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

    QUrl urlAccueil("http://www.google.fr");
    nouvelleWebView->setUrl(urlAccueil);

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
    QUrl urlAccueil("http://www.google.fr");

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
}

void MainWindow::setTitreFenetreNavigateur()
{
    setWindowTitle(webViewActive()->title()+" - zNavigo");
}

