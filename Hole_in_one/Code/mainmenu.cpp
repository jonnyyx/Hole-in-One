#include "mainmenu.h"
#include <button.h>
#include "levelmenu.h"
#include <QGraphicsTextItem>

MainMenu::MainMenu(QWidget *parent){
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*!Scene setup*/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);

    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Hole in One"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int titlexPos = this->width()/2-titleText->boundingRect().width()/2;
    int titleyPos = 150;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    /*!create level menu button*/
    Button* levelButton = new Button(QString("Levels"));
    int levelxPos = this->width()/2-levelButton->boundingRect().width()/2;
    int levelyPos = 310;
    levelButton->setPos(levelxPos,levelyPos);
    connect(levelButton, SIGNAL(clicked()), this, SLOT(startLevelMenu()));
    scene->addItem(levelButton);

    /*!create highscore button*/
    Button* scoreButton = new Button(QString("Highscore"));
    int scorexPos = this->width()/2-scoreButton->boundingRect().width()/2;
    int scoreyPos = 410;
    scoreButton->setPos(scorexPos,scoreyPos);
    connect(scoreButton, SIGNAL(clicked()), this, SLOT());
    scene->addItem(scoreButton);

    /*!create quit button*/
    Button* quitButton = new Button(QString("Quit"));
    int quitxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int quityPos = 510;
    quitButton->setPos(quitxPos,quityPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}

///*display main menu!*/
//void MainMenu::displayMainMenu()
//{
//    /*!create title text*/
//    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Hole in One"));
//    QFont titleFont("comic sans", 50);
//    titleText->setFont(titleFont);
//    int titlexPos = this->width()/2-titleText->boundingRect().width()/2;
//    int titleyPos = 150;
//    titleText->setPos(titlexPos,titleyPos);
//    scene->addItem(titleText);

//    /*!create level menu button*/
//    Button* levelButton = new Button(QString("Levels"));
//    int levelxPos = this->width()/2-levelButton->boundingRect().width()/2;
//    int levelyPos = 310;
//    levelButton->setPos(levelxPos,levelyPos);
//    connect(levelButton, SIGNAL(clicked()), this, SLOT(startlevelMenu()));
//    scene->addItem(levelButton);

//    /*!create highscore button*/
//    Button* scoreButton = new Button(QString("Highscore"));
//    int scorexPos = this->width()/2-scoreButton->boundingRect().width()/2;
//    int scoreyPos = 410;
//    scoreButton->setPos(scorexPos,scoreyPos);
//    connect(scoreButton, SIGNAL(clicked()), this, SLOT());
//    scene->addItem(scoreButton);

//    /*!create quit button*/
//    Button* quitButton = new Button(QString("Quit"));
//    int quitxPos = this->width()/2-quitButton->boundingRect().width()/2;
//    int quityPos = 510;
//    quitButton->setPos(quitxPos,quityPos);
//    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
//    scene->addItem(quitButton);


//}

void MainMenu::startLevelMenu()
{
    scene->clear();
    LevelMenu();
}

///*!initialise level menu*/
//void LevelMenu::levelMenu()
//{
////clear scene first
//}

///*!initialise highscore screen*/
//void MainMenu::highscore()
//{
////clear scene first
//}
