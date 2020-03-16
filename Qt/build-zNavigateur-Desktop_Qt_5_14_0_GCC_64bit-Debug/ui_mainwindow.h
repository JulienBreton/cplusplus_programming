/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOuvrirOnglet;
    QAction *actionFermerOnglet;
    QAction *actionQuitter;
    QAction *actionPageprecedente;
    QAction *actionPageSuivante;
    QAction *actionActualiser;
    QAction *actionArreter;
    QAction *actionAccueil;
    QAction *actionAllerURL;
    QAction *actionAProposDezNavigo;
    QAction *actionAProposDeQt;
    QAction *actionViderHistorique;
    QAction *actionChercher;
    QAction *actionOptions;
    QAction *actionAjouter_aux_favoris;
    QAction *actionSupprimerFavoris;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayoutFenetre;
    QHBoxLayout *hLayoutBarreOutils;
    QPushButton *btPrecedent;
    QPushButton *btSuivant;
    QPushButton *btActualiser;
    QPushButton *btStopChargement;
    QPushButton *btHome;
    QLineEdit *barreURL;
    QPushButton *btAllerURL;
    QHBoxLayout *hLayoutTab;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuNavigation;
    QMenu *menuAide;
    QMenu *menuHistorique;
    QMenu *menuEditer;
    QMenu *menuFavoris;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1135, 600);
        actionOuvrirOnglet = new QAction(MainWindow);
        actionOuvrirOnglet->setObjectName(QString::fromUtf8("actionOuvrirOnglet"));
        actionFermerOnglet = new QAction(MainWindow);
        actionFermerOnglet->setObjectName(QString::fromUtf8("actionFermerOnglet"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionPageprecedente = new QAction(MainWindow);
        actionPageprecedente->setObjectName(QString::fromUtf8("actionPageprecedente"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icones/prec.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPageprecedente->setIcon(icon);
        actionPageSuivante = new QAction(MainWindow);
        actionPageSuivante->setObjectName(QString::fromUtf8("actionPageSuivante"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icones/suiv.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPageSuivante->setIcon(icon1);
        actionActualiser = new QAction(MainWindow);
        actionActualiser->setObjectName(QString::fromUtf8("actionActualiser"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icones/actu.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActualiser->setIcon(icon2);
        actionArreter = new QAction(MainWindow);
        actionArreter->setObjectName(QString::fromUtf8("actionArreter"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icones/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArreter->setIcon(icon3);
        actionAccueil = new QAction(MainWindow);
        actionAccueil->setObjectName(QString::fromUtf8("actionAccueil"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icones/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAccueil->setIcon(icon4);
        actionAllerURL = new QAction(MainWindow);
        actionAllerURL->setObjectName(QString::fromUtf8("actionAllerURL"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icones/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAllerURL->setIcon(icon5);
        actionAProposDezNavigo = new QAction(MainWindow);
        actionAProposDezNavigo->setObjectName(QString::fromUtf8("actionAProposDezNavigo"));
        actionAProposDeQt = new QAction(MainWindow);
        actionAProposDeQt->setObjectName(QString::fromUtf8("actionAProposDeQt"));
        actionViderHistorique = new QAction(MainWindow);
        actionViderHistorique->setObjectName(QString::fromUtf8("actionViderHistorique"));
        actionChercher = new QAction(MainWindow);
        actionChercher->setObjectName(QString::fromUtf8("actionChercher"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionAjouter_aux_favoris = new QAction(MainWindow);
        actionAjouter_aux_favoris->setObjectName(QString::fromUtf8("actionAjouter_aux_favoris"));
        actionSupprimerFavoris = new QAction(MainWindow);
        actionSupprimerFavoris->setObjectName(QString::fromUtf8("actionSupprimerFavoris"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 1061, 501));
        vLayoutFenetre = new QVBoxLayout(verticalLayoutWidget);
        vLayoutFenetre->setObjectName(QString::fromUtf8("vLayoutFenetre"));
        vLayoutFenetre->setContentsMargins(3, 0, 3, 0);
        hLayoutBarreOutils = new QHBoxLayout();
        hLayoutBarreOutils->setObjectName(QString::fromUtf8("hLayoutBarreOutils"));
        hLayoutBarreOutils->setSizeConstraint(QLayout::SetDefaultConstraint);
        hLayoutBarreOutils->setContentsMargins(0, 3, 0, 3);
        btPrecedent = new QPushButton(verticalLayoutWidget);
        btPrecedent->setObjectName(QString::fromUtf8("btPrecedent"));
        btPrecedent->setMinimumSize(QSize(24, 24));
        btPrecedent->setMaximumSize(QSize(24, 24));
        btPrecedent->setAcceptDrops(false);
        btPrecedent->setToolTipDuration(-1);
        btPrecedent->setIcon(icon);
        btPrecedent->setIconSize(QSize(24, 24));
        btPrecedent->setAutoRepeatDelay(0);
        btPrecedent->setAutoRepeatInterval(0);
        btPrecedent->setAutoDefault(false);
        btPrecedent->setFlat(true);

        hLayoutBarreOutils->addWidget(btPrecedent);

        btSuivant = new QPushButton(verticalLayoutWidget);
        btSuivant->setObjectName(QString::fromUtf8("btSuivant"));
        btSuivant->setMinimumSize(QSize(24, 24));
        btSuivant->setMaximumSize(QSize(24, 24));
        btSuivant->setIcon(icon1);
        btSuivant->setIconSize(QSize(24, 24));
        btSuivant->setFlat(true);

        hLayoutBarreOutils->addWidget(btSuivant);

        btActualiser = new QPushButton(verticalLayoutWidget);
        btActualiser->setObjectName(QString::fromUtf8("btActualiser"));
        btActualiser->setMinimumSize(QSize(24, 24));
        btActualiser->setMaximumSize(QSize(24, 24));
        btActualiser->setIcon(icon2);
        btActualiser->setIconSize(QSize(24, 24));
        btActualiser->setFlat(true);

        hLayoutBarreOutils->addWidget(btActualiser);

        btStopChargement = new QPushButton(verticalLayoutWidget);
        btStopChargement->setObjectName(QString::fromUtf8("btStopChargement"));
        btStopChargement->setMinimumSize(QSize(24, 24));
        btStopChargement->setMaximumSize(QSize(24, 24));
        btStopChargement->setIcon(icon3);
        btStopChargement->setIconSize(QSize(24, 24));
        btStopChargement->setFlat(true);

        hLayoutBarreOutils->addWidget(btStopChargement);

        btHome = new QPushButton(verticalLayoutWidget);
        btHome->setObjectName(QString::fromUtf8("btHome"));
        btHome->setMinimumSize(QSize(24, 24));
        btHome->setMaximumSize(QSize(24, 24));
        btHome->setIcon(icon4);
        btHome->setIconSize(QSize(24, 24));
        btHome->setFlat(true);

        hLayoutBarreOutils->addWidget(btHome);

        barreURL = new QLineEdit(verticalLayoutWidget);
        barreURL->setObjectName(QString::fromUtf8("barreURL"));
        barreURL->setMinimumSize(QSize(500, 0));
        barreURL->setMaximumSize(QSize(16777215, 20));
        barreURL->setLayoutDirection(Qt::RightToLeft);
        barreURL->setFrame(true);

        hLayoutBarreOutils->addWidget(barreURL);

        btAllerURL = new QPushButton(verticalLayoutWidget);
        btAllerURL->setObjectName(QString::fromUtf8("btAllerURL"));
        btAllerURL->setMinimumSize(QSize(24, 24));
        btAllerURL->setMaximumSize(QSize(24, 24));
        btAllerURL->setIcon(icon5);
        btAllerURL->setIconSize(QSize(24, 24));
        btAllerURL->setFlat(true);

        hLayoutBarreOutils->addWidget(btAllerURL);


        vLayoutFenetre->addLayout(hLayoutBarreOutils);

        hLayoutTab = new QHBoxLayout();
        hLayoutTab->setSpacing(0);
        hLayoutTab->setObjectName(QString::fromUtf8("hLayoutTab"));

        vLayoutFenetre->addLayout(hLayoutTab);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1135, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuNavigation = new QMenu(menubar);
        menuNavigation->setObjectName(QString::fromUtf8("menuNavigation"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuHistorique = new QMenu(menubar);
        menuHistorique->setObjectName(QString::fromUtf8("menuHistorique"));
        menuHistorique->setTearOffEnabled(true);
        menuEditer = new QMenu(menubar);
        menuEditer->setObjectName(QString::fromUtf8("menuEditer"));
        menuFavoris = new QMenu(menubar);
        menuFavoris->setObjectName(QString::fromUtf8("menuFavoris"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuEditer->menuAction());
        menubar->addAction(menuNavigation->menuAction());
        menubar->addAction(menuHistorique->menuAction());
        menubar->addAction(menuFavoris->menuAction());
        menubar->addAction(menuAide->menuAction());
        menu->addAction(actionOuvrirOnglet);
        menu->addAction(actionFermerOnglet);
        menu->addSeparator();
        menu->addAction(actionQuitter);
        menuNavigation->addAction(actionPageprecedente);
        menuNavigation->addAction(actionPageSuivante);
        menuNavigation->addAction(actionActualiser);
        menuNavigation->addAction(actionArreter);
        menuNavigation->addAction(actionAccueil);
        menuNavigation->addAction(actionAllerURL);
        menuAide->addAction(actionAProposDezNavigo);
        menuAide->addAction(actionAProposDeQt);
        menuHistorique->addAction(actionViderHistorique);
        menuHistorique->addSeparator();
        menuEditer->addAction(actionChercher);
        menuEditer->addAction(actionOptions);
        menuFavoris->addAction(actionAjouter_aux_favoris);
        menuFavoris->addAction(actionSupprimerFavoris);
        menuFavoris->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        btPrecedent->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOuvrirOnglet->setText(QCoreApplication::translate("MainWindow", "Nouvel onglet", nullptr));
        actionFermerOnglet->setText(QCoreApplication::translate("MainWindow", "Fermer l'onglet", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionPageprecedente->setText(QCoreApplication::translate("MainWindow", "Page pr\303\251c\303\251dente", nullptr));
        actionPageSuivante->setText(QCoreApplication::translate("MainWindow", "Page suivante", nullptr));
        actionActualiser->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        actionArreter->setText(QCoreApplication::translate("MainWindow", "Arr\303\252ter", nullptr));
        actionAccueil->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        actionAllerURL->setText(QCoreApplication::translate("MainWindow", "Aller URL", nullptr));
        actionAProposDezNavigo->setText(QCoreApplication::translate("MainWindow", "A propos de zNavigateur", nullptr));
        actionAProposDeQt->setText(QCoreApplication::translate("MainWindow", "A propos de Qt", nullptr));
        actionViderHistorique->setText(QCoreApplication::translate("MainWindow", "Vider l'historique", nullptr));
        actionChercher->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
#if QT_CONFIG(shortcut)
        actionChercher->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        actionAjouter_aux_favoris->setText(QCoreApplication::translate("MainWindow", "Ajouter aux favoris", nullptr));
        actionSupprimerFavoris->setText(QCoreApplication::translate("MainWindow", "Supprimer des favoris", nullptr));
#if QT_CONFIG(tooltip)
        btPrecedent->setToolTip(QCoreApplication::translate("MainWindow", "Page pr\303\251c\303\251dente", "Page pr\303\251c\303\251dente"));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btPrecedent->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btPrecedent->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btPrecedent->setText(QString());
        btSuivant->setText(QString());
        btActualiser->setText(QString());
        btStopChargement->setText(QString());
        btHome->setText(QString());
        btAllerURL->setText(QString());
#if QT_CONFIG(shortcut)
        btAllerURL->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuNavigation->setTitle(QCoreApplication::translate("MainWindow", "Navigation", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        menuHistorique->setTitle(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        menuEditer->setTitle(QCoreApplication::translate("MainWindow", "Editer", nullptr));
        menuFavoris->setTitle(QCoreApplication::translate("MainWindow", "Favoris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
