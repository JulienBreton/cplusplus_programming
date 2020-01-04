#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QPushButton>
#include <QtGui>
#include <QInputDialog>
#include <QMessageBox>
#include "fencodegenere.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();

private slots:
    void genererCode();

private:

    QVBoxLayout *m_vboxLayoutPrincipale;

    //Definition de la classe
    QFormLayout *m_formLayoutDefClasse;
    QGroupBox *m_groupBoxDefClasse;
    QLineEdit *m_nomClasse;
    QLineEdit *m_classeMere;

    //Options
    QVBoxLayout *m_optionsVBoxLayout;
    QGroupBox *m_groupBoxOptions;
    QRadioButton *m_protegerHeader;
    QRadioButton *m_genererConstructeur;
    QRadioButton *m_genererDestructeur;

    //Commentaires
    QFormLayout *m_formLayoutCommentaires;
    QGroupBox *m_groupBoxCommentaires;
    QLineEdit *m_auteur;
    QDateTimeEdit *m_dateCreation;
    QTextEdit *m_roleClasse;

    //Les boutons
    QHBoxLayout *m_boutonsHBoxLayout;
    QPushButton *m_generer;
    QPushButton *m_quitter;

    FenCodeGenere *m_fenCodeGenere;
};

#endif // FENPRINCIPALE_H