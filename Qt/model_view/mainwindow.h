#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QVBoxLayout>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTreeView *vue;
    QStandardItemModel *modele;
    QPushButton *bouton;

private slots:
    void clicSelection();
};
#endif // MAINWINDOW_H
