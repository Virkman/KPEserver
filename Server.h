//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_SERVER_H
#define KPESERVER_SERVER_H


#include <QtCore/QArgument>
#include <QtNetwork/QTcpServer>
#include <QtCore/QThread>
#include "Bestilling.h"
#include "ServerThread.h"


class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void setup(qintptr socketDescriptor);
    void sendLast(qintptr socketDesc);
    void setServerNo(int serverN);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
    //void nextPendingConnection() Q_DECL_OVERRIDE;

private:
    //QStringList fortunes;
    QString strtoSend;
    qintptr newS;
    int serverNumber;
};

#endif //KPESERVER_SERVER_H
