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
    setBackgroundBrush(QBrush(QColor(191,153,89), Qt::SolidPattern));

    /*!Scene setup*/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void GUI::displayGUI()
{
    scene->clear();
     /*!create title text*/
    QGraphicsPixmapItem* titleText = new QGraphicsPixmapItem(QPixmap(":/images/images/Title.png"));
    int titlexPos = this->width()/2-titleText->boundingRect().width()/2;
    int titleyPos = 150;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    /*!create level menu button*/
    picButton* levelpicButton = new picButton(QPixmap(":/images/images/levelbuttondefault.png"), QPixmap(":/images/images/levelbuttonhover.png"));
    int levelxPos = this->width()/2-levelpicButton->width()/2;
    int levelyPos = 310;
    levelpicButton->move(levelxPos,levelyPos);
    connect(levelpicButton, SIGNAL(clicked()), this, SLOT(levelMenu()));
    scene->addWidget(levelpicButton);

    /*!create highscore button*/

    picButton* scorepicButton = new picButton(QPixmap(":/images/images/highscorebuttonhover.png"), QPixmap(":/images/images/highscorebuttondefault.png"));
    int scorexPos = this->width()/2-scorepicButton->width()/2;
    int scoreyPos = 410;
    scorepicButton->move(scorexPos,scoreyPos);
    connect(scorepicButton, SIGNAL(clicked()), this, SLOT(highscore()));
    scene->addWidget(scorepicButton);

    /*!create quit button*/
    picButton* quitpicButton = new picButton(QPixmap(":/images/images/quitbuttonhover.png"), QPixmap(":/images/images/quitbuttondefault.png"));
    int quitxPos = this->width()/2-quitpicButton->width()/2;
    int quityPos = 510;
    quitpicButton->move(quitxPos,quityPos);
    connect(quitpicButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addWidget(quitpicButton);


}

void GUI::levelMenu()
{
    scene->clear();
    QGraphicsPixmapItem* titleText = new QGraphicsPixmapItem(QPixmap(":/images/images/LevelTitle.png"));
    int titlexPos = this->width()/2-titleText->boundingRect().width()/2;
    int titleyPos = 60;
    titleText->setPos(titlexPos,titleyPos);

    scene->addItem(titleText);

    /*!create level menu button*/
    picButton* onepicButton = new picButton(QPixmap(":/images/images/1hover.png"), QPixmap(":/images/images/1enabled.png"));
    int onexPos = 148;
    int oneyPos = 250;
    onepicButton->move(onexPos,oneyPos);
    connect(onepicButton, SIGNAL(clicked()), this, SLOT(showLevel1()));
    scene->addWidget(onepicButton);

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

void GUI::showLevel1()      //scene und level anpassen. 2. Fenster wird geöffnet für Level
{
    MainWindow *test;
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
    connect(level1, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(level1);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 550;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(backButton);

   
}
