/********************************************************************************
** Form generated from reading UI file 'fntoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNTOPTIONS_H
#define UI_FNTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fntOptions
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayoutOptions;
    QFormLayout *formLayout;
    QLineEdit *urlPageAccueil;
    QLabel *labelPageAccueil;
    QLabel *titreFntOptions;
    QLabel *labelTaillePolice;
    QSpinBox *taillePolice;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *fntOptions)
    {
        if (fntOptions->objectName().isEmpty())
            fntOptions->setObjectName(QString::fromUtf8("fntOptions"));
        fntOptions->resize(767, 250);
        verticalLayoutWidget = new QWidget(fntOptions);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 741, 231));
        vLayoutOptions = new QVBoxLayout(verticalLayoutWidget);
        vLayoutOptions->setObjectName(QString::fromUtf8("vLayoutOptions"));
        vLayoutOptions->setContentsMargins(6, 0, 6, 6);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(6, 6, 6, 6);
        urlPageAccueil = new QLineEdit(verticalLayoutWidget);
        urlPageAccueil->setObjectName(QString::fromUtf8("urlPageAccueil"));

        formLayout->setWidget(1, QFormLayout::FieldRole, urlPageAccueil);

        labelPageAccueil = new QLabel(verticalLayoutWidget);
        labelPageAccueil->setObjectName(QString::fromUtf8("labelPageAccueil"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPageAccueil);

        titreFntOptions = new QLabel(verticalLayoutWidget);
        titreFntOptions->setObjectName(QString::fromUtf8("titreFntOptions"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        titreFntOptions->setFont(font);
        titreFntOptions->setAlignment(Qt::AlignCenter);
        titreFntOptions->setMargin(10);

        formLayout->setWidget(0, QFormLayout::SpanningRole, titreFntOptions);

        labelTaillePolice = new QLabel(verticalLayoutWidget);
        labelTaillePolice->setObjectName(QString::fromUtf8("labelTaillePolice"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTaillePolice);

        taillePolice = new QSpinBox(verticalLayoutWidget);
        taillePolice->setObjectName(QString::fromUtf8("taillePolice"));
        taillePolice->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, taillePolice);


        vLayoutOptions->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vLayoutOptions->addWidget(buttonBox);


        retranslateUi(fntOptions);
        QObject::connect(buttonBox, SIGNAL(accepted()), fntOptions, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fntOptions, SLOT(reject()));

        QMetaObject::connectSlotsByName(fntOptions);
    } // setupUi

    void retranslateUi(QDialog *fntOptions)
    {
        fntOptions->setWindowTitle(QCoreApplication::translate("fntOptions", "Dialog", nullptr));
        labelPageAccueil->setText(QCoreApplication::translate("fntOptions", "Page d'accueil :", nullptr));
        titreFntOptions->setText(QCoreApplication::translate("fntOptions", "R\303\251glage des options", nullptr));
        labelTaillePolice->setText(QCoreApplication::translate("fntOptions", "Taille de la police par d\303\251faut", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fntOptions: public Ui_fntOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNTOPTIONS_H
