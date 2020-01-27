#include "mainwindow.h"
#include "loginwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //LoginWindow loginWindow;
    //loginWindow.show();
    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
