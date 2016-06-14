//
// Created by Nicholas on 01-06-2016.
//

#include <QtCore/QJsonDocument>
#include <c++/iostream>
#include "Bestilling.h"
    Bestilling::Bestilling(int id_, QString status_,QString adresse_,
                           QString navn_, QString tlf_, QString evt_,
                           QString madkode_, QString time_, QString  devtime_,
                           QString bm_, int pris_, QString driver_ ){
    id = id_;
    status = status_;
    adresse = adresse_;
    navn = navn_;
    tlfnummer = tlf_;
    EVT = evt_;
    madkode = madkode_;
    time = time_;
    devtime = devtime_;
    betalingsmetode = bm_;
    pris = pris_;
    driver = driver_;

    };

QString Bestilling::getId() {
    return QString::number(id);
}

QString Bestilling::getTid() {
    return time;
}

QString Bestilling::getTlf() {
    return tlfnummer;
}

QString Bestilling::getAdresse() {
    return adresse;
}

QString Bestilling::getTextPris() {
    return QString::number(pris);
}

QJsonObject Bestilling::writeJson() {
    QJsonObject json = QJsonObject();
    json["id"] = id;
    json["status"] = status;
    json["adresse"] = adresse;
    json["navn"] = navn;
    json["tlf"] = tlfnummer;
    json["evt"] = EVT;
    json["madkode"] = madkode;
    json["time"] = time;
    json["devtime"] = devtime;
    json["bm"] = betalingsmetode;
    json["pris"] = pris;
    json["driver"] = driver;
    return json;
}

void Bestilling::readJson(QString jsonstring) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonstring.toUtf8());
    QJsonObject json = doc.object();

    id = json["id"].toInt();
    status = QString(json["status"].toString());
}