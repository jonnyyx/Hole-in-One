#include "gui.h"
#include <button.h>
#include <picbutton.h>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QtSvg/QGraphicsSvgItem>

GUI::GUI(QWidget *parent){
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);
    setBackgroundBrush(QBrush(QColor(191,153,89), Qt::SolidPattern));

    /*!Scene setup*/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);

}

void GUI::displayGUI()
{
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

    /*!create level menu button*/
    Button* levelButton = new Button(QString("Levels"));
    //int levelxPos = this->width()/2-levelButton->boundingRect().width()/2;
    //int levelyPos = 10;
    //levelButton->setPos(levelxPos,levelyPos);
    connect(levelButton, SIGNAL(clicked()), this, SLOT(levelMenu())); //TODO levelMenu()
    scene->addItem(levelButton);

    /*!create highscore button*/
    Button* scoreButton = new Button(QString("Highscore"));
    //int scorexPos = this->width()/2-scoreButton->boundingRect().width()/2;
    int scoreayPos = 100;
    scoreButton->setPos(0,scoreayPos);
    connect(scoreButton, SIGNAL(clicked()), this, SLOT(highscore())); //TODO highscore
    scene->addItem(scoreButton);

    setScene(scene);

}

void GUI::levelMenu()
{

    scene->clear();
    /*!create title text*/
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
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(onepicButton);

    picButton* twopicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int twoxPos = 348;
    int twoyPos = 250;
    twopicButton->move(twoxPos,twoyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(twopicButton);


    picButton* threepicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int threexPos = 548;
    int threeyPos = 250;
    threepicButton->move(threexPos,threeyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(threepicButton);


    picButton* fourpicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int fourxPos = 748;
    int fouryPos = 250;
    fourpicButton->move(fourxPos,fouryPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(fourpicButton);


    picButton* fivepicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int fivexPos = 148;
    int fiveyPos = 450;
    fivepicButton->move(fivexPos,fiveyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(fivepicButton);


    picButton* sixpicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int sixxPos = 348;
    int sixyPos = 450;
    sixpicButton->move(sixxPos,sixyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(sixpicButton);


    picButton* sevenpicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int sevenxPos = 548;
    int sevenyPos = 450;
    sevenpicButton->move(sevenxPos,sevenyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(sevenpicButton);


    picButton* eightpicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
    int eightxPos = 748;
    int eightyPos = 450;
    eightpicButton->move(eightxPos,eightyPos);
    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
    scene->addWidget(eightpicButton);




//    Button* level1 = new Button(QString("Level 1"));
//    int levelxPos = 50;
//    int levelyPos = 150;
//    level1->setPos(levelxPos,levelyPos);
//    //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
//    scene->addItem(level1);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 700;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(backButton);
}

void GUI::back(){
    scene->clear();
    displayGUI();
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
