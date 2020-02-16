#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    m_webCourrant = new QWebEngineView();
    m_webCourrant = ui->web;

    QUrl urlAccueil("http://www.google.fr");
    m_webCourrant->setUrl(urlAccueil);

    ui->tab->setLayout(ui->vLayoutWeb);
    ui->tabNavigateur->removeTab(1);

    m_loadingBar = new QProgressBar();

    ui->vLayoutWeb->addWidget(m_loadingBar);

    //m_indexOngletEnChargement = 0;

    getOngletTitre(m_webCourrant);

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

    connect(webViewActive(), SIGNAL(loadProgress(int)), m_loadingBar , SLOT(setValue(int)));
    connect(webViewActive(), SIGNAL(loadStarted()), this , SLOT(getOngletTest()));
    //connect(ui->tabNavigateur, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));
    //connect(webViewActive(), SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ouvrirTab()
{
    QWidget * onglet = new QWidget();
    onglet->setObjectName("NouvelOnglet");

    QVBoxLayout * layoutOnglet = new QVBoxLayout();
    layoutOnglet->setObjectName("layoutOnglet");

    m_webCourrant = new QWebEngineView();
    m_webCourrant->setObjectName("web");

    layoutOnglet->addWidget(m_webCourrant);

    onglet->setLayout(layoutOnglet);

    int index = ui->tabNavigateur->addTab(onglet, "Nouvel onglet");
    ui->tabNavigateur->setCurrentIndex(index);

    m_loadingBar = new QProgressBar();
    layoutOnglet->addWidget(m_loadingBar);

    connect(webViewActive(), SIGNAL(loadProgress(int)), m_loadingBar , SLOT(setValue(int)));

    //getOngletTitre(m_webCourrant);

    connect(webViewActive(), SIGNAL(loadStarted()), this , SLOT(getOngletTest()));

    qDebug() << "---***ouvrirTab" << m_indexOngletEnChargement << "***---";
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
        getOngletTitre(m_webCourrant);
    }
}

void MainWindow::allerPageSuivante()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->forward();
        getOngletTitre(m_webCourrant);
    }
}

void MainWindow::rechargerPage()
{
    m_webCourrant = webViewActive();

    if(m_webCourrant != nullptr)
    {
        m_webCourrant->reload();
        getOngletTitre(m_webCourrant);
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
        getOngletTitre(m_webCourrant);
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
        getOngletTitre(m_webCourrant);
    }

}

void MainWindow::changementOnglet(int index)
{
    if(index <= 0)
    {
        m_webCourrant = webViewActive();
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
    ui->tabNavigateur->setTabText(m_indexOngletEnChargement, titrePage);
}

void MainWindow::getOngletTitre(QWebEngineView * web)
{
    QWidget * onglet = web->parentWidget();
    m_indexOngletEnChargement = ui->tabNavigateur->indexOf(onglet);
    QString titreReduit = web->title();
    titreReduit.truncate(30);

    qDebug() << "TAB où actualiser titre: " << m_indexOngletEnChargement;
    connect(web, SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
}

/*void MainWindow::getOngletTest()
{
    QWidget * onglet = webViewActive()->parentWidget();
    m_indexOngletEnChargement = ui->tabNavigateur->indexOf(onglet);
    QString titreReduit = webViewActive()->title();
    titreReduit.truncate(30);

    qDebug() << "TAB où actualiser titre: " << m_indexOngletEnChargement;
    connect(webViewActive(), SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
}*/

void MainWindow::getIndexOngletQuiCharge()
{
    qDebug() << "CHARGEMENT PAGE";
    connect(webViewActive(), SIGNAL(titleChanged(QString)), this, SLOT(actualiserTitreOnglet(QString)));
}
