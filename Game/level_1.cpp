#include "level_1.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <qdebug.h>
#include <QFile>
#include <QTextStream>
#include "string"
#include "gui.h"
#include <QtWidgets>


using namespace std;

/*!
 * \brief Level_1::Level_1
 * \param parent
 *  Initialize Level1 - Screen/Scene Setup...
 */
Level_1::Level_1()
{
    /*!Set Application-Name*/
    setWindowTitle(tr("Hole in One - Level 1"));

    //Screen setup. No scroll bar available
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    timer2=new QTimer(this);
    timer2->setInterval(1.0/120.0*1000.0);

    timer2->start();

    //Scene setup
    level = new QGraphicsScene();
    level->setSceneRect(0,0,1024,768);
    setScene(level);
    showLevel();
}


/*!
 * \brief Level_1::update
 * update function for moveable objects like our ball - sets the graphics of the ball to the position
 * of the box2D body.
 */
void Level_1::update(){
    myWorld->Step(framerate, 20, 20);
    win = ball->drawBall1(); //nur bewegende Elemente in Update
    // qDebug()<<recyclebin1->body->GetPosition().x<<recyclebin1->body->GetPosition().y;
	
        if (win==true){
        Level_1::pauseLevel();

        msgbox = new MeinElement(level,QPointF(375,275),300,210);

        QGraphicsTextItem * winText = new QGraphicsTextItem;
        winText->setPos(400,300);
        winText->setPlainText("You have finished Level 1!");
        level->addItem(winText);
        saveLevel();
        if(newhighscore){
            QGraphicsTextItem* highscoretext=new QGraphicsTextItem();
            highscoretext->setPos(400,350);
            highscoretext->setPlainText("New Highscore!!");
            level->addItem(highscoretext);

        }
        QGraphicsTextItem * timeText = new QGraphicsTextItem;
        timeText->setPos(400,400);

        QString time = QString("Time: %3 s").arg(leveltime);
        timeText->setPlainText( time);
        level->addItem(timeText);
        QPushButton* quitLevel = new QPushButton("Quit");
        quitLevel->move(400,440);
        level->addWidget(quitLevel);
        connect(quitLevel, SIGNAL(clicked()),this,SLOT(closeLevel()));

    }
}

void Level_1::closeLevel(){
    emit levelcompleted();
    this->close();
}

/*!
 * \brief Level_1::startLevel
 * Set the flag of the QGraphicsItem, after start was clicked.
 * draw the graphics if the body was moved before start was clicked.
 */
void Level_1::startLevel(){


	recyclebin1->drawGraphics();
    recyclebin2->drawGraphics();
    //obstaclesrec1->drawGraphics();
    obstaclescircle1->drawGraphics();
    obstaclescircle2->drawGraphics();
    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    recyclebin1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    recyclebin2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);


    if(counterRec==1){
        addblock1->drawGraphics();
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterRec==2){
        addblock1->drawGraphics();
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        addblock2->drawGraphics();
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterRec==3){
        addblock1->drawGraphics();
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        addblock2->drawGraphics();
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock2->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        addblock3->drawGraphics();
        addblock3->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addblock3->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterCircle==1){
        addcircle1->drawGraphics();
        addcircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==2){
        addcircle1->drawGraphics();
        addcircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addcircle2->drawGraphics();
        addcircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==3){
        addcircle1->drawGraphics();
        addcircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addcircle2->drawGraphics();
        addcircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        addcircle3->drawGraphics();
        addcircle3->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }


    timer=new QTimer(this);
    timer->setInterval(1.0/120.0*1000.0);
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);
    bt__rect->setEnabled(false);
    bt__circle->setEnabled(false);

    leveltime_elapsed.start();
}

/*!
 * \brief Level_1::pauseLevel
 * pauses game when button pause is clicked
 */
void Level_1::pauseLevel(){
    if(leveltime_elapsed.elapsed()>0.0){
         timer->stop();
    }
    Level_1::getTime();
    Level_1::highscoreCounter();
    bt_pause->setEnabled(false);
    bt__resume->setEnabled(true);
    bt_start->setEnabled(false);

}
/*!
 * \brief Level_1::resumeLevel
 * resumes game when button resume is clicked
 */
