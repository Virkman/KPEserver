//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_BESTILLING_H
#define KPESERVER_BESTILLING_H

#include <QtCore/QString>
#include <vector>
#include <QtCore/QJsonObject>

using namespace std;
class Bestilling {
public:
    Bestilling(int id_, QString status_,QString adresse_,
               QString navn_, QString tlf_, QString evt_,
               QString madkode_, QString time_, QString  devtime_,
               QString bm_, int pris_, QString driver_ );
    QString getId();
    QString getTid();
    QString getTlf();
    QString getAdresse();
    QString getTextPris();
    QJsonObject writeJson();
    void readJson(QString jsonstring);


private:
    int id;
    QString status;
    QString adresse;
    QString navn;
    QString tlfnummer;
    QString EVT;
    QString madkode;
    QString time;
    QString  devtime;
    QString betalingsmetode;
    int pris;
    QString driver;


};
#endif //KPESERVER_BESTILLING_H
