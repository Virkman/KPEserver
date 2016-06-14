#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QWidget>
#include "User.h"
#include "QMainApp.h"
#include "ServerDialog.h"

using namespace std;
class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = 0);

public slots:
    void slotAcceptUserLogin(QString&,QString&);

private:
    //Ui::MainPage *ui;
    QPushButton *testknap;
    QString currentUserName;                        // holds the current username try
    QString currentPassword;
};

#endif // MAINWINDOW_H
