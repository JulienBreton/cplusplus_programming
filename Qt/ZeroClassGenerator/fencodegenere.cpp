#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString codeGenere, QString codeCPP, QString nomClasse, QWidget *parent) : QDialog(parent)
{
    setNomClasse(nomClasse);
    setCodeHeader(codeGenere);
    setCodeCPP(codeCPP);

    //Paramétrage de la fenêtre
    setWindowTitle(tr("Zero Class Generator"));
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
    m_boutonFermer->setText(tr("Fermer"));
    m_boutonEnregistrer = new QPushButton;
    m_boutonEnregistrer->setText(tr("Enregistrer les fichiers"));
    vboxOnglets->addWidget(m_boutonEnregistrer);
    vboxOnglets->addWidget(m_boutonFermer);

    this->setLayout(vboxOnglets);

    connect(m_boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_boutonEnregistrer, SIGNAL(clicked()), this, SLOT(enregisterFichiers()));
}

void FenCodeGenere::enregisterFichiers()
{
    QString classe = nomClasse();

    QString saveFile = QFileDialog::getSaveFileName(this, tr("Enregistrer .h et .cpp"),
                               "/home/julien/test_class_generator/robot",
                               tr(".h/.cpp (*.h *.cpp)"));

    //Enregistrement du .h
    QFile fileHeader(saveFile+".h");

    if (!fileHeader.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'écrire dans le fichier ")+nomClasse()+".h");

        return;
    }

    QTextStream streamCodeHeader(&fileHeader);
    streamCodeHeader << codeHeader();

    fileHeader.close();

    //Enregistrement du .cpp
    QFile fileCPP(saveFile+".cpp");

    if (!fileCPP.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'écrire dans le fichier ")+nomClasse()+".cpp");

        return;
    }

    QTextStream streamCodeCPP(&fileCPP);
    streamCodeCPP << codeCPP();

    fileCPP.close();
}

void FenCodeGenere::setNomClasse(QString nomClasse)
{
    m_nomClasse = nomClasse;
}

QString FenCodeGenere::nomClasse()
{
    return m_nomClasse;
}

void FenCodeGenere::setCodeHeader(QString codeHeader)
{
    m_codeHeader = codeHeader;
}

QString FenCodeGenere::codeHeader()
{
    return m_codeHeader;
}

void FenCodeGenere::setCodeCPP(QString codeCPP)
{
    m_codeCPP = codeCPP;
}

QString FenCodeGenere::codeCPP()
{
    return m_codeCPP;
}
