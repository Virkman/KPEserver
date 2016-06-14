//
// Created by Nicholas on 01-06-2016.
//

#include "ServerThread.h"
#include "QMainApp.h"



#include <QtNetwork>
#include <QtCore/QJsonDocument>

ServerThread::ServerThread(int socketDescriptor, QObject *parent)
        : QThread(parent) , socketDescriptor(socketDescriptor)
{
    qDebug() << "Setting up" << socketDescriptor << endl;
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        qDebug() << "Setting up error!!" << socketDescriptor << endl;
        emit error(tcpSocket.error());
        return;
    }
    tcpSocket.open(QIODevice::ReadWrite |QIODevice::Text);
    connect(&tcpSocket, SIGNAL(disconnected()),this,SLOT(disconnectedFromClient()));
}


void ServerThread::runIt()
{
    qDebug() << "Starter thread!!" << endl;
        QTextStream out(buffer, QIODevice::WriteOnly);
        QTextStream in(inbuffer, QIODevice::ReadOnly);

        size = static_cast<QMainApp *>qApp->getDbSize() + 10000;
        buffer = QByteArray(QByteArray::number(size, 16));

        out << endl;

        //tcpSocket.waitForConnected();
        tcpSocket.write(buffer);
        tcpSocket.flush();
        buffer.clear();

        int attempt = 0;
        while (!inbuffer.contains('\n') && attempt < 1001) {
            tcpSocket.waitForReadyRead();
            inbuffer += tcpSocket.readAll();
            wait(10);
            attempt++;
            if(attempt == 1000){
                qDebug() << "Disconnecter" << endl;
                itsDisconnected = true;
                //tcpSocket.disconnect();
                tcpSocket.close();
                return;
            }
        }
        qDebug() << "Noget paa buffer" << endl;
        QString stringPacketId = QString(inbuffer.at(0));
        qDebug() << stringPacketId << endl;
        if (stringPacketId == "1") {
            inbuffer.clear();
            wait(1000);
        } else if (stringPacketId == "2") {
            qDebug() << "Sender klar" << endl;
            buffer.append("3");
            out << endl;
            tcpSocket.write(buffer);
            tcpSocket.flush();

            qDebug() << inbuffer << endl;
            inbuffer.clear();
            wait(20);
            getNewOrder();
            buffer.clear();
            inbuffer.clear();
            wait(1000);
        }else if (stringPacketId == "3") {
            qDebug() << "Sender sidste order" << endl;
            sendLastOrder();
            inbuffer.clear();
            wait(1000);
        } else if (stringPacketId == "4") {
            qDebug() << "Sender flere order" << endl;
            qDebug() << QString(inbuffer).toInt() << endl;
            sendMoreOrder(QString(inbuffer).toInt() - 4000);
            inbuffer.clear();
            wait(1000);
        }
    quit();
    this->deleteLater();
}

void ServerThread::sendMoreOrder(int count) {
    for (int i = 0 ; i < count ; i++){
        inbuffer.clear();
        Bestilling temp = static_cast<QMainApp *>qApp->getOrder(static_cast<QMainApp *>qApp->getDbSize() - count + i);
        QJsonObject tempJson =  temp.writeJson();
        QJsonDocument doc(tempJson);
        text = (doc.toJson(QJsonDocument::Compact));
        buffer.append(text.toUtf8());
        out << endl;
        tcpSocket.write(buffer);
        tcpSocket.flush();
        qDebug() << buffer << endl;
        tcpSocket.error();
        qDebug() << "All data sent!";
        buffer.clear();
        int attempt = 0;
        while (!inbuffer.contains('\n') && attempt < 1001) {
            tcpSocket.waitForReadyRead();
            inbuffer += tcpSocket.readAll();
            wait(10);
            attempt++;
            if(attempt == 1000){
                qDebug() << "Disconnecter" << endl;
                itsDisconnected = true;
                //tcpSocket.disconnect();
                tcpSocket.close();
                return;
            }
        }
    }
}

void ServerThread::disconnectedFromClient(){
    qDebug() << "Disconnected" << endl;
    //itsDisconnected = true;
}

void ServerThread::getNewOrder() {
    QTextStream out(buffer, QIODevice::WriteOnly);
    QTextStream in(&inbuffer, QIODevice::ReadOnly);
    int attempts = 0;
    while(!inbuffer.contains('\n') && attempts < 10001) {
        attempts++;
        tcpSocket.waitForReadyRead();
        inbuffer += tcpSocket.readAll();
        wait(1);
        if(attempts == 10000){
            qDebug() << "Disconnecter, client timeout" << endl;
            itsDisconnected = true;
            //tcpSocket.disconnect();
            tcpSocket.close();
            return;
        }
    }
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(in.readAll().toUtf8());
    qDebug() << in.readAll() << endl;
    qDebug() << QString(inbuffer) << endl;
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
            Bestilling *tempBestilling = new Bestilling(obj["id"].toInt(),
                                                        obj["status"].toString(),
                                                        obj["adresse"].toString(),
                                                        obj["navn"].toString(),
                                                        obj["tlf"].toString(),
                                                        obj["evt"].toString(),
                                                        obj["madkode"].toString(),
                                                        obj["time"].toString(),
                                                        obj["devtime"].toString(),
                                                        obj["bm"].toString(),
                                                        obj["pris"].toInt(),
                                                        obj["driver"].toString()
            );
            static_cast<QMainApp *>qApp->addNewOrder(tempBestilling);
            /*buffer.append("2");
            out << endl;
            tcpSocket.write(buffer);
            tcpSocket.flush();*/
            inbuffer.clear();
            qDebug() << "object recived" << endl;
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << in.readAll() << endl;
    }

    qDebug() << "Object Recived" << endl;
}

void ServerThread::sendLastOrder(){
    Bestilling temp = static_cast<QMainApp *>qApp->getLasOrder();
    QJsonObject tempJson =  temp.writeJson();
    QJsonDocument doc(tempJson);
    text = (doc.toJson(QJsonDocument::Compact));
    buffer.append(text.toUtf8());
    out << endl;
    tcpSocket.write(buffer);
    tcpSocket.flush();
    qDebug() << buffer << endl;
    tcpSocket.error();
    qDebug() << "All data sent!";
    buffer.clear();
}

QHostAddress ServerThread::getPeerAdresse(){
    return tcpSocket.peerAddress();
}