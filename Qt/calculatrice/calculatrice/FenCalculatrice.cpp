#include "FenCalculatrice.h"
#include "ui_fencalculatrice.h"

FenCalculatrice::FenCalculatrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenCalculatrice)
{
    ui->setupUi(this);

    connect(ui->boutonEgal, SIGNAL(clicked()), this, SLOT(calculerOperation()));
}

FenCalculatrice::~FenCalculatrice()
{
    delete ui;
}

void FenCalculatrice::calculerOperation()
{
    double resultat = 0.0;

    if(ui->operation->currentText() == "+")
    {
        resultat = ui->nombre1->text().toInt() + ui->nombre2->text().toInt();

        ui->resultat->setText(QString::number(resultat));
    }

    else if(ui->operation->currentText() == "-")
    {
        resultat = ui->nombre1->text().toInt() - ui->nombre2->text().toInt();

        ui->resultat->setText(QString::number(resultat));
    }

    else if(ui->operation->currentText() == "*")
    {
        resultat = ui->nombre1->text().toInt() * ui->nombre2->text().toInt();

        ui->resultat->setText(QString::number(resultat));
    }

    else if(ui->operation->currentText() == "/")
    {
        resultat = ui->nombre1->text().toDouble() / ui->nombre2->text().toDouble();

        ui->resultat->setText(QString::number(resultat,'g',2));
    }
}
