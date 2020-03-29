#ifndef SMILEY_H
#define SMILEY_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class smiley;
}

class smiley : public QDialog
{
    Q_OBJECT

public:
    explicit smiley(QWidget *parent = nullptr);
    ~smiley();

    QString getSmileyChoisi();

private slots:
    void ajouterSmiley();

private:
    Ui::smiley *ui;
    QString smileyChoisi = "";

};

#endif // SMILEY_H
