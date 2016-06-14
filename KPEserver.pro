#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T07:45:18
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
                                  QT += network

TARGET = KPEserver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        LoginDialog.cpp\
        QMainApp.cpp\
        User.cpp\
        Server.cpp

HEADERS  += mainwindow.h\
            mainwindow.h\
            LoginDialog.h\
            QMainApp.h\
            User.h\
            Server.h


FORMS    += mainwindow.ui
