#include "fntoptions.h"
#include "ui_fntoptions.h"

fntOptions::fntOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fntOptions)
{
    ui->setupUi(this);

    //Attache le layout à la fenêtre pour que les éléments soient redimentionnés lorsqu'on redimentionne la fenêtre.
    this->setLayout(ui->vLayoutOptions);

    //On récupère le chemin du fichier .ini
    MainWindow * fntPrincipale = qobject_cast<MainWindow *>(parent);
    cheminFichierIni = fntPrincipale->getChemiFichierIni();
    QSettings settings(cheminFichierIni, QSettings::IniFormat);

    //On set la valeur de la page d'accueil.
    QUrl urlAccueil(settings.value("urlAccueil","https://www.google.fr").toString());
    ui->urlPageAccueil->setText(urlAccueil.toString());

    QString taillePolice(settings.value("taillePolice","12").toString());

    if(taillePolice.toInt() <= 0)
    {
        ui->taillePolice->setValue(12);
    }
    else
    {
        ui->taillePolice->setValue(taillePolice.toInt());
    }

    connect(this, SIGNAL(accepted()), this, SLOT(enregistrerOptions()));
}

fntOptions::~fntOptions()
{
    delete ui;
}

void fntOptions::enregistrerOptions()
{
    QSettings settings(cheminFichierIni, QSettings::IniFormat);
    settings.setValue("urlAccueil", ui->urlPageAccueil->text());
    settings.setValue("taillePolice", ui->taillePolice->text());
}
