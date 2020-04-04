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
    quint16 getTailleMessage();
    void setTailleMessage(quint16 taille);

private:

    QTcpSocket *clientTcpSocket;
    QString pseudo;
    quint16 tailleMessage;

};

#endif // CLIENT_H
