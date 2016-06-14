cmake_minimum_required(VERSION 3.5)
project(KPEserver)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)


include_directories(MenuWidgets)

set(SOURCE_FILES
    KPEserver.pro
    KPEserver.pro.user
    main.cpp
        MainPage.cpp
        MainPage.h
        MainPage.ui
        QMainApp.cpp
        QMainApp.h
        User.cpp
        User.h
        LoginDialog.cpp
        LoginDialog.h
        Server.cpp
        Server.h
        ServerThread.cpp
        ServerThread.h
        Bestilling.cpp
        Bestilling.h
        ServerDialog.cpp
        ServerDialog.h ServerStarter.cpp ServerStarter.h)

add_executable(KPEserver ${SOURCE_FILES})

target_link_libraries(KPEserver Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)