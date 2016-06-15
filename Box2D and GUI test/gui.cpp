#include "gui.h"
#include <QFile>
#include <QGraphicsTextItem>
#include "level_1.h"
#include "level_2.h"
#include "qdebug.h"
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

    /*!create sound button*/
    mutepicButton = new picButton(QPixmap(":/images/images/soundon.png"), QPixmap(":/images/images/soundon.png"), false);
    int mutexPos = 920;
    int muteyPos = 680;
    mutepicButton->move(mutexPos,muteyPos);
    connect(mutepicButton, SIGNAL(clicked()), this, SLOT(mute()), Qt::QueuedConnection);
    scene->addWidget(mutepicButton);

}

void GUI::levelMenu()
{
    checkLevel();
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
    qDebug()<<levelenab.isEmpty();
    if(!levelenab.isEmpty()&&levelenab.at(1)=="true\n"){
        picButton* twopicButton = new picButton(QPixmap(":/images/images/1hover.png"), QPixmap(":/images/images/1enabled.png"));
        int twoxPos = 348;
        int twoyPos = 250;
        twopicButton->move(twoxPos,twoyPos);
        connect(twopicButton, SIGNAL(clicked()), this, SLOT(showLevel2()));
        scene->addWidget(twopicButton);

    }
    else{
        picButton* twopicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
        int twoxPos = 348;
        int twoyPos = 250;
        twopicButton->move(twoxPos,twoyPos);

        scene->addWidget(twopicButton);
    }
    if(!levelenab.isEmpty()&&levelenab.at(2)=="true\n"){
            picButton* threepicButton = new picButton(QPixmap(":/images/images/1hover.png"), QPixmap(":/images/images/1enabled.png"));
            int threexPos = 548;
            int threeyPos = 250;
            threepicButton->move(threexPos,threeyPos);
            //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
            scene->addWidget(threepicButton);

    }
    else{
        picButton* threepicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
        int threexPos = 548;
        int threeyPos = 250;
        threepicButton->move(threexPos,threeyPos);

        scene->addWidget(threepicButton);
    }
    if(!levelenab.isEmpty()&&levelenab.at(3)=="true\n"){
            picButton* fourpicButton = new picButton(QPixmap(":/images/images/1hover.png"), QPixmap(":/images/images/1disabled.png"));
            int fourxPos = 748;
            int fouryPos = 250;
            fourpicButton->move(fourxPos,fouryPos);
            //connect(level1, SIGNAL(clicked()), this, SLOT(level_1234...));
            scene->addWidget(fourpicButton);

    }else{
        picButton* fourpicButton = new picButton(QPixmap(":/images/images/1disabled.png"), QPixmap(":/images/images/1disabled.png"));
        int fourxPos = 748;
        int fouryPos = 250;
        fourpicButton->move(fourxPos,fouryPos);
        scene->addWidget(fourpicButton);
    }

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
    int backyPos = 650;
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
    Level_1 *test;
    test = new Level_1();
    test->show();

}

