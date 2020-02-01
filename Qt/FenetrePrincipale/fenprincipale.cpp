#include "fenprincipale.h"
#include "ui_fenprincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FenPrincipale)
{
    ui->setupUi(this);

    //QWidget *zoneCentrale = new QWidget;
    QMdiArea *zoneCentrale = new QMdiArea;

    /*QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre nom", nom);
    layout->addRow("Votre prénom", prenom);
    layout->addRow("Votre âge", age);*/

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon("quitter.png"));

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QAction *actionGras = new QAction("&Gras", this);
    actionGras->setCheckable(true);
    menuEdition->addAction(actionGras);
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    QTextEdit *zoneTexte1 = new QTextEdit;
    QTextEdit *zoneTexte2 = new QTextEdit;

    QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(zoneTexte1);
    QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionQuitter);
    toolBarFichier->addSeparator();
    QFontComboBox *choixPolice = new QFontComboBox;
    toolBarFichier->addWidget(choixPolice);

    //zoneCentrale->setLayout(layout);

    setCentralWidget(zoneCentrale);

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(choixPolice, SIGNAL(currentFontChanged(QFont)), zoneTexte1, SLOT(setCurrentFont(QFont)));
    connect(choixPolice, SIGNAL(currentFontChanged(QFont)), zoneTexte2, SLOT(setCurrentFont(QFont)));
}

FenPrincipale::~FenPrincipale()
{
    delete ui;
}

