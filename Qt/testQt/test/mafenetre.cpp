#include "mafenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
    m_boutonCacheTrouve = false;

    QVBoxLayout *vboxOnglets = new QVBoxLayout;

    m_onglets = new QTabWidget(this);

    m_page1 = new QWidget;
    m_page2 = new QWidget;

    setWindowOpacity(0.9);

    m_layout = new QGridLayout;

    setFixedWidth(640);

    m_lcd = new QLCDNumber();
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->display(this->width());
    m_layout->addWidget(m_lcd, 0, 0, 1, 2);

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(this->width(), 800);
    m_layout->addWidget(m_slider, 1, 0, 1, 2);

    //m_sliderHauteur = new QSlider();
    //m_sliderHauteur->setGeometry(180, 10, 20, 600);
    //m_sliderHauteur->setRange(this->height(), 600);
    //m_layout->addWidget(m_sliderHauteur, 0 , 3, 7, 1);

    m_progressBar = new QProgressBar();
    m_progressBar->setGeometry(10, 100, 150, 20);
    m_progressBar->setRange(this->width(), 800);
    m_layout->addWidget(m_progressBar, 2, 0, 1, 2);

    m_bouton = new QPushButton("Reset the progress bar");
    m_layout->addWidget(m_bouton, 3, 0, 1, 2);

    m_boutonAjouterOpacite = new QPushButton("Add window opacity");
    m_layout->addWidget(m_boutonAjouterOpacite, 4, 0);

    m_boutonReduireOpacite = new QPushButton("Reduce window opacity");
    m_layout->addWidget(m_boutonReduireOpacite, 4, 1);

    m_boutonQuestion = new QPushButton("Question?");
    m_layout->addWidget(m_boutonQuestion, 5, 0);

    m_boutonDemandePseudo = new QPushButton("Qui êtes-vous?");
    m_layout->addWidget(m_boutonDemandePseudo, 5, 1);

    m_boutonCouleur = new QPushButton("Changer la couleur");
    m_layout->addWidget(m_boutonCouleur, 6, 0);

    m_boutonPolice = new QPushButton("Changer la police");
    m_layout->addWidget(m_boutonPolice, 6, 1);

    m_boutonChargerImage = new QPushButton("Charger une image");
    m_layout->addWidget(m_boutonChargerImage, 7, 0);

    m_boutonDialogue = new QPushButton("Bouton caché");
    m_layout->addWidget(m_boutonDialogue, 7, 1);
    m_boutonDialogue->setVisible(false);

    m_page1->setLayout(m_layout);

    m_onglets->addTab(m_page1, "Home");

    QDialog * secondeFenetre = new QDialog(m_page1);
    QVBoxLayout *layout_image = new QVBoxLayout;
    QLabel *image = new QLabel(secondeFenetre);
    image->setPixmap(QPixmap("qt.png"));
    layout_image->addWidget(image);
    secondeFenetre->setLayout(layout_image);

    QVBoxLayout *vboxQueOnda = new QVBoxLayout;

    m_groupbox = new QGroupBox("Hola como estas?", m_page2);

        m_muyBien = new QRadioButton("Muy bien!");
        m_estoyBien = new QRadioButton("Estoy bien.");
        m_malo = new QRadioButton("Malo...");

        //m_muyBien->setChecked(true);

        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(m_muyBien);
        vbox->addWidget(m_estoyBien);
        vbox->addWidget(m_malo);

        m_groupbox->setLayout(vbox);
        vboxQueOnda->addWidget(m_groupbox);
        //m_groupbox->move(5, 5);

        m_labelComoEsta = new QLabel("");
        vboxQueOnda->addWidget(m_labelComoEsta);

     m_page2->setLayout(vboxQueOnda);

     m_onglets->addTab(m_page2, "Que onda?");

     vboxOnglets->addWidget(m_onglets);

     this->setLayout(vboxOnglets);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_progressBar, SLOT(setValue(int)));
    QObject::connect(m_bouton, SIGNAL(clicked()), m_progressBar, SLOT(reset()));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    //QObject::connect(m_sliderHauteur, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)));
    QObject::connect(m_boutonAjouterOpacite, SIGNAL(clicked()), this, SLOT(augmenterOpacite()));
    QObject::connect(m_boutonReduireOpacite, SIGNAL(clicked()), this, SLOT(reduireOpacite()));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));
    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
    QObject::connect(m_boutonQuestion, SIGNAL(clicked()), this, SLOT(poserQuestion()));
    QObject::connect(m_boutonDemandePseudo, SIGNAL(clicked()), this, SLOT(demanderPseudo()));
    QObject::connect(m_boutonCouleur, SIGNAL(clicked()), this, SLOT(changerCouleur()));
    QObject::connect(m_boutonPolice, SIGNAL(clicked()), this, SLOT(changerPolice()));
    QObject::connect(m_boutonChargerImage, SIGNAL(clicked()), secondeFenetre, SLOT(exec()));
    QObject::connect(m_muyBien, SIGNAL(clicked()), this, SLOT(afficherComoEstaReponse()));
    QObject::connect(m_estoyBien, SIGNAL(clicked()), this, SLOT(afficherComoEstaReponse()));
    QObject::connect(m_malo, SIGNAL(clicked()), this, SLOT(afficherComoEstaReponse()));
}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedWidth(largeur);

    if(largeur == 800)
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
    else
    {
        m_boutonDialogue->setVisible(true);
    }
}

void MaFenetre::ouvrirDialogue()
{
    m_boutonCacheTrouve = true;
    QMessageBox::information(this, "Bravo!", "Tu as trouvé <strong>le bouton caché!</strong>");
}

void MaFenetre::poserQuestion()
{
    int reponse = QMessageBox::question(this, "Bouton caché", "As-tu trouvé le bouton caché?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes && m_boutonCacheTrouve == true)
    {
        QMessageBox::information(this, "Oui", "Alors là bien joué!");
    }

    if(reponse == QMessageBox::Yes && m_boutonCacheTrouve == false)
    {
        QMessageBox::information(this, "Menteur", "Ce n'est pas vrai! Cherche encore!");
    }

    if(reponse == QMessageBox::No)
    {
        QMessageBox::information(this, "Non", "Mais dans quel coin est-il?");
    }
}

void MaFenetre::demanderPseudo()
{
    bool ok = false;
    QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !pseudo.isEmpty())
    {
        QMessageBox::information(this, "Pseudo", "Bonjour " + pseudo + ", ça va ?");
        m_boutonDemandePseudo->setText(pseudo);
        QString queOnda = "Que onda "+pseudo+"?";
        m_onglets->setTabText(1, queOnda);

    }
    else
    {
        QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom… snif.");
    }
}

void MaFenetre::changerCouleur()
{
    QColor couleur = QColorDialog::getColor(Qt::white, this);

    QPalette palette;
    palette.setColor(QPalette::Window, couleur);
    this->setPalette(palette);
}

void MaFenetre::changerPolice()
{
    bool ok = false;

    QFont police = QFontDialog::getFont(&ok, m_boutonDialogue->font(), this, "Choisissez une police");

    if (ok)
    {
        this->setFont(police);
    }
}

void MaFenetre::chargerImage()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
}

void MaFenetre::afficherComoEstaReponse()
{
    if(m_muyBien->isChecked())
    {
        m_labelComoEsta->setText("Que guay!");
    }

    if(m_estoyBien->isChecked())
    {
        m_labelComoEsta->setText("Super!");
    }

    if(m_malo->isChecked())
    {
        m_labelComoEsta->setText("Que pasa?");
    }
}
