/********************************************************************************
** Form generated from reading UI file 'fenprincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENPRINCIPALE_H
#define UI_FENPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenPrincipale
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenPrincipale)
    {
        if (FenPrincipale->objectName().isEmpty())
            FenPrincipale->setObjectName(QString::fromUtf8("FenPrincipale"));
        FenPrincipale->resize(800, 600);
        centralwidget = new QWidget(FenPrincipale);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FenPrincipale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FenPrincipale);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        FenPrincipale->setMenuBar(menubar);
        statusbar = new QStatusBar(FenPrincipale);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FenPrincipale->setStatusBar(statusbar);

        retranslateUi(FenPrincipale);

        QMetaObject::connectSlotsByName(FenPrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *FenPrincipale)
    {
        FenPrincipale->setWindowTitle(QCoreApplication::translate("FenPrincipale", "FenPrincipale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenPrincipale: public Ui_FenPrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENPRINCIPALE_H
