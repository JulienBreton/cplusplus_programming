#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString codeGenere, QString codeCPP, QString nomClasse, QWidget *parent = 0) : QDialog(parent)
{
    //Paramétrage de la fenêtre
    setWindowTitle("Zero Class Generator");
    setWindowIcon(QIcon("icone.png"));
    setFixedSize(400, 600);

    QVBoxLayout *vboxOnglets = new QVBoxLayout;
    m_onglets = new QTabWidget(this);
    m_page1 = new QWidget;
    m_page2 = new QWidget;

    //Onglet header
    m_TextEditCodeGenere = new QTextEdit;
    m_TextEditCodeGenere->setReadOnly(true);
    m_TextEditCodeGenere->setFontFamily("Courier");
    m_TextEditCodeGenere->setText(codeGenere);
    m_layoutPrincipal = new QVBoxLayout;
    m_layoutPrincipal->addWidget(m_TextEditCodeGenere);
    m_page1->setLayout(m_layoutPrincipal);
    m_onglets->addTab(m_page1, nomClasse+".h");

    //Onglet CPP
    m_layoutCodeCPP = new QVBoxLayout();
    m_TextEditCodeCPP = new QTextEdit();
    m_TextEditCodeCPP->setReadOnly(true);
    m_TextEditCodeCPP->setFontFamily("Courier");
    m_TextEditCodeCPP->setText(codeCPP);
    m_layoutCodeCPP->addWidget(m_TextEditCodeCPP);
    m_page2->setLayout(m_layoutCodeCPP);
    m_onglets->addTab(m_page2, nomClasse+".cpp");

    vboxOnglets->addWidget(m_onglets);
    m_boutonFermer = new QPushButton;
    m_boutonFermer->setText("Fermer");
    vboxOnglets->addWidget(m_boutonFermer);

    this->setLayout(vboxOnglets);

    connect(m_boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
}
