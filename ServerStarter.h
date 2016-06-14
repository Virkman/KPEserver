//
// Created by Nicholas on 06-06-2016.
//

#ifndef KPESERVER_SERVERSTARTER_H
#define KPESERVER_SERVERSTARTER_H

#include <QtCore/QArgument>
#include <QtCore/QThread>
#include "Server.h"

class ServerStarter : public QThread
{
    Q_OBJECT
public:
    ServerStarter();
    void sendNewOrder(qintptr server1, qintptr server2);



protected:
    void run();

private:
    Server serverOne;
    Server serverTwo;
    bool serverOn;

};



#endif //KPESERVER_SERVERSTARTER_H
