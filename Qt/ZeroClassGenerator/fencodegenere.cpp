#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString codeGenere, QWidget *parent = 0) : QDialog(parent)
{
    //Paramétrage de la fenêtre
    setWindowTitle("Zero Class Generator");
    setWindowIcon(QIcon("icone.png"));
    setFixedSize(400, 600);

    //Mise en place des éléments de la fenêtre
    m_TextEditCodeGenere = new QTextEdit;
    m_TextEditCodeGenere->setReadOnly(true);
    m_TextEditCodeGenere->setFontFamily("Courier");
    m_TextEditCodeGenere->setText(codeGenere);
    m_boutonFermer = new QPushButton;
    m_boutonFermer->setText("Fermer");
    m_layoutPrincipal = new QVBoxLayout;

    m_layoutPrincipal->addWidget(m_TextEditCodeGenere);
    m_layoutPrincipal->addWidget(m_boutonFermer);

    setLayout(m_layoutPrincipal);

    connect(m_boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
}
