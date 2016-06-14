//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_SERVERDIALOG_H
#define KPESERVER_SERVERDIALOG_H

#include <QWidget>
#include "Server.h"
#include "ServerStarter.h"

class QLabel;
class QPushButton;

class ServerDialog : public QWidget
{
Q_OBJECT

public:
    ServerDialog(QWidget *parent = 0);
    void sendNewOrder(qintptr server1, qintptr server2);

protected:
    ServerStarter starter;

private:
    QLabel *statusLabel;
    QPushButton *quitButton;



    QList<QHostAddress> ipAddressesListValid;
};

#endif //KPESERVER_SERVERDIALOG_H
