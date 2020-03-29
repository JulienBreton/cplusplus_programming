#include "smiley.h"
#include "ui_smiley.h"

smiley::smiley(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::smiley)
{
    ui->setupUi(this);

    smileyChoisi = "";
    connect(ui->icon1, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
    connect(ui->icon2, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
    connect(ui->icon3, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
    connect(ui->icon4, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
    connect(ui->icon5, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
    connect(ui->icon6, SIGNAL(clicked()), this, SLOT(ajouterSmiley()));
}

smiley::~smiley()
{
    delete ui;
}

void smiley::ajouterSmiley()
{
    QPushButton *btSmileyChoisi = qobject_cast<QPushButton *>(sender());

    QString cheminImage = ":/icons/smiley/icons/"+btSmileyChoisi->objectName()+".png";


    smileyChoisi = "<img src = \""+ cheminImage +"\" alt = \"\"/>";

    this->accept();
}

QString smiley::getSmileyChoisi()
{
    return smileyChoisi;
}
