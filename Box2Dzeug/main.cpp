#include "mainwindow.h"
#include <QApplication>
#include "main.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu = new GUI();
    menu->show();
    menu->displayGUI();

    /*MainWindow* test;
    test = new MainWindow();
    test->show();*/
    //test->displayLevel();

    return a.exec();
}
