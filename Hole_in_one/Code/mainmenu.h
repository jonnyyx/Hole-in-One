#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelmenu.h"
class LevelMenu;
class MainMenu : public QGraphicsView
{
    Q_OBJECT

public:
    /*!Constructor of the MainMenu*/
    MainMenu(QWidget* parent=NULL);

    /*!public methods*/
    //void displayMainMenu();

    /*!public Attributes*/
    QGraphicsScene* scene;
    LevelMenu* levelmenu;

public slots:
    void startLevelMenu();


};

#endif // MAINMENU_H
