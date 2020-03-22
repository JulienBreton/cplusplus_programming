#include "client.h"

client::client()
{
    clientTcpSocket = new QTcpSocket();
    pseudo = "";
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
