#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QPushButton>
#include <QtGui>
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QList>
#include <QTabWidget>
#include "fencodegenere.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();

private slots:
    void genererCode();
    void saisirHeaderGuard(QString nomClasse);
    void activerHeaderGuard(int state);

private:

    QString genererCPP();

    QVBoxLayout *m_vboxLayoutPrincipale;
    QTabWidget *m_onglets;
    QWidget * m_page1;

    //Definition de la classe
    QFormLayout *m_formLayoutDefClasse;
    QGroupBox *m_groupBoxDefClasse;
    QLineEdit *m_nomClasse;
    QLineEdit *m_classeMere;

    //Ajout classes et attributs
    QHBoxLayout * m_classesAttributsHBoxLayout;
    QGroupBox * m_groupBoxClassesAttributs;

    //Options
    QVBoxLayout *m_optionsVBoxLayout;
    QGroupBox *m_groupBoxOptions;
    QCheckBox *m_protegerHeader;
    QLineEdit *m_headerGuard;
    QCheckBox *m_genererConstructeur;
    QCheckBox *m_genererDestructeur;
    QCheckBox *m_ajouterLicenceGPL;
    QListWidget *m_classesAAjouter;
    QListWidget *m_attributsAAjouter;
    QCheckBox *m_genererAccesseur;

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
