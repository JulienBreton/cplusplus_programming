#ifndef FENSERVEUR_H
#define FENSERVEUR_H

#include <QWidget>
#include <QtNetwork>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QListView>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FenServeur; }
QT_END_NAMESPACE

class FenServeur : public QWidget
{
    Q_OBJECT

public:
    FenServeur(QWidget *parent = nullptr);
    ~FenServeur();
    void envoyerATous(const QString &message);
    void getClientsConnectes();

private slots:
    void nouvelleConnexion();
    void donneesRecues();
    void deconnexionClient();

private:
    QLabel *etatServeur;
    QPushButton *boutonQuitter;

    QTcpServer *serveur;
    QList<client *> clients;
    quint16 tailleMessage;
    unsigned int nbrClients;
    QStringListModel * modeleClients;
    QStringList listeClientsConnectes;

    Ui::FenServeur *ui;
};
#endif // FENSERVEUR_H
