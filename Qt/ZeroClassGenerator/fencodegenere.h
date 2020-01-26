#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere(QString codeGenere, QString codeCPP, QString nomClasse, QWidget *parent);
    QString nomClasse();
    QString codeHeader();
    QString codeCPP();

private slots:
    void enregisterFichiers();

private:
    QTabWidget *m_onglets;
    QWidget *m_page1;
    QWidget *m_page2;

    QTextEdit *m_TextEditCodeGenere;
    QPushButton *m_boutonFermer;
    QPushButton *m_boutonEnregistrer;
    QVBoxLayout *m_layoutPrincipal;

    QTextEdit *m_TextEditCodeCPP;
    QVBoxLayout *m_layoutCodeCPP;

    QString m_nomClasse;
    QString m_codeHeader;
    QString m_codeCPP;

    void setNomClasse(QString nomClasse);
    void setCodeHeader(QString codeHeader);
    void setCodeCPP(QString codeCPP);
};

#endif // FENCODEGENERE_H
