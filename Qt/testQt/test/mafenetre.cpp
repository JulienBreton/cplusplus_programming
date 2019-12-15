#include "mafenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(200, 300);

    setWindowOpacity(0.5);

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(50, 20);
    m_lcd->display(200);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(200, 600);

    m_sliderHauteur = new QSlider(this);
    m_sliderHauteur->setGeometry(180, 10, 20, 150);
    m_sliderHauteur->setRange(300, 600);

    m_progressBar = new QProgressBar(this);
    m_progressBar->setGeometry(10, 100, 150, 20);
    m_progressBar->setRange(200, 600);

    m_bouton = new QPushButton("Reset the progress bar", this);
    m_bouton->move(10, 140);

    m_boutonAjouterOpacite = new QPushButton("Add window opacity", this);
    m_boutonAjouterOpacite->move(10, 180);

    m_boutonReduireOpacite = new QPushButton("Reduce window opacity", this);
    m_boutonReduireOpacite->move(10, 220);

    m_boutonDialogue = new QPushButton("Bouton caché", this);
    m_boutonDialogue->move(450, 550);

    m_boutonQuestion = new QPushButton("Question?", this);
    m_boutonQuestion->move(50, 260);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_progressBar, SLOT(setValue(int)));
    QObject::connect(m_bouton, SIGNAL(clicked()), m_progressBar, SLOT(reset()));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(m_sliderHauteur, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)));
    QObject::connect(m_boutonAjouterOpacite, SIGNAL(clicked()), this, SLOT(augmenterOpacite()));
    QObject::connect(m_boutonReduireOpacite, SIGNAL(clicked()), this, SLOT(reduireOpacite()));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));
    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
    QObject::connect(m_boutonQuestion, SIGNAL(clicked()), this, SLOT(poserQuestion()));
}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedWidth(largeur);

    if(largeur == 600)
    {
        QMessageBox::warning(this, "Bye!", "Le programme va se fermer!");
        emit agrandissementMax();
    }
}

void MaFenetre::changerHauteur(int largeur)
{
    setFixedHeight(largeur);
}

void MaFenetre::augmenterOpacite()
{
    double opacite = windowOpacity();

    if(0.9 >= opacite)
    {
        opacite += 0.1;
        setWindowOpacity(opacite);
    }
}

void MaFenetre::reduireOpacite()
{
    double opacite = windowOpacity();

    if(0.1 <= opacite)
    {
        opacite -= 0.1;
        setWindowOpacity(opacite);
    }
}

void MaFenetre::ouvrirDialogue()
{
    QMessageBox::information(this, "Bravo!", "Tu as trouvé <strong>le bouton caché!</strong>");
}

void MaFenetre::poserQuestion()
{
    int reponse = QMessageBox::question(this, "Bouton caché", "As-tu trouvé le bouton caché?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes)
    {
        QMessageBox::information(this, "Oui", "Alors là bien joué!");
    }

    if(reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Non", "Mais dans quel coin est-il?");
    }
}
