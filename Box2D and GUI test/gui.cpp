#include "gui.h"

#include <QGraphicsTextItem>
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

    /*!ismute false by default*/
    ismute=false;

}

void GUI::displayGUI()
{

     /*!create title text*/
    QGraphicsPixmapItem* titleText = new QGraphicsPixmapItem(QPixmap(":/images/images/Title.png"));
    int titlexPos = this->width()/2-titleText->boundingRect().width()/2;
    int titleyPos = 120;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    /*!create level menu button*/
    picButton* levelpicButton = new picButton(QPixmap(":/images/images/levelbuttonhover.png"), QPixmap(":/images/images/levelbuttondefault.png"));
    int levelxPos = this->width()/2-levelpicButton->width()/2;
    int levelyPos = 270;
    levelpicButton->move(levelxPos,levelyPos);
    connect(levelpicButton, SIGNAL(clicked()), this, SLOT(levelMenu()), Qt::QueuedConnection);
    scene->addWidget(levelpicButton);

    /*!create highscore button*/

    picButton* scorepicButton = new picButton(QPixmap(":/images/images/highscorebuttondefault.png"), QPixmap(":/images/images/highscorebuttonhover.png"));
    int scorexPos = this->width()/2-scorepicButton->width()/2;
    int scoreyPos = 370;
    scorepicButton->move(scorexPos,scoreyPos);
    connect(scorepicButton, SIGNAL(clicked()), this, SLOT(highscore()), Qt::QueuedConnection);
    scene->addWidget(scorepicButton);

    /*!create help button*/

    picButton* helppicButton = new picButton(QPixmap(":/images/images/helpbuttondefault.png"), QPixmap(":/images/images/helpbuttonhover.png"));
    int helpxPos = this->width()/2-helppicButton->width()/2;
    int helpyPos = 470;
    helppicButton->move(helpxPos,helpyPos);
    connect(helppicButton, SIGNAL(clicked()), this, SLOT(help()), Qt::QueuedConnection);
    scene->addWidget(helppicButton);

    /*!create quit button*/
    picButton* quitpicButton = new picButton(QPixmap(":/images/images/quitbuttondefault.png"), QPixmap(":/images/images/quitbuttonhover.png"));
    int quitxPos = this->width()/2-quitpicButton->width()/2;
    int quityPos = 570;
    quitpicButton->move(quitxPos,quityPos);
    connect(quitpicButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addWidget(quitpicButton);

    /*!create quit button*/
    mutepicButton = new picButton(QPixmap(":/images/images/soundon.png"), QPixmap(":/images/images/soundon.png"), false);
    int mutexPos = 920;
    int muteyPos = 680;
    mutepicButton->move(mutexPos,muteyPos);
    connect(mutepicButton, SIGNAL(clicked()), this, SLOT(mute()), Qt::QueuedConnection);
    scene->addWidget(mutepicButton);

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

void GUI::help()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 80;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 550;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    scene->addItem(backButton);


}

void GUI::mute()
{


    if(ismute==false){
        ismute=true;
        mutepicButton->setdefaultpic(QPixmap(":/images/images/soundoff.png"));
    }
    else if(ismute==true){
        ismute=false;
        mutepicButton->setdefaultpic(QPixmap(":/images/images/soundon.png"));
    }
}
