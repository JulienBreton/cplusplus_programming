#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere(QString codeGenere, QString codeCPP, QString nomClasse, QWidget *parent);

private:
    QTabWidget *m_onglets;
    QWidget *m_page1;
    QWidget *m_page2;

    QTextEdit *m_TextEditCodeGenere;
    QPushButton *m_boutonFermer;
    QVBoxLayout *m_layoutPrincipal;

    QTextEdit *m_TextEditCodeCPP;
    QVBoxLayout *m_layoutCodeCPP;
};

#endif // FENCODEGENERE_H
