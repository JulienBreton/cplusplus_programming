#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QUrl>
#include <QProgressBar>
#include <QMessageBox>
#include <QTabWidget>
#include <QWebEngineHistoryItem>
#include <QInputDialog>
#include <QSettings>
#include <QWebEngineSettings>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "fntoptions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:

    void ouvrirTab();
    void fermerTab();
    void allerPagePrecedente();
    void allerPageSuivante();
    void rechargerPage();
    void stopChargement();
    void allerAccueil();
    void allerURL();
    void actualiserTitreOnglet(QString titrePage);
    void afficherAProposzNavigo();
    void afficherAProposQt();
    void actualiserBarreURL(const QUrl & url);
    void actualiserApresChangementOnglet(int);
    void ajouterURLActionHisto();
    void chercherDansPageWeb();
    void editerOptions();
    void ajouterAuxFavoris();
    void allerUrlFavoris();
    void supprimerDesFavoris();
    void supprimerHistorique();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getChemiFichierIni();

private:
    QWebEngineView * webViewActive();
    void setTitreFenetreNavigateur();
    void obtenirHistorique();
    void updateTaillePolice(QWebEngineView * pageActive);
    bool connecterDatabase();
    void populateFavoris();
    QString getURLFavoris(QString libelleFavoris);

    QString m_sSettingsFile;
    QSettings * settings;
    QTabWidget * m_tabOnglets;
    QList<QWebEngineHistoryItem> m_historique;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
