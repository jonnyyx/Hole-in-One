#include "mainmenu.h"
#include <QApplication>


MainMenu* test;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test = new MainMenu();
    test->show();
    //test->displayMainMenu();
    //game->levelMenu();

    return a.exec();
}
