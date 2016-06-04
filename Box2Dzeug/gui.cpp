#include "gui.h"
#include <button.h>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include "mainwindow.h"

GUI::GUI(QWidget *parent){
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*!Scene setup*/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void GUI::displayGUI()
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
    connect(levelButton, SIGNAL(clicked()), this, SLOT(levelMenu())); //TODO levelMenu()
    scene->addItem(levelButton);

    /*!create highscore button*/
    Button* scoreButton = new Button(QString("Highscore"));
    int scorexPos = this->width()/2-scoreButton->boundingRect().width()/2;
    int scoreyPos = 410;
    scoreButton->setPos(scorexPos,scoreyPos);
    connect(scoreButton, SIGNAL(clicked()), this, SLOT(highscore())); //TODO highscore
    scene->addItem(scoreButton);

    /*!create quit button*/
    Button* quitButton = new Button(QString("Quit"));
    int quitxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int quityPos = 510;
    quitButton->setPos(quitxPos,quityPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}

void GUI::levelMenu()
{

    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level Menu"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 80;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    /*!create level menu button*/
    Button* level1 = new Button(QString("Level 1"));
    int levelxPos = 50;
    int levelyPos = 150;
    level1->setPos(levelxPos,levelyPos);
    connect(level1, SIGNAL(clicked()), this, SLOT(showLevel1())); //............................
    scene->addItem(level1);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 550;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(backButton);
}

void GUI::back(){
    scene->clear();
    displayGUI();
}

void GUI::showLevel1()
{
     MainWindow* test; //.............................
     test = new MainWindow();
     test->show();
}

void GUI::highscore()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Highscore"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 80;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    /*!create level menu button*/
    Button* level1 = new Button(QString("#1"));
    int levelxPos = 50;
    int levelyPos = 150;
    level1->setPos(levelxPos,levelyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(level1);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 550;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(backButton);
}
