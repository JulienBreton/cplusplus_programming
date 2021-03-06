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
    void envoyerAUnClient(const QString &message, QTcpSocket *socket);

private slots:
    void nouvelleConnexion();
    void donneesRecues();
    void deconnexionClient();

private:
    bool verifierUnicitePseudo(QString PseudoNouveauClient);
    client * determinerClientEnCours();

    QLabel *etatServeur;
    QPushButton *boutonQuitter;
    QTcpServer *serveur;
    QList<client *> clients;
    unsigned int nbrClients;
    QStringListModel * modeleClients;
    QStringList listeClientsConnectes;

    Ui::FenServeur *ui;
};
#endif // FENSERVEUR_H
