#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    //On ajoute le layout à l'onglet pour que son contenu soit redimentionné.
    ui->tab->setLayout(ui->vLayoutWeb);

    //On retire le second onglet.
    ui->tabNavigateur->removeTab(1);

    //On set l'URL de la page d'accueil.
    QUrl urlAccueil("http://www.google.fr");
    ui->web->setUrl(urlAccueil);

    //Mise en place de la progessBar
    m_loadingBar = new QProgressBar();
    ui->vLayoutWeb->addWidget(m_loadingBar);

    //Menu
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

    //Boutons
    connect(ui->btPrecedent, SIGNAL(clicked()), this, SLOT(allerPagePrecedente()));
    connect(ui->btSuivant, SIGNAL(clicked()), this, SLOT(allerPageSuivante()));
    connect(ui->btActualiser, SIGNAL(clicked()), this, SLOT(rechargerPage()));
    connect(ui->btStopChargement, SIGNAL(clicked()), this, SLOT(stopChargement()));
    connect(ui->btHome, SIGNAL(clicked()), this, SLOT(allerAccueil()));
    connect(ui->btAllerURL, SIGNAL(clicked()), this, SLOT(allerURL()));

    connect(ui->web, SIGNAL(loadProgress(int)), m_loadingBar , SLOT(setValue(int)));
    connect(webViewActive(), SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ouvrirTab()
{
    //Mise en place du nouvel onglet.
    QWidget * onglet = new QWidget();
    onglet->setObjectName("NouvelOnglet");

    QVBoxLayout * layoutOnglet = new QVBoxLayout();
    layoutOnglet->setObjectName("layoutOnglet");

    QWebEngineView * nouvelleWebView = new QWebEngineView();
    nouvelleWebView->setObjectName("web");

    layoutOnglet->addWidget(nouvelleWebView);

    onglet->setLayout(layoutOnglet);

    int index = ui->tabNavigateur->addTab(onglet, "Nouvel onglet");
    ui->tabNavigateur->setCurrentIndex(index);

    m_loadingBar = new QProgressBar();
    layoutOnglet->addWidget(m_loadingBar);

    connect(nouvelleWebView, SIGNAL(loadProgress(int)), m_loadingBar , SLOT(setValue(int)));
    connect(webViewActive(), SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
}

void MainWindow::fermerTab()
{
    //On garde toujours un onglet actif.
    if(ui->tabNavigateur->count() > 1)
    {
        ui->tabNavigateur->removeTab(ui->tabNavigateur->currentIndex());
    }
}

void MainWindow::allerPagePrecedente()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->back();
    }
}

void MainWindow::allerPageSuivante()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->forward();
    }
}

void MainWindow::rechargerPage()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->reload();
    }
}

void MainWindow::stopChargement()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->stop();
    }
}

void MainWindow::allerAccueil()
{
    QUrl urlAccueil("http://www.google.fr");

    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->setUrl(urlAccueil);
    }
}

QWebEngineView * MainWindow::webViewActive()
{
    //On regarde sur quel onglet on est.
    QWidget * ongletActif = ui->tabNavigateur->currentWidget();

    //On récupére le QWebEngineView associé à l'onglet.
    QWebEngineView * webCourrant = ongletActif->findChild<QWebEngineView *>("web");

    return webCourrant;
}

void MainWindow::allerURL()
{
    QUrl url(ui->barreURL->text());

    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr && url.isValid())
    {
        m_webCourrant->setUrl(url);
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
    QString titreReduit = webViewActive()->title();
    titreReduit.truncate(30);

    QWidget * onglet = webViewActive()->parentWidget();
    ui->tabNavigateur->setTabText(ui->tabNavigateur->indexOf(onglet), titrePage);
}
