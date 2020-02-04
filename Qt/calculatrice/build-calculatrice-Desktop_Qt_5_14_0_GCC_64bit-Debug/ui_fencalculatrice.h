/********************************************************************************
** Form generated from reading UI file 'fencalculatrice.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCALCULATRICE_H
#define UI_FENCALCULATRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenCalculatrice
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *nombre1;
    QComboBox *operation;
    QSpinBox *nombre2;
    QPushButton *boutonEgal;
    QLabel *resultat;

    void setupUi(QWidget *FenCalculatrice)
    {
        if (FenCalculatrice->objectName().isEmpty())
            FenCalculatrice->setObjectName(QString::fromUtf8("FenCalculatrice"));
        FenCalculatrice->resize(368, 49);
        horizontalLayout = new QHBoxLayout(FenCalculatrice);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nombre1 = new QSpinBox(FenCalculatrice);
        nombre1->setObjectName(QString::fromUtf8("nombre1"));

        horizontalLayout->addWidget(nombre1);

        operation = new QComboBox(FenCalculatrice);
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->setObjectName(QString::fromUtf8("operation"));
        operation->setMouseTracking(false);
        operation->setLayoutDirection(Qt::LeftToRight);
        operation->setAutoFillBackground(false);
        operation->setInsertPolicy(QComboBox::InsertAtBottom);

        horizontalLayout->addWidget(operation);

        nombre2 = new QSpinBox(FenCalculatrice);
        nombre2->setObjectName(QString::fromUtf8("nombre2"));

        horizontalLayout->addWidget(nombre2);

        boutonEgal = new QPushButton(FenCalculatrice);
        boutonEgal->setObjectName(QString::fromUtf8("boutonEgal"));
        boutonEgal->setAutoFillBackground(false);

        horizontalLayout->addWidget(boutonEgal);

        resultat = new QLabel(FenCalculatrice);
        resultat->setObjectName(QString::fromUtf8("resultat"));

        horizontalLayout->addWidget(resultat);


        retranslateUi(FenCalculatrice);

        QMetaObject::connectSlotsByName(FenCalculatrice);
    } // setupUi

    void retranslateUi(QWidget *FenCalculatrice)
    {
        FenCalculatrice->setWindowTitle(QCoreApplication::translate("FenCalculatrice", "Form", nullptr));
        operation->setItemText(0, QCoreApplication::translate("FenCalculatrice", "+", nullptr));
        operation->setItemText(1, QCoreApplication::translate("FenCalculatrice", "-", nullptr));
        operation->setItemText(2, QCoreApplication::translate("FenCalculatrice", "*", nullptr));
        operation->setItemText(3, QCoreApplication::translate("FenCalculatrice", "/", nullptr));

        operation->setCurrentText(QCoreApplication::translate("FenCalculatrice", "+", nullptr));
        boutonEgal->setText(QCoreApplication::translate("FenCalculatrice", "=", nullptr));
        resultat->setText(QCoreApplication::translate("FenCalculatrice", "R\303\251sultat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenCalculatrice: public Ui_FenCalculatrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCALCULATRICE_H
