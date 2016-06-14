#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QtGui>
#include <c++/iostream>
 #include "MainPage.h"


MainPage::MainPage(QWidget *parent) :
    QWidget(parent)

{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    /*QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QLabel *hello = new QLabel("HEllo WORLD!");

    testknap = new QPushButton;
    testknap->setText("Test Knap");

    mainLayout->addWidget(hello);
    mainLayout->addWidget(testknap);



    setLayout(mainLayout);*/
}

void MainPage::slotAcceptUserLogin(QString &userName, QString &password) {
    cout << "Welcome to MainPage" << endl;
    currentUserName = userName;
    currentPassword = password;
    QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();



    for (int i = 0; i <tempUserList.size() ; ++i) {
        if(tempUserList.at(i)->getName()==currentUserName){
            //setupPages(tempUserList.at(i));
            qDebug() << tempUserList.at(i);
            qDebug() << tempUserList.size();
        }
    }
    /*if (firstTime){
        forsteGangsVisning();
    } else {*/
        this->show();
    //}

}
