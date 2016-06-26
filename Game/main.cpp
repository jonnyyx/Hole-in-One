
#include <QApplication>

#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GUI *menu = new GUI();
    menu->show();
    menu->displayGUI();



    return a.exec();
}
