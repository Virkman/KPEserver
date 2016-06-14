//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_SERVERTHREAD_H
#define KPESERVER_SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QtCore/QRunnable>
#include <QtNetwork/QHostAddress>
#include "Bestilling.h"

class ServerThread : public QThread
{
Q_OBJECT

public:
    ServerThread(int socketDescriptor, QObject *parent);

    void runIt(); //Q_DECL_OVERRIDE;
    QHostAddress getPeerAdresse();

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    int size;

    QTcpSocket tcpSocket;
    QByteArray buffer;
    QByteArray inbuffer;
    QTextStream out;
    QTextStream in;

    QString text;
    void getNewOrder();
    void sendLastOrder();
    void sendAll();
    void deleteOne();
    void deleteAll();
    void sendMoreOrder(int count);
    //void sendIncNumber();

    bool itsDisconnected = false;


private slots:
    void disconnectedFromClient();
};

#endif //KPESERVER_SERVERTHREAD_H
