#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>

class client
{
public:
    client();
    ~client();

    QTcpSocket* getClientTcpSocket();
    void setClientTcpSocket(QTcpSocket *socket);
    void setPseudo(QString pseudoRecu);
    QString getPseudo();

private:

    QTcpSocket *clientTcpSocket;
    QString pseudo;
};

#endif // CLIENT_H