void GUI::showLevel2()      //scene und level anpassen. 2. Fenster wird geöffnet für Level
{
    Level_2 *test2;
    test2 = new Level_2();
    test2->show();

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
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);


    //Game instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("What is it all about?""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* firstText = new QGraphicsTextItem(QString(
                                                             "Welcome to 'Hole in One', this unique physic game will be your perfect companion" "\n"
                                                             "for diverting hours. The aim is to lead the paperball through different levels to the" "\n"
                                                             "trash can, to fullfill its purpose of life. To succeed the different tasks there is a" "\n"
                                                             "wide set of tools ready to be used by the player. These tools are necessary to" "\n"
                                                             "bypass different and many evil obstacles, which will do everything to prevent the" "\n"
                                                             "ball from reaching his goal.""\n"
                                                             "Be the chosen one and support the paperball!" "\n"
                                                             "_____________________________________________________________________"
                                                             ));
    QFont firstFont("comic sans", 18);
    firstText->setFont(firstFont);
    int firstxPos = 50;
    int firstyPos = 160;
    firstText->setPos(firstxPos,firstyPos);
    scene -> addItem(firstText);


    //Tool instruction
    QGraphicsTextItem* secondCap = new QGraphicsTextItem(QString("Tools:""\n"));
    QFont secondCFont("comic sans", 26);
    secondCap->setFont(secondCFont);
    int secondCxPos = 50;
    int secondCyPos = 412;
    secondCap->setPos(secondCxPos,secondCyPos);
    scene -> addItem(secondCap);

    //Tool instruction buttons
    Button* boxButton = new Button(QString("Rectangle"));
    boxButton->setRect(0,0,100,100);
    int boxxPos = 180;
    int boxyPos = 412;
    boxButton->setPos(boxxPos,boxyPos);
    connect(boxButton, SIGNAL(clicked()), this, SLOT(box()));
    scene->addItem(boxButton);

    Button* cirlceButton = new Button(QString("Cirlce"));
    cirlceButton->setRect(0,0,100,100);
    int cirlcexPos = 310;
    int cirlceyPos = 412;
    cirlceButton->setPos(cirlcexPos,cirlceyPos);
    connect(cirlceButton, SIGNAL(clicked()), this, SLOT(circle()));
    scene->addItem(cirlceButton);


    Button* triangleButton = new Button(QString("Triangle"));
    triangleButton->setRect(0,0,100,100);
    int trianglexPos = 440;
    int triangleyPos = 412;
    triangleButton->setPos(trianglexPos,triangleyPos);
    connect(triangleButton, SIGNAL(clicked()), this, SLOT(triangle()));
    scene->addItem(triangleButton);

    Button* springButton = new Button(QString("Spring"));
    springButton->setRect(0,0,100,100);
    int springxPos = 570;
    int springyPos = 412;
    springButton->setPos(springxPos,springyPos);
    connect(springButton, SIGNAL(clicked()), this, SLOT(spring()));
    scene->addItem(springButton);

    Button* trampolineButton = new Button(QString("Trampoline"));
    trampolineButton->setRect(0,0,100,100);
    int trampolinexPos = 700;
    int trampolineyPos = 412;
    trampolineButton->setPos(trampolinexPos,trampolineyPos);
    connect(trampolineButton, SIGNAL(clicked()), this, SLOT(trampoline()));
    scene->addItem(trampolineButton);

    Button* conveyorButton = new Button(QString("Conveyor"));
    conveyorButton->setRect(0,0,100,100);
    int conveyorxPos = 830;
    int conveyoryPos = 412;
    conveyorButton->setPos(conveyorxPos,conveyoryPos);
    connect(conveyorButton, SIGNAL(clicked()), this, SLOT(conveyor()));
    scene->addItem(conveyorButton);


    QGraphicsTextItem* secondText = new QGraphicsTextItem(QString(
     "_____________________________________________________________________"
                                                             ));
    QFont secondFont("comic sans", 18);
    secondText->setFont(secondFont);
    int secondxPos = 50;
    int secondyPos = 500;
    secondText->setPos(secondxPos,secondyPos);
    scene -> addItem(secondText);

    //Obstacles instruction
    QGraphicsTextItem* obstaCap = new QGraphicsTextItem(QString("Obstacles:""\n"));
    QFont obstaCFont("comic sans", 26);
    obstaCap->setFont(obstaCFont);
    int obstaCxPos = 50;
    int obstaCyPos = 540;
    obstaCap->setPos(obstaCxPos,obstaCyPos);
    scene -> addItem(obstaCap);

    QGraphicsTextItem* obstText = new QGraphicsTextItem(QString(
                                                             "Obstacles are objects which can not be moved by the player." "\n"
                                                             "Since obstacles can be of the same type as tools (such as" "\n"
                                                             "trampolines, springs, conveyors etc.) they just vary in colour." "\n"
                                                             "They hamper the ball of paper to reach the trash basket, but" "\n"
                                                             "you may use them in your favour. Mostly they are fixed in the" "\n"
                                                             "scene, but some managed to move around to raise difficulty."
                                                             ));
    QFont obstFont("comic sans", 18);
    obstText->setFont(obstFont);
    int obstxPos = 260;
    int obstyPos = 552;
    obstText->setPos(obstxPos,obstyPos);
    scene -> addItem(obstText);


    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
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

