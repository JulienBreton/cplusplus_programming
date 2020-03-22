#ifndef FENCLIENT_H
#define FENCLIENT_H

#include <QWidget>
#include <QtNetwork>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class FenClient; }
QT_END_NAMESPACE

class FenClient : public QWidget
{
    Q_OBJECT

public:
    FenClient(QWidget *parent = nullptr);
    ~FenClient();

private slots:
    void on_boutonConnexion_clicked();
    void on_boutonEnvoyer_clicked();
    void on_message_returnPressed();
    void donneesRecues();
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);

private:
    Ui::FenClient *ui;
    QTcpSocket *socket; // Représente le serveur
    quint16 tailleMessage;

    void envoyerPseudo();
};
#endif // FENCLIENT_H
