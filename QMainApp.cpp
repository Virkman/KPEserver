//
// Created by Nicholas on 01-06-2016.
//


#include <c++/iostream>
#include "QMainApp.h"

QMainApp::QMainApp(int &argc, char **argv) : QApplication(argc, argv){
    User *adminUser = new User((QString)"a", (QString) "p",true);
    adminUser->setRights(true, true, true, true, true, true);
    addUserToList(adminUser);

    dialog = new ServerDialog();
    dialog->show();

    /*MainPage *mainPage = new MainPage();
    //mainPage->setupPages(adminUser);
    mainPage->hide();
    //LoginDialog *loginDialog = new LoginDialog;
    loginDialog->show();
    QObject::connect(loginDialog, SIGNAL (acceptLogin(QString&,QString&)),
                     mainPage,
                     SLOT (slotAcceptUserLogin(QString&,QString&)));*/
}

QList<User *> QMainApp::getUserList() {
    return userList;
}

void QMainApp::addUserToList(User *newUser) {
    userList << newUser;
    //qDebug (userName_.toLatin1());
    qDebug(newUser->getName().toLatin1());
}

LoginDialog* QMainApp::getLogin() {
            foreach(QWidget *widget, findChildren<QWidget *>()){
            if(!widget->windowFlags() & Qt::Window){
                delete widget;
            }
        }
    return loginDialog;

}

void QMainApp::setUserList(QList<User *> list) {
    userList = list;
}

void QMainApp::removeUser(int userIndex) {
    delete userList.at(userIndex);
    userList.removeAt(userIndex);
}


void QMainApp::setCurrentUser(QString userName) {
    for (int i = 0 ; i < userList.size() ; i++){
        if (userList.at(i)->getName() == userName){
            currentUser = userList.at(i);
        }
    }
}

User QMainApp::getCurrentUser() {
    return *currentUser;
}


void QMainApp::notFirstTime(){
    //mainPage->notFirstTime();
}

void QMainApp::addNewOrder(Bestilling *bestilling) {
    bestillingsDB.append(bestilling);
    qDebug() << "Adresse :" << bestilling->getAdresse() << " tlf: " << bestilling->getTlf() << endl;
    qDebug() << "BD størrelse: " << bestillingsDB.size() << endl;
    dialog->sendNewOrder(server1soc, server2soc);
}

Bestilling QMainApp::getLasOrder() {
    return *bestillingsDB.last();
}

Bestilling QMainApp::getOrder( int pos ) {
    return *bestillingsDB.at(pos);
}

int QMainApp::getDbSize() {
    return bestillingsDB.size();
}

void QMainApp::setSocket(int nr, qintptr socket) {
    if (nr == 1){
        server1soc = socket;
    }
    if (nr == 2){
        server2soc = socket;
    }
}


