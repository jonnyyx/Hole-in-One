#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelmenu.h"

class MainMenu : public QGraphicsView
{
public:
    /*!Constructor of the MainMenu*/
    MainMenu(QWidget* parent=NULL);

    /*!public methods*/
    //void displayMainMenu();

    /*!public Attributes*/
    QGraphicsScene* scene;

public slots:
    void startLevelMenu();


};

#endif // MAINMENU_H
