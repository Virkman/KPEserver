//
// Created by Nicholas on 01-06-2016.
//

#ifndef KPESERVER_QMAINAPP_H
#define KPESERVER_QMAINAPP_H

#include <QtWidgets/QApplication>
#include "User.h"
#include "LoginDialog.h"
#include "MainPage.h"
#include "Bestilling.h"
#include "ServerDialog.h"

class QMainApp : public QApplication {

public:
    QMainApp(int &argc, char *argv[]);
    QList<User *> getUserList();
    void addUserToList(User *newUser);
    LoginDialog *getLogin();
    void setUserList(QList<User *> list);
    void removeUser(int userIndex);
    void lockUser(int userIndex);
    void unLockUser(int userIndex);
    void setCurrentUser(QString userName);
    User getCurrentUser();
    void notFirstTime();
    void addNewOrder(Bestilling *bestilling);
    Bestilling getLasOrder();
    Bestilling getOrder(int pos);
    int getDbSize();
    void setSocket(int nr, qintptr socket);

private:
    LoginDialog *loginDialog = new LoginDialog;
    QList<User *> userList;
    QList<Bestilling *> bestillingsDB;
    User *currentUser;
    ServerDialog *dialog;
    qintptr server1soc;
    qintptr server2soc;
};

#endif //KPESERVER_QMAINAPP_H
