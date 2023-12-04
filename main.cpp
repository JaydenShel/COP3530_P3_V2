#include "mainwindow.h"
#include <vector>
#include <string>
#include <QApplication>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


