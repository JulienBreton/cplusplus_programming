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
#include <QGridLayout>
#include <QLabel>
#include <QTabWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <textedit.h>

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
    void afficherComoEstaReponse();

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
    QGridLayout * m_layout;
    QLabel * m_labelComoEsta;
    QRadioButton * m_muyBien;
    QRadioButton * m_estoyBien;
    QRadioButton * m_malo;
    QRadioButton * m_cafe;
    QRadioButton * m_cerbeza;
    QRadioButton * m_zumo;
    QGroupBox * m_groupboxQueOnda;
    QGroupBox * m_groupboxQueTomas;
    QWidget * m_page1;
    QWidget * m_page2;
    QWidget * m_page3;
    QTabWidget * m_onglets;
    QLineEdit * m_titreNote;
    QLabel * m_labelTitreNote;
    QPlainTextEdit * m_note;
    TextEdit * mw;
    //TextEdit * mw2;
};

#endif // MAFENETRE_H
