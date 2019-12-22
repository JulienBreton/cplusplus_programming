#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>

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
    void demanderPseudo();
    void changerCouleur();
    void changerPolice();
    void chargerImage();

signals:
    void agrandissementMax();

private:
    bool m_boutonCacheTrouve;
    QPushButton * m_bouton;
    QPushButton * m_boutonAjouterOpacite;
    QPushButton * m_boutonReduireOpacite;
    QPushButton * m_boutonDialogue;
    QPushButton * m_boutonQuestion;
    QPushButton * m_boutonDemandePseudo;
    QPushButton * m_boutonCouleur;
    QPushButton * m_boutonPolice;
    QPushButton * m_boutonChargerImage;
    QLCDNumber * m_lcd;
    QSlider * m_slider;
    QSlider * m_sliderHauteur;
    QProgressBar * m_progressBar;
};

#endif // MAFENETRE_H
