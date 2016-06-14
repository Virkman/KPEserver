//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_USER_H
#define KPESERVER_USER_H

#include <QtCore/QString>
#include <vector>

using namespace std;
class User {
public:
    User(QString userName_, QString password_, bool admin);
    QString getName();
    QString getPass();
    void setRights(bool tilfoej_, bool aendreBrugerprofil_, bool aktivitet_, bool lysstyring_, bool adfaerd_ , bool enhed_ );
    vector<bool> getRights();
    void setPassword(QString newpassword);
    void setLock(bool newlock);
    bool getLock();
    bool getAdmin();

private:
    QString userName, password;
    bool adfaerd, lysstyring, aktivitet, enhed, aendreBrugerprofil, tilfoej;
    bool isLock;
    bool isAdmin;

};

#endif //KPESERVER_USER_H
