#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*QDirModel *modele = new QDirModel;
    QTreeView *vue = new QTreeView;
    //QListView *vue = new QListView;
    //QTableView *vue = new QTableView;
    vue->setModel(modele);
    vue->setRootIndex(modele->index("/home/julien"));

    this->layout()->addWidget(vue);*/

    /*QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
    QStringListModel *modelePerso = new QStringListModel(listePays);

    QListView *vue2 = new QListView;
    vue2->setModel(modelePerso);

    this->layout()->addWidget(vue2);*/

    /*QStandardItemModel *modele = new QStandardItemModel(5, 3);
    modele->setItem(3, 1, new QStandardItem("Zéro !"));

    QTableView *vue = new QTableView;
    vue->setModel(modele);

    this->layout()->addWidget(vue);*/

    ui->centralwidget->setLayout(ui->vLayoutPrincipal);

    modele = new QStandardItemModel;

    QStandardItem *item = new QStandardItem("John Deuf");
    modele->appendRow(item);
    item->appendRow(new QStandardItem("17 ans"));

    QStandardItem *item2 = new QStandardItem("Naturo Uzumaki");
    item2->appendRow(new QStandardItem("32 ans"));

    QStandardItem *item3 = new QStandardItem("Boruto Uzumaki");
    item3->appendRow(new QStandardItem("12 ans"));

    QStandardItem *item4 = new QStandardItem("Uzumaki family");
    modele->appendRow(item4);
    item4->appendRow(item2);
    item4->appendRow(item3);

    vue = new QTreeView;
    vue->header()->hide();
    vue->setModel(modele);

    vue->setSelectionMode(QAbstractItemView::ExtendedSelection);

    bouton = new QPushButton("Afficher la sélection");

    ui->vLayoutPrincipal->addWidget(vue);
    ui->vLayoutPrincipal->addWidget(bouton);

    connect(bouton, SIGNAL(clicked()), this, SLOT(clicSelection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicSelection()
{
    QItemSelectionModel *selection = vue->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();
    QString elementsSelectionnes;

    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
        QVariant elementSelectionne = modele->data(listeSelections[i], Qt::DisplayRole);
        elementsSelectionnes += elementSelectionne.toString() + "<br />";
    }

    QMessageBox::information(this, "Eléments sélectionnés", elementsSelectionnes);
}

