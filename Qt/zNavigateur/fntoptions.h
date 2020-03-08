#ifndef FNTOPTIONS_H
#define FNTOPTIONS_H

#include <QDialog>
#include <QDebug>
#include "mainwindow.h"

namespace Ui {
class fntOptions;
}

class fntOptions : public QDialog
{
    Q_OBJECT

public slots:
    void enregistrerOptions();

public:
    explicit fntOptions(QWidget *parent = nullptr);
    ~fntOptions();

private:
    Ui::fntOptions *ui;
     QString cheminFichierIni;
};

#endif // FNTOPTIONS_H
