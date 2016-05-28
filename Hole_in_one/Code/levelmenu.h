#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainmenu.h"


class LevelMenu : public QGraphicsView
{
    friend class MainMenu;
public:
    //constructor of LevelMenu
    LevelMenu(QWidget* parent=NULL);

    int getStatus(bool status);
    void setStatus();


private:
    bool status; //enabled or disabled?
public slots:
      void startLevelMenu();

};

#endif // LEVELMENU_H
