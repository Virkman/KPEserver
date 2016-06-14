#include <c++/iostream>
#include "QMainApp.h"

int main(int argc, char *argv[])
{
    QMainApp app(argc, argv);
    cout << "Hello World" << endl;
    return app.exec();
}
