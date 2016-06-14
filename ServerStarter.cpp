//
// Created by Nicholas on 06-06-2016.
//

#include <c++/iostream>
#include "ServerStarter.h"

ServerStarter::ServerStarter() : QThread() {
    int port = 25727;
    int port2 = 25737;

    serverOne.setServerNo(1);
    serverTwo.setServerNo(2);
    serverOne.listen(QHostAddress::Any,port);
    serverTwo.listen(QHostAddress::Any,port2);
    serverOn = true;
}

void ServerStarter::run() {
    while(serverOn){
        if(serverOne.hasPendingConnections()){
            qDebug() << "Server 1 has pending!!" << endl;
        }
        sleep(1);
    }

}

void ServerStarter::sendNewOrder(qintptr server1, qintptr server2) {
    /*if(server1 != NULL) {
        serverOne.sendLast(server1);
    } else {
        cout << "Client 1 hasent connected!" << endl;
    }
    if(server2 != NULL) {
        serverTwo.sendLast(server2);
    } else {
        cout << "Client 2 hasent connected!" << endl;
    }*/
}
