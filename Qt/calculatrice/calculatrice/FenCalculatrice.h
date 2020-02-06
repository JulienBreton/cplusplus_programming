#ifndef FENCALCULATRICE_H
#define FENCALCULATRICE_H

#include <QWidget>

namespace Ui {
class FenCalculatrice;
}

class FenCalculatrice : public QWidget
{
    Q_OBJECT

public slots:
    void on_boutonEgal_clicked();


public:
    explicit FenCalculatrice(QWidget *parent = nullptr);
    ~FenCalculatrice();

private:
    Ui::FenCalculatrice *ui;
};

#endif // FENCALCULATRICE_H