void GUI::box()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);


    //Rect instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Rectangle""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* rectText = new QGraphicsTextItem(QString("The block is the most common tool in the game. It can even be rotated, simply select" "\n"
                                                                "the object (through clicking on it) and push the arrow buttons '<-' & '->' to rotate the" "\n"
                                                                "object. Pressing the '->' button will lead to a clockwise rotation, and vise versa." "\n"
                                                                "To unselect the object just click elsewhere." "\n"
                                                                "To move the object click and hold on the object and drag it with your mouse."
                                                                ));
    QFont rectFont("comic sans", 18);
    rectText->setFont(rectFont);
    int rectxPos = 50;
    int rectyPos = 160;
    rectText->setPos(rectxPos,rectyPos);
    scene -> addItem(rectText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::circle()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    //Circle instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Circle""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* circleText = new QGraphicsTextItem(QString("The cirlce is a very similar to the block, but the rebounce behavior is different. It can" "\n"
                                                                  "not be rotated (since this would not be useful). To move the object click and hold on" "\n"
                                                                  "the object and drag it with your mouse."
                                                                ));
    QFont circleFont("comic sans", 18);
    circleText->setFont(circleFont);
    int circlexPos = 50;
    int circleyPos = 160;
    circleText->setPos(circlexPos,circleyPos);
    scene -> addItem(circleText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::triangle()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    //Triangle instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Triangle""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* triText = new QGraphicsTextItem(QString("The triangle is similar to the block, too. When placed correctly it might be very" "\n"
                                                               "useful to solve levels. It can be rotated, simply select the object (through" "\n"
                                                               "clicking on it) and push the arrow buttons '<-' & '->' to rotate the object." "\n"
                                                               "Pressing the '->' button will lead to a clockwise rotation, and vise versa." "\n"
                                                               "To unselect the object just click elsewhere. To move the object click and hold " "\n"
                                                               "on the object and drag it with your mouse."
                                                                ));
    QFont triFont("comic sans", 18);
    triText->setFont(triFont);
    int trixPos = 50;
    int triyPos = 160;
    triText->setPos(trixPos,triyPos);
    scene -> addItem(triText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::spring()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    //Spring instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Spring""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* springText = new QGraphicsTextItem(QString("The spring is a very useful and powerful tool. The spring is prestressed and triggers" "\n"
                                                                  "once the ball touches the surface of it. It will accelerate the paperball (within the" "\n"
                                                                  "physical boundaries of: angle of incidence equals angle of reflection). Once it is" "\n"
                                                                  "used it will not accelerate the ball again. To move the object click and hold on the" "\n"
                                                                  "object and drag it with your mouse."
                                                                ));
    QFont springFont("comic sans", 18);
    springText->setFont(springFont);
    int springxPos = 50;
    int springyPos = 160;
    springText->setPos(springxPos,springyPos);
    scene -> addItem(springText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::trampoline()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    //Trampoline instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Trampoline""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* trampText = new QGraphicsTextItem(QString("The trampolin is quite similar to the spring. The difference is, that the trampoline" "\n"
                                                                 "can be used multiple times, and it will not add power to the ball (e.g. If the ball" "\n"
                                                                 "drops from a certain heigth on the trampoline it will not reach the start value when" "\n"
                                                                 "reflected, due to friction losses etc.). To move the object click and hold on the" "\n"
                                                                 "object and drag it with your mouse."
                                                                ));
    QFont trampFont("comic sans", 18);
    trampText->setFont(trampFont);
    int trampxPos = 50;
    int trampyPos = 160;
    trampText->setPos(trampxPos,trampyPos);
    scene -> addItem(trampText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::conveyor()
{
    scene->clear();
    /*!create title text*/
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Help"));
    QFont titleFont("comic sans", 40);
    titleText->setFont(titleFont);
    int titlexPos = 50;
    int titleyPos = 30;
    titleText->setPos(titlexPos,titleyPos);
    scene->addItem(titleText);

    //Conveyor instruction
    QGraphicsTextItem* firstCap = new QGraphicsTextItem(QString("Conveyor""\n"));
    QFont firstCFont("comic sans", 26);
    firstCap->setFont(firstCFont);
    int firstCxPos = 50;
    int firstCyPos = 110;
    firstCap->setPos(firstCxPos,firstCyPos);
    scene -> addItem(firstCap);

    QGraphicsTextItem* conveyorText = new QGraphicsTextItem(QString("The conveyor is a very powerful tool, too. Once the paperball lands on it, the ball " "\n"
                                                                    "will be accelerated in the direction the conveyor is aiming at" "\n"
                                                                    "('<': left direction, '>': right direction). There are different models, which can" "\n"
                                                                    "be identified by '<<' '<' '>' '>>', which is written on the side of the tool." "\n"
                                                                    "Neither can it be rotated, nor can the direction be changed by the player."
                                                                ));
    QFont conveyorFont("comic sans", 18);
    conveyorText->setFont(conveyorFont);
    int conveyorxPos = 50;
    int conveyoryPos = 160;
    conveyorText->setPos(conveyorxPos,conveyoryPos);
    scene -> addItem(conveyorText);

    Button* backButton = new Button(QString("Back"));
    int backxPos = 50;
    int backyPos = 670;
    backButton->setPos(backxPos,backyPos);
    connect(backButton, SIGNAL(clicked()), this, SLOT(help()));
    scene->addItem(backButton);
}

void GUI::checkLevel(){
    QFile file("level.txt");
    if(file.exists()==true){
        file.open(QIODevice::ReadOnly |QIODevice::Text);

        while(!file.atEnd()){
            levelenab+=file.readLine();
        }
        qDebug()<< levelenab;
        file.close();
    }
}

