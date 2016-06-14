//
// Created by Nicholas on 01-06-2016.
//

#include "Server.h"
#include "ServerThread.h"
#include "QMainApp.h"

#include <stdlib.h>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <c++/iostream>

Server::Server(QObject *parent)
        : QTcpServer(parent)
{
    strtoSend = "";
}

void Server::setServerNo(int serverNo) {
    serverNumber = serverNo;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    static_cast<QMainApp *>qApp->setSocket(serverNumber,socketDescriptor);
    ServerThread *thread = new ServerThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
    /*QHostAddress *tempIp = new QHostAddress(thread->getPeerAdresse());
    bool d = true;
    for(int i = 0 ; i < ips.size() ; i++){
        qDebug() << "Skifter port!!" << endl;
        if (ips.at(i)->toString() == tempIp->toString()){
            sockets.replace(i, socketDescriptor);
            d = false;
        }
    }
    if(d) {
        qDebug() << "Opretter nu port og ip" << endl;
        sockets.append(socketDescriptor);
        ips.append(tempIp);
    }*/

    cout << "tester socket: " << socketDescriptor << endl;
    thread->runIt();
}

void Server::sendLast(qintptr socketDesc) {
        qDebug() << "Sender ud på socket: " << socketDesc << endl;
        ServerThread *thread = new ServerThread(socketDesc, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
        thread->runIt();
}



/*void Server::nextPendingConnection() {
    cout << "tester socket: " << socketDescriptor << endl;
    /*serverThreads.append(new ServerThread(socketDescriptor, this));
    ServerThread *thread = serverThreads.last();
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    thread->runIt();
}*/