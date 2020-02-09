#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QUrl>
#include <QProgressBar>

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
    void changementOnglet(int index);
    void actualiserTitreOnglet(bool chargementTermine);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWebEngineView * webViewActive();

    Ui::MainWindow *ui;
    QProgressBar * m_loadingBar;
    QWebEngineView * m_webCourrant;

};
#endif // MAINWINDOW_H
