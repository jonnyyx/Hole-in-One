#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* test;
    test = new MainWindow();
    test->show();
    test->displayLevel();

    return a.exec();
}
