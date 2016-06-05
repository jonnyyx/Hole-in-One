#include "main.h"
#include"gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu = new GUI();
    menu->show();
    menu->displayGUI();


    return a.exec();
}
