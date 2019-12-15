#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>

class MaFenetre : public QWidget
{
    Q_OBJECT

public:
    MaFenetre();
    MaFenetre(int w, int h);

public slots:
    void changerLargeur(int largeur);
    void changerHauteur(int largeur);
    void augmenterOpacite();
    void reduireOpacite();
    void ouvrirDialogue();
    void poserQuestion();

signals:
    void agrandissementMax();

private:
    QPushButton * m_bouton;
    QPushButton * m_boutonAjouterOpacite;
    QPushButton * m_boutonReduireOpacite;
    QPushButton * m_boutonDialogue;
    QPushButton * m_boutonQuestion;
    QLCDNumber * m_lcd;
    QSlider * m_slider;
    QSlider * m_sliderHauteur;
    QProgressBar * m_progressBar;
};

#endif // MAFENETRE_H
