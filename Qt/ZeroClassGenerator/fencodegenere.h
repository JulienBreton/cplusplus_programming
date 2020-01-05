#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere(QString codeGenere, QWidget *parent);

private:
    QTextEdit *m_TextEditCodeGenere;
    QPushButton *m_boutonFermer;
    QVBoxLayout *m_layoutPrincipal;
};

#endif // FENCODEGENERE_H
