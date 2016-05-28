#include "mainmenu.h"
#include <button.h>
#include "levelmenu.h"
#include <QGraphicsTextItem>


LevelMenu::LevelMenu(QWidget *parent)
{
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level Menu"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 80;
    titleText->setPos(titlexPos,titleyPos);
    MainMenu().scene->addItem(titleText);

    /*!create level menu button*/
    Button* level1 = new Button(QString("Level 1"));
    int levelxPos = 50;
    int levelyPos = 150;
    level1->setPos(levelxPos,levelyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(close()));
    MainMenu().scene->addItem(level1);
}

void LevelMenu::startLevelMenu()
{
    MainMenu().scene->clear();
    LevelMenu();
}


//void LevelMenu::displayLevelMenu()
//{
//    /*!create title text*/
//    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level Menu"));
//    QFont titleFont("comic sans", 50);
//    titleText->setFont(titleFont);
//    int titlexPos = 50;
//    int titleyPos = 80;
//    titleText->setPos(titlexPos,titleyPos);
//    scene1->addItem(titleText);

//    /*!create level menu button*/
//    Button* level1 = new Button(QString("Level 1"));
//    int levelxPos = 50;
//    int levelyPos = 150;
//    level1->setPos(levelxPos,levelyPos);
//    //connect(level1, SIGNAL(clicked()), this, SLOT(close()));
//    scene1->addItem(level1);
//}