void Level_1::resumeLevel()
{
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);
}

/*!
 * \brief Level_1::addRectangle
 * Create new rectangle and count the rectangle items. limited to number.
 */
void Level_1::addRectangle()
{
    counterRec++;
    switch(counterCircle){
    case 1:
        addcircle1->graphics->setSelected(false);
        break;
    case 2:
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(false);
        break;
    case 3:
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(false);
        addcircle3->graphics->setSelected(false);
        break;

    }

    if (counterRec==1){
        addblock1 = new Block(myWorld, level, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");
        addblock1->graphics->setSelected(true);
        bt__rect->sethoverpic(QPixmap(":/images/images/rec2hover.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec2default.png"));

    }

    else if(counterRec==2){
        addblock2 = new Block(myWorld, level, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");
        addblock2->graphics->setSelected(true);
        addblock1->graphics->setSelected(false);
        bt__rect->sethoverpic(QPixmap(":/images/images/rec1hover.png"));
       bt__rect->setdefaultpic(QPixmap(":/images/images/rec1default.png"));

    }

    else if(counterRec==3){
        addblock3 = new Block(myWorld, level, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");
        addblock3->graphics->setSelected(true);
        addblock1->graphics->setSelected(false);
        addblock2->graphics->setSelected(false);
        bt__rect->sethoverpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setEnabled(false);

    }

}
/*!
 * \brief Level_1::addCircle
 * create new circle and count the circle items. limited to number.
 */
void Level_1::addCircle(){
    counterCircle++;

    b2CircleShape circle;
    switch(counterRec){
    case 1:
        addblock1->graphics->setSelected(false);
        break;
    case 2:
        addblock1->graphics->setSelected(false);
        addblock2->graphics->setSelected(false);
        break;
    case 3:
        addblock1->graphics->setSelected(false);
        addblock2->graphics->setSelected(false);
        addblock3->graphics->setSelected(false);
        break;

    }
    if(counterCircle==1){
        circle.m_radius = 21.0;
        addcircle1 = new Circle(myWorld, level, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");
        addcircle1->graphics->setSelected(true);
        bt__circle->sethoverpic(QPixmap(":/images/images/circ2hover.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circ2default.png"));

        addcircle1->draw();

    }

    if(counterCircle==2){
        circle.m_radius = 21.0;
        addcircle2 = new Circle(myWorld, level, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(true);
        bt__circle->sethoverpic(QPixmap(":/images/images/circle1hover.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circle1default.png"));

        addcircle2->draw();

    }

    if(counterCircle==3){
        circle.m_radius = 21.0;
        addcircle3 = new Circle(myWorld, level, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");
        addcircle1->graphics->setSelected(false);
        addcircle2->graphics->setSelected(false);
        addcircle3->graphics->setSelected(true);
        bt__circle->sethoverpic(QPixmap(":/images/images/circ0.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circ0.png"));

        addcircle3->draw();


        bt__circle->setEnabled(false);

    }

}

/*!
 * \brief Level_1::getTime
 * Stop time and convert it to ms.
 */
void Level_1::getTime(){
    leveltime = leveltime_elapsed.elapsed(); //leveltime in msec
    leveltime = ((double)((long)(leveltime)))/1000; //leveltime in sec
}

/*!
 * \brief Level_1::highscoreCounter
 * Calculate the highscore.
 */
void Level_1::highscoreCounter(){

    counterTogether = counterRec + counterCircle;

    if (counterTogether==6){
        highscore = 1;
    }
    else if (counterTogether==5){
        highscore = 2;
    }
    else if (counterTogether==4){
        highscore = 3;
    }
    else if (counterTogether==3){
        highscore = 4;
    }
    else if (counterTogether==2){
        highscore = 5;
    }
    else if (counterTogether==1){
        highscore = 6;
    }
    else if (counterTogether==0){
        highscore = 7;
    }
    qDebug()<<counterTogether;
    highscore=highscore/leveltime*3000;
    qDebug()<<highscore;
}

/*!
 * \brief Level_1::reset
 * Clear scene and load Level again.
 */
void Level_1::reset(){
   pauseLevel();

   level->clear();
   counterRec = 0;
   counterCircle = 0;
   
   showLevel();
}



/*!
 * \brief Level_1::quitLevel
 * quits game and writes time/score into highscore table
 */
void Level_1::saveLevel()
{

    QFile file("level.txt");
    file.open(QIODevice::ReadWrite |QIODevice::Text);
    if(file.exists("level.txt")){

        levelenab.clear();
        while(!file.atEnd()){
            levelenab.append(file.readLine());
        }
       file.resize(0);

    }

    if(levelenab.size()>0){
        if(levelenab.at(7).toInt()<highscore){
                levelenab.replace(1,"true\n");
                levelenab.replace(5,QString::number(leveltime)+" s\n");
                levelenab.replace(6,QString::number(counterTogether)+"\n");
                levelenab.replace(7,QString::number(highscore)+"\n");
                newhighscore=true;
            }else if(levelenab.at(7).toInt()==highscore){
                 QStringList timescortest=levelenab.at(5).split(" ");
                 if(timescortest.at(0).toDouble()>leveltime){
                     levelenab.replace(1,"true\n");
                     levelenab.replace(5,QString::number(leveltime)+" s\n");
                     levelenab.replace(6,QString::number(counterTogether)+"\n");
                     levelenab.replace(7,QString::number(highscore)+"\n");
                     newhighscore=true;
            } else{
                newhighscore=false;
            }
        }else{
            newhighscore=false;
        }

    }
    else{
        levelenab.insert(0,"true\n");
        levelenab.insert(1,"true\n");
        levelenab.insert(2,"false\n");
        levelenab.insert(3,"false\n");
        levelenab.insert(4,"Highscore\n");
        levelenab.insert(5,QString::number(leveltime)+" s\n");
        levelenab.insert(6,QString::number(counterTogether)+"\n");
        levelenab.insert(7,QString::number(highscore)+"\n");
        newhighscore=true;
    }

    QTextStream out(&file);
    foreach (QString data, levelenab) {
        out<<data;
    }


    file.close();


}

/*!
 * \brief Level_1::showLevel
 * Create all Objects for Level 1.
 * Connect Buttons with SLOT.
 */
void Level_1::showLevel(){
    //set Background Image

     QPixmap background(":/pic/Game_background_tut.png");
     background.scaled(QSize(1021,766));
     backgnd = level->addPixmap(background);
     backgnd->setPos(0,0); //Set Graphic to top left corner
     backgnd->setFlag(QGraphicsItem::ItemIsMovable, false);


     //Start Button
     bt_start=new picButton(QPixmap(":/images/images/startdefault.png"), QPixmap(":/images/images/starthover.png"));
     bt_start->move(726.0,640.0);
     connect(bt_start,SIGNAL(clicked()),this,SLOT(startLevel()), Qt::QueuedConnection);
     level->addWidget(bt_start);

     //Pause Button
     bt_pause=new picButton(QPixmap(":/images/images/pauseenabled.png"), QPixmap(":/images/images/pausehover.png"));
     bt_pause->setEnabled(false);
     bt_pause->move(865.0,640.0);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(getTime()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(highscoreCounter()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(pauseLevel()),Qt::QueuedConnection);
     level->addWidget(bt_pause);

     //Resume Button
     bt__resume=new picButton(QPixmap(":/images/images/resumeenabled.png"), QPixmap(":/images/images/resumehover.png"));
     bt__resume->setEnabled(false);
     bt__resume->move(726.0, 685.0);
     connect(bt__resume,SIGNAL(clicked()),this,SLOT(resumeLevel()));
     level->addWidget(bt__resume);

     //Reset
     bt__reset=new picButton(QPixmap(":/images/images/resetenabled.png"), QPixmap(":/images/images/resethover.png"));
     bt__reset->setEnabled(true);
     bt__reset->move(865.0, 685.0);
     connect(bt__reset, SIGNAL(clicked()), this, SLOT(reset()), Qt::QueuedConnection);
     level->addWidget(bt__reset);

     //Rect Button
     bt__rect=new picButton(QPixmap(":/images/images/rec3defualt.png"), QPixmap(":/images/images/rec3hover.png"));
     bt__rect->setEnabled(true);
     bt__rect->move(219.0,640.0);
     connect(bt__rect,SIGNAL(clicked()),this,SLOT(addRectangle()), Qt::QueuedConnection);
     level->addWidget(bt__rect);

     //Circle Button
     bt__circle=new picButton(QPixmap(":/images/images/circ3default.png"), QPixmap(":/images/images/circ3hover.png"));
     bt__circle->setEnabled(true);
     bt__circle->move(378.0,640.0);
     connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()), Qt::QueuedConnection);
     level->addWidget(bt__circle);

     //Triangle Button
     bt__triangle=new picButton(QPixmap(":/images/images/tri0.png"), QPixmap(":/images/images/tri0.png"));
     bt__triangle->setEnabled(false);
     bt__triangle->move(537.0,640.0);
     //connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()), Qt::QueuedConnection);
     level->addWidget(bt__triangle);

     //Rotate Left
     bt__left=new picButton(QPixmap(":/images/images/rotleftdefault.png"), QPixmap(":/images/images/rotlefthover.png"));
     bt__left->setEnabled(true);
     bt__left->move(30.0,654.0);
     bt__left->setShortcut(Qt::Key_Left);
     connect(bt__left,SIGNAL(clicked()),this,SLOT(rotateLeft()), Qt::QueuedConnection);
     level->addWidget(bt__left);

     //Rotate Right
     bt__right=new picButton(QPixmap(":/images/images/rotrightdefault.png"), QPixmap(":/images/images/rotrighthover.png"));
     bt__right->setEnabled(true);
     bt__right->move(30.0,699.0);
     bt__right->setShortcut(Qt::Key_Right);
     connect(bt__right,SIGNAL(clicked()),this,SLOT(rotateRight()), Qt::QueuedConnection);
     level->addWidget(bt__right);

     //Levelmenue
     bt_levelmenue=new picButton(QPixmap(":/images/images/levelmenue_bt.png"), QPixmap(":/images/images/levelmenue_hover.png"));
     bt_levelmenue->setEnabled(true);
     bt_levelmenue->move(30.0,609.0);
     connect(bt_levelmenue,SIGNAL(clicked()),this,SLOT(closeLevel()), Qt::QueuedConnection);
     level->addWidget(bt_levelmenue);

     b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!

     myWorld = new b2World(gravity);

     float32 timeStep = 1.0/100.0;     //the length of time passed to simulate (seconds)
     int32 velocityIterations = 8.0;   //how strongly to correct velocity
     int32 positionIterations = 3.0;   //how strongly to correct position

     myWorld->Step(timeStep, velocityIterations, positionIterations);

     b2CircleShape circle;
     circle.m_radius = 21.0;

     //Outer borders
     umrandung1 = new MeinElement(myWorld,level, b2Vec2 (-30.0,0.0), 10, 1024, b2_staticBody, 1.0);
     umrandung2 = new MeinElement(myWorld,level, b2Vec2 (1002.0,0.0), 0, 1024, b2_staticBody, 1.0);
     bottom= new MeinElement(myWorld, level, b2Vec2(0.0,level->height()-200), level->width(), 22, b2_staticBody, 0.1);

     // game Objects
     ball  = new Paperball(myWorld, level, QPointF(520.0,440.0), 0*(3.14/180.0), b2_dynamicBody, circle);

     recyclebin1 = new RecycleBin(myWorld, level, QPointF(500,508),QPointF(510,508),QPointF(530,568),QPointF(520,568), 0.0, b2_staticBody);
     recyclebin2 = new RecycleBin(myWorld, level, QPointF(550,568),QPointF(570,508),QPointF(580,508),QPointF(560,568), 0.0, b2_staticBody);
     recyclebin3 = new RecycleBinGraphics(level);

     obstaclescircle1 = new Circle(myWorld, level, QPointF(0.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle2 = new Circle(myWorld, level, QPointF(40.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle3 = new Circle(myWorld, level, QPointF(85.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle4 = new Circle(myWorld, level, QPointF(160.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle5 = new Circle(myWorld, level, QPointF(200.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle6 = new Circle(myWorld, level, QPointF(279.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle7 = new Circle(myWorld, level, QPointF(450.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle8 = new Circle(myWorld, level, QPointF(650.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle9 = new Circle(myWorld, level, QPointF(20.0,493.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle10 = new Circle(myWorld, level, QPointF(0.0,459.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle11 = new Circle(myWorld, level, QPointF(61.0,490.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle12 = new Circle(myWorld, level, QPointF(122.0,512.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle13 = new Circle(myWorld, level, QPointF(239.0,512.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle14 = new Circle(myWorld, level, QPointF(37.0,457.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle15 = new Circle(myWorld, level, QPointF(92.0,464.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle16 = new Circle(myWorld, level, QPointF(969.0,526.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle17 = new Circle(myWorld, level, QPointF(985.0,487.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");

     obstaclesrec1=new Block(myWorld,level,b2Vec2(469,350),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec2=new Block(myWorld,level,b2Vec2(369,350),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec3=new Block(myWorld,level,b2Vec2(269,350),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec4=new Block(myWorld,level,b2Vec2(569,350),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec5=new Block(myWorld,level,b2Vec2(669,350),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec6=new Block(myWorld,level,b2Vec2(769,446),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec7=new Block(myWorld,level,b2Vec2(869,426),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec8=new Block(myWorld,level,b2Vec2(163,470),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec9=new Block(myWorld,level,b2Vec2(263,470),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec10=new Block(myWorld,level,b2Vec2(799,527),0,100,40,b2_staticBody,1.0,"obs");
     obstaclesrec10=new Block(myWorld,level,b2Vec2(356,527),0,100,40,b2_staticBody,1.0,"obs");

     //so that ball is not moveable like the other objects
     ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);

     ball->drawBall1();

     bottom->drawBottom();
     umrandung1->graphics->hide();
     umrandung2->graphics->hide();
}


/*!
 * \brief Level_1::rotateLeft
 * possibility to rotate objects to the left
 */
void Level_1::rotateLeft(){


    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
        }
       if(addblock2->graphics->isSelected()){
           qreal angle=addblock2->angle-0.5235;
           //QPointF pos=addblock2->graphics->pos();
           qreal degreeangle=angle*180/3.1415;
           level->removeItem(addblock2->graphics);
           addblock2->body->GetWorld()->DestroyBody(addblock2->body);
           addblock2 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
           addblock2->graphics->setRotation(degreeangle);
           addblock2->graphics->setSelected(true);
        }
    }

    if(counterRec==3){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
            //QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle-0.5235;
           // QPointF pos=elem5->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock2->graphics);
            addblock2->body->GetWorld()->DestroyBody(addblock2->body);
            addblock2 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
            addblock2->graphics->setSelected(true);
        }
        if(addblock3->graphics->isSelected()){
            qreal angle=addblock3->angle-0.5235;
            //QPointF pos=elem6->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock3->graphics);
            addblock3->body->GetWorld()->DestroyBody(addblock3->body);
            addblock3 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock3->graphics->setRotation(degreeangle);
            addblock3->graphics->setSelected(true);
        }
    }
}
/*!
 * \brief Level_1::rotateRight
 * possibility to rotate right
 */
void Level_1::rotateRight(){

    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
            //QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle+0.5235;
            //QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock2->graphics);
            addblock2->body->GetWorld()->DestroyBody(addblock2->body);
            addblock2 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
            addblock2->graphics->setSelected(true);
        }
    }

    if(counterRec==3){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock1->graphics);
            addblock1->body->GetWorld()->DestroyBody(addblock1->body);
            addblock1 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
            addblock1->graphics->setSelected(true);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle+0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level->removeItem(addblock2->graphics);
            addblock2->body->GetWorld()->DestroyBody(addblock2->body);
            addblock2 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
            addblock2->graphics->setSelected(true);
        }
       if(addblock3->graphics->isSelected()){
           qreal angle=addblock3->angle+0.5235;
           //QPointF pos=addblock3->graphics->pos();
           qreal degreeangle=angle*180/3.1415;
           level->removeItem(addblock3->graphics);
           addblock3->body->GetWorld()->DestroyBody(addblock3->body);
           addblock3 =new Block(myWorld, level, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
           addblock3->graphics->setRotation(degreeangle);
           addblock3->graphics->setSelected(true);
        }
    }


}







