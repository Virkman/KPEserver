//
// Created by Nicholas on 01-06-2016.
//

#include "ServerDialog.h"

#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>
#include <QtNetwork/QNetworkInterface>

#include "ServerDialog.h"
#include "Server.h"
#include "ServerStarter.h"

ServerDialog::ServerDialog(QWidget *parent)
        : QWidget(parent)
{
    //Bestilling temp = Bestilling(1, "klar", "Vej 2", "Navn", "86440202", "", "00", "22:10", "22:30", "dk", 200, "NV" );
    //server.setup(temp);

    starter.start();
    statusLabel = new QLabel;
    statusLabel->setWordWrap(true);
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    int port = 25727;

    /*if (!server.listen(QHostAddress::Any, port)) {
        QMessageBox::critical(this, tr("Threaded Fortune Server"),
                              tr("Unable to start the server: %1.")
                                      .arg(server.errorString()));
        close();
        return;
    }*/
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2 og port: %3\n\n"
                                    "Connect the clients.")
                                 .arg("192.168.0.26").arg("25727").arg("25737"));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    for (int i = 0 ; i < ipAddressesList.size() ; i++) {
        /*if(ipAddressesList.at(i).toString().startsWith("192.168.0.")){
            ipAddressesListValid.append(ipAddressesList.at(i));
        }*/
        ipAddressesListValid.append(ipAddressesList.at(i));
    }

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);


    //orderCountLabel->setText("Count: 0");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Kylling og Pizza Ekspressen App"));
}



void ServerDialog::sendNewOrder(qintptr server1, qintptr server2) {
    starter.sendNewOrder(server1,server2);
}




