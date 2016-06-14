//
// Created by Nicholas on 01-06-2016.
//

#include "LoginDialog.h"

#include <QtWidgets/QMessageBox>
#include <c++/iostream>
#include "LoginDialog.h"
#include "QMainApp.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setUpGUI();
    setWindowTitle(tr("User Login"));
    setModal(true);

    DE2off = true;


}

void LoginDialog::setUpGUI() {
    // set up the layout
    QGridLayout *formGridLayout = new QGridLayout(this);

    editUsername = new QLineEdit(this);
    editPassword = new QLineEdit(this);
    editPassword->setEchoMode(QLineEdit::Password);

// initialize the labels
    labelUsername = new QLabel(this);
    labelPassword = new QLabel(this);
    labelUsername->setText(tr("Brugernavn"));
    labelUsername->setBuddy(editUsername);
    labelPassword->setText(tr("Kodeord"));
    labelPassword->setBuddy(editPassword);
    editUsername->setPlaceholderText("Brugernavn");
    editPassword->setPlaceholderText("Kodeord");

// initialize buttons
    buttons = new QDialogButtonBox(this);
    buttons->addButton(QDialogButtonBox::Ok);
    buttons->button(QDialogButtonBox::Ok)->setText(tr("Log ind"));


    // connects slots
    connect(buttons->button(QDialogButtonBox::Ok),
            SIGNAL (clicked()),
            this,
            SLOT(slotAcceptLogin()));



// place components into the dialog
    formGridLayout->addWidget(labelUsername, 0, 0);
    formGridLayout->addWidget(editUsername, 0, 1);
    formGridLayout->addWidget(labelPassword, 1, 0);
    formGridLayout->addWidget(editPassword, 1, 1);
    formGridLayout->addWidget(buttons, 2, 0, 1, 2);

/*    QString userName = "Admin";
    setUsername(userName);
  */  setLayout(formGridLayout);

    att = 0;

}



void LoginDialog::clearInput() {
    editPassword->setText("");
    editUsername->setText("");
}

void LoginDialog::slotAcceptLogin() {
    QString username = editUsername->text();
    QString password = editPassword->text();
    QString tempUserName;

    QList<User *> userList = static_cast<QMainApp *>qApp->getUserList();
    if (username == tempUserName){
        att = 0;
    }
    if(username == "" || password == ""){
        return;
    } else {
        for (int i = 0; i < userList.size() ; ++i) {
            if (userList.at(i)->getName() == username && (userList.at(i)->getPass() + "iampro") == password && userList.at(i)->getAdmin()){
                cout << "It's true bro, and the PC know its not you first time :D" << endl;
                password.remove("iampro");
                        static_cast<QMainApp *>qApp->setCurrentUser(username);
                        static_cast<QMainApp *>qApp->notFirstTime();
                        password = userList.at(i)->getPass();
                        emit acceptLogin(username, // current username
                                         password // current password

                        );
                        this->hide();
                        return;
            }
            if(userList.at(i)->getName() == username && userList.at(i)->getPass() == password && !userList.at(i)->getLock()){
                cout << "It's true bro" << endl;


                static_cast<QMainApp *>qApp->setCurrentUser(username);
                    emit acceptLogin(username, // current username
                                     password // current password
                );
                this->hide();
                return;
            }

            if (userList.at(i)->getLock()){
                QMessageBox errorMessage;
                errorMessage.setText("Brugeren er låst, kontakt administrator");
                errorMessage.exec();
                return;
            }
            // 3 forsøg og derefter låses brugeren.
            if (userList.at(i)->getName() == username){
                att++;

                /*if (att == 3){

                    userList.at(i)->setLock(true);

                    static_cast<QMainApp *> qApp->lockUser(i);

                    QMessageBox errorMessage;
                    errorMessage.setText("Du har forsøgt med 3 forkerte password, brugeren er nu låst, kontakt administrator");
                    errorMessage.exec();
                }*/
                if (att < 3) {
                    QMessageBox errorMessage;
                    QString temp = "Forkert password!";
                    errorMessage.setText(temp);
                    errorMessage.exec();
                    if (userList.at(i)->getAdmin()){
                        att = 0;
                    }
                }
                if (att == 1){
                    if (username != tempUserName){
                        att = 0;
                    }
                }
                tempUserName = username;
                editPassword->clear();
            }

        }


    }
}

void LoginDialog::showMe() {
    clearInput();
    this->show();
}
