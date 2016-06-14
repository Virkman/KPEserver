//
// Created by Nicholas on 01-06-2016.
//

#include "User.h"


User::User(QString userName_, QString password_, bool admin) {
    if (userName_ != NULL && password_ != NULL) {
        userName = userName_;
        password = password_;
        isLock = false;
        isAdmin = admin;
    } else {
        exit(0);
    }
}

QString User::getName() {
    return userName;
}

void User::setRights(bool tilfoej_, bool aendreBrugerprofil_, bool aktivitet_, bool lysstyring_, bool adfaerd_ , bool enhed_ ) {
    tilfoej = tilfoej_;
    adfaerd = adfaerd_;
    lysstyring = lysstyring_;
    aktivitet = aktivitet_;
    enhed = enhed_;
    aendreBrugerprofil = aendreBrugerprofil_;
}

vector<bool> User::getRights() {
    if (isAdmin){
        vector<bool> rights;
        for (int i = 0 ; i < 6 ; i ++){
            rights.push_back(true);
        }
        return rights;
    } else {
        vector<bool> rights;
        rights.push_back(tilfoej);
        rights.push_back(aendreBrugerprofil);
        rights.push_back(aktivitet);
        rights.push_back(lysstyring);
        rights.push_back(adfaerd);
        rights.push_back(enhed);
        return rights;
    }
}

QString User::getPass() {
    return password;
}

void User::setPassword(QString newpassword) {
    password = newpassword;
}

void User::setLock(bool newlock) {
    isLock = newlock;
}

bool User::getLock() {
    if (isAdmin){
        return false;
    }
    return isLock;
}

bool User::getAdmin() {
    return isAdmin;
}