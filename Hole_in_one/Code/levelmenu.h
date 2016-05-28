#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainmenu.h"

class MainMenu;
class LevelMenu : public QGraphicsView
{
    Q_OBJECT

public:
    //constructor of LevelMenu
    LevelMenu(QWidget* parent=NULL);
    MainMenu* mainmenu;
    int getStatus(bool status);
    void setStatus();


private:
    bool status; //enabled or disabled?
public slots:
      void startLevelMenu();

};

#endif // LEVELMENU_H
