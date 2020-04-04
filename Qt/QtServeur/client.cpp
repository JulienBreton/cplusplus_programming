#include "client.h"

client::client()
{
    clientTcpSocket = new QTcpSocket();
    pseudo = "";
    tailleMessage = 0;
}

client::~client()
{
    if(clientTcpSocket != nullptr)
    delete clientTcpSocket;
}

QTcpSocket* client::getClientTcpSocket()
{
    return clientTcpSocket;
}

void client::setClientTcpSocket(QTcpSocket *socket)
{
    clientTcpSocket = socket;
}

void client::setPseudo(QString pseudoRecu)
{
    pseudo = pseudoRecu;
}

QString client::getPseudo()
{
    return pseudo;
}

quint16 client::getTailleMessage()
{
    return tailleMessage;
}

void client::setTailleMessage(quint16 taille)
{
    tailleMessage = taille;
}
