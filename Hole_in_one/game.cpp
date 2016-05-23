#include "game.h"
#include <button.h>
#include <QGraphicsTextItem>

Game::Game(QWidget *parent){
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*!Scene setup*/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}
/*display main menu!*/
void Game::displayMenu()
{
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
    connect(levelButton, SIGNAL(clicked()), this, SLOT(levelMenu()));
    scene->addItem(levelButton);

    /*!create highscore button*/
    Button* scoreButton = new Button(QString("Highscore"));
    int scorexPos = this->width()/2-scoreButton->boundingRect().width()/2;
    int scoreyPos = 410;
    scoreButton->setPos(scorexPos,scoreyPos);
    connect(levelButton, SIGNAL(clicked()), this, SLOT(highscore()));
    scene->addItem(scoreButton);

    /*!create quit button*/
    Button* quitButton = new Button(QString("Quit"));
    int quitxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int quityPos = 510;
    quitButton->setPos(quitxPos,quityPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

/*!initialise level menu*/
void Game::levelMenu()
{
//clear scene first
    scene->clear();

}
/*!initialise highscore screen*/
void Game::highscore()
{

}
