#include "level_2.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <qdebug.h>
#include <QFile>
#include <QTextStream>
#include "string"
#include "trampoline.h"

using namespace std;

/*!
 * \brief Level_2::Level_2
 * Initialize Level1 - Screen/Scene Setup...
 */
Level_2::Level_2()
{
    /*!Set Application-Name*/
    setWindowTitle(tr("Hole in One - Level 2"));

    //Screen setup. No scroll bar available
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    //Scene setup
    level2 = new QGraphicsScene();
    level2->setSceneRect(0,0,1024,768);
    setScene(level2);

    showLevel();
}

/*!
 * \brief Level_2::update
 * update function for moveable objects like our ball - sets the graphics of the ball to the position
 * of the box2D body.
 */
void Level_2::update(){
    myWorld2->Step(framerate, 20, 20);

    win = ball->drawBall1(); //nur bewegende Elemente in Update

        if (win==true){
        Level_2::pauseLevel();

        msgbox = new MeinElement(level2,QPointF(375,275),300,175);

        QGraphicsTextItem * winText = new QGraphicsTextItem;
        winText->setPos(400,300);
        winText->setPlainText("You have finished Level 2!");
        level2->addItem(winText);
        saveLevel();
        if(newhighscore){
            QGraphicsTextItem* highscoretext=new QGraphicsTextItem();
            highscoretext->setPos(400,350);
            highscoretext->setPlainText("New Highscore!!");
            level2->addItem(highscoretext);

        }
        QGraphicsTextItem * timeText = new QGraphicsTextItem;
        timeText->setPos(400,400);
        QString time = QString("Time: %1 s").arg(leveltime);
        timeText->setPlainText( time);
        level2->addItem(timeText);
        QPushButton* quitLevel = new QPushButton("Quit");
        quitLevel->move(400,440);
        level2->addWidget(quitLevel);
        connect(quitLevel, SIGNAL(clicked()),this,SLOT(close()));
    }

}

/*!
 * \brief Level_2::startLevel
 * Set the flag of the QGraphicsItem, after start was clicked.
 * draw the graphics if the body was moved before start was clicked.
 */
void Level_2::startLevel(){

    recyclebin1->drawGraphics();
    recyclebin1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    recyclebin2->drawGraphics();
    recyclebin2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->drawGraphics();
    //obstaclesrec1->drawGraphics();

    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    //obstaclescircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    //obstaclescircle2->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);


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

    if(counterTriangle==1){
        if(addtriangle1!=NULL){
           addtriangle1->drawGraphics();
           addtriangle1->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
    }
    if(counterTriangle==2){

        if(addtriangle1!=NULL){
           addtriangle1->drawGraphics();
           addtriangle1->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
        if(addtriangle2!=NULL){
           addtriangle2->drawGraphics();
           addtriangle2->graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
           }
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
 * \brief Level_2::pauseLevel
 * pauses game when button pause is clicked
 */
void Level_2::pauseLevel(){
    if(timer!=NULL){
        timer->stop();
    }
    Level_2::getTime();
    Level_2::highscoreCounter();
    bt_pause->setEnabled(false);
    bt__resume->setEnabled(true);
    bt_start->setEnabled(false);

    qDebug()<<"Level paused";
    qDebug()<<leveltime_elapsed.elapsed()<<"milliseconds";
    //qDebug()<<leveltime;
    //qDebug()<<highscore;
}

/*!
 * \brief Level_2::resumeLevel
 * resumes game when button resume is clicked
 */
void Level_2::resumeLevel()
{
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);

}

/*!
 * \brief Level_2::addRectangle
 * Create new rectangle and count the rectangle items. limited to number.
 */
void Level_2::addRectangle()
{
    counterRec++;


    if (counterRec==1){
        addblock1 = new Block(myWorld2, level2, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");

        bt__rect->sethoverpic(QPixmap(":/images/images/rec1hover.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec1default.png"));


    }

    else if(counterRec==2){
        addblock2 = new Block(myWorld2, level2, b2Vec2 (50.0,20.0), 0, 100, 40, b2_staticBody,1.0,"tool");

        bt__rect->sethoverpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setdefaultpic(QPixmap(":/images/images/rec0.png"));
        bt__rect->setEnabled(false);

    }

}

/*!
 * \brief Level_2::addCircle
 * Create new Circle and count the circle items. Limited to number.
 */

void Level_2::addCircle(){
    counterCircle++;

    b2CircleShape circle;

    if(counterCircle==1){
        circle.m_radius = 21.0;
        addcircle1 = new Circle(myWorld2, level2, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");

        bt__circle->sethoverpic(QPixmap(":/images/images/circle1hover.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circle1default.png"));

        addcircle1->draw();

    }

    if(counterCircle==2){
        circle.m_radius = 21.0;
        addcircle2 = new Circle(myWorld2, level2, QPointF(0.0,0.0), 0*(3.14/180.0), b2_staticBody, circle,"tool");

        bt__circle->sethoverpic(QPixmap(":/images/images/circ0.png"));
        bt__circle->setdefaultpic(QPixmap(":/images/images/circ0.png"));
        bt__circle->setEnabled(false);
        addcircle2->draw();

    }

}

/*!
 * \brief Level_2::addTriangle
 * Create new Triangle and count the triangle items. Limited to number.
 */
void Level_2::addTriangle()
{
    counterTriangle++;

    if(counterTriangle==1){
        addtriangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0), 0, b2_staticBody, 1.0,"tool");

        bt__triangle->sethoverpic(QPixmap(":/images/images/tri1hover.png"));
        bt__triangle->setdefaultpic(QPixmap(":/images/images/tri1default.png"));
        addtriangle1->draw();


    }

    if(counterTriangle==2){
        addtriangle2 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0), 0, b2_staticBody, 1.0,"tool");

        bt__triangle->sethoverpic(QPixmap(":/images/images/tri0.png"));
        bt__triangle->setdefaultpic(QPixmap(":/images/images/tri0.png"));

        bt__triangle->setEnabled(false);
        addtriangle2->draw();

    }

}

/*!
 * \brief Level_2::getTime
 * Stop time and convert it to ms.
 */
void Level_2::getTime(){
    leveltime = leveltime_elapsed.elapsed(); //leveltime in msec
    leveltime = leveltime/1000; //leveltime in sec
}

/*!
 * \brief Level_2::highscoreCounter
 * Calculate the highscore.
 */
void Level_2::highscoreCounter(){

    counterTogether = counterRec + counterCircle;

    if ( (counterTogether==6)||(counterTogether==5) ){
        highscore = 1;
    }

    else if( (counterTogether==4)||(counterTogether==3) ){
        highscore = 2;
    }

    else if( (counterTogether==1)||(counterTogether==2)||(counterTogether==0) ){
        highscore = 3;
    }

    if ( (leveltime>=30) ){
        highscore = highscore*1;
    }

    else if( (leveltime<30)&&(leveltime>=15) ){
        highscore = highscore*2;
    }

    else if( (leveltime<15)&&(leveltime>=0) ){
        highscore = highscore*3;
    }

    highscore=highscore*100;

}

/*!
 * \brief Level_2::reset
 * Clear scene and load Level again.
 */
void Level_2::reset(){
    pauseLevel();
   level2->clear();
   counterRec = 0;
   counterCircle = 0;
   counterTriangle = 0;

   showLevel();

}

/*!
 * \brief Level_2::quitLevel
 * quits game and writes time/score into highscore table
 */
void Level_2::saveLevel()
{
    QList <QString> levelenab;
    QFile file("level.txt");
    file.open(QIODevice::ReadWrite |QIODevice::Text);
    if(file.exists("level.txt")){

        levelenab.clear();
        while(!file.atEnd()){
            levelenab.append(file.readLine());
        }
       file.resize(0);

    }

    if(levelenab.size()>8){
        if(levelenab.at(10).toInt()<highscore){
            levelenab.replace(2,"true\n");
            levelenab.replace(8,QString::number(leveltime)+" s\n");
            levelenab.replace(9,QString::number(counterTogether)+"\n");
            levelenab.replace(10,QString::number(highscore)+"\n");
            newhighscore=true;
        }else{
            newhighscore=false;
        }

    }else{
        levelenab.replace(2,"true\n");
        levelenab.insert(8,QString::number(leveltime)+" s\n");
        levelenab.insert(9,QString::number(counterTogether)+"\n");
        levelenab.insert(10,QString::number(highscore)+"\n");
        newhighscore=true;
    }


    QTextStream out(&file);
    foreach (QString data, levelenab) {
        out<<data;
    }


    file.close();

}

/*!
 * \brief Level_2::showLevel
 * Create all Objects for Level 1.
 * Connect Buttons with SLOT.
 */
void Level_2::showLevel(){

     //set Background Image
     QPixmap background(":/pic/Game_background_spwn.png");
     background.scaled(QSize(1021,766));
     backgnd = level2->addPixmap(background);
     backgnd->setPos(0,0); //Set Graphic to top left corner
     backgnd->setFlag(QGraphicsItem::ItemIsMovable, false);

     //Start Button
     bt_start=new picButton(QPixmap(":/images/images/startdefault.png"), QPixmap(":/images/images/starthover.png"));
     bt_start->move(726.0,640.0);
     connect(bt_start,SIGNAL(clicked()),this,SLOT(startLevel()), Qt::QueuedConnection);
     level2->addWidget(bt_start);

     //Pause Button
     bt_pause=new picButton(QPixmap(":/images/images/pauseenabled.png"), QPixmap(":/images/images/pausehover.png"));
     bt_pause->setEnabled(false);
     bt_pause->move(865.0,640.0);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(getTime()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(highscoreCounter()),Qt::QueuedConnection);
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(pauseLevel()),Qt::QueuedConnection);
     level2->addWidget(bt_pause);

     //Resume Button
     bt__resume=new picButton(QPixmap(":/images/images/resumeenabled.png"), QPixmap(":/images/images/resumehover.png"));
     bt__resume->setEnabled(false);
     bt__resume->move(726.0, 685.0);
     connect(bt__resume,SIGNAL(clicked()),this,SLOT(resumeLevel()));
     level2->addWidget(bt__resume);

     //Reset
     bt__reset=new picButton(QPixmap(":/images/images/resetenabled.png"), QPixmap(":/images/images/resethover.png"));
     bt__reset->setEnabled(true);
     bt__reset->move(865.0, 685.0);
     connect(bt__reset, SIGNAL(clicked()), this, SLOT(reset()), Qt::QueuedConnection);
     level2->addWidget(bt__reset);

     //Rect Button
     bt__rect=new picButton(QPixmap(":/images/images/rec2default.png"), QPixmap(":/images/images/rec2hover.png"));
     bt__rect->setEnabled(true);
     bt__rect->move(219.0,640.0);
     connect(bt__rect,SIGNAL(clicked()),this,SLOT(addRectangle()), Qt::QueuedConnection);
     level2->addWidget(bt__rect);

     //Circle Button
     bt__circle=new picButton(QPixmap(":/images/images/circ2default.png"), QPixmap(":/images/images/circ2hover.png"));
     bt__circle->setEnabled(true);
     bt__circle->move(378.0,640.0);
     connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()), Qt::QueuedConnection);
     level2->addWidget(bt__circle);

     //Triangle Button
     bt__triangle=new picButton(QPixmap(":/images/images/tri2default.png"), QPixmap(":/images/images/tri2hover.png"));
     bt__triangle->setEnabled(true);
     bt__triangle->move(537.0,640.0);
     connect(bt__triangle,SIGNAL(clicked()),this,SLOT(addTriangle()), Qt::QueuedConnection);
     level2->addWidget(bt__triangle);

     //Rotate Left
     bt__left=new picButton(QPixmap(":/images/images/rotleftdefault.png"), QPixmap(":/images/images/rotlefthover.png"));
     bt__left->setEnabled(true);
     bt__left->move(30.0,640.0);
     connect(bt__left,SIGNAL(clicked()),this,SLOT(rotateLeft()), Qt::QueuedConnection);
     level2->addWidget(bt__left);

     //Rotate Right
     bt__right=new picButton(QPixmap(":/images/images/rotrightdefault.png"), QPixmap(":/images/images/rotrighthover.png"));
     bt__right->setEnabled(true);
     bt__right->move(30.0,685.0);
     connect(bt__right,SIGNAL(clicked()),this,SLOT(rotateRight()), Qt::QueuedConnection);
     level2->addWidget(bt__right);


     b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!
     myWorld2 = new b2World(gravity);

     float32 timeStep = 1.0/100.0;     //the length of time passed to simulate (seconds)
     int32 velocityIterations = 8.0;   //how strongly to correct velocity
     int32 positionIterations = 3.0;   //how strongly to correct position

     myWorld2->Step(timeStep, velocityIterations, positionIterations);

     b2CircleShape circle;
     circle.m_radius = 21.0;

     umrandung1 = new MeinElement(myWorld2,level2, b2Vec2 (-30.0,0.0), 10, 1024, b2_staticBody, 1.0);
     umrandung2 = new MeinElement(myWorld2,level2, b2Vec2 (1002.0,0.0), 0, 1024, b2_staticBody, 1.0);

     ball  = new Paperball(myWorld2, level2, QPointF(540.0,20.0), 0*(3.14/180.0), b2_dynamicBody, circle);

     obstaclescircle1 = new Circle(myWorld2, level2, QPointF(0.0,547), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle2 = new Circle(myWorld2, level2, QPointF(42.0,505), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle3 = new Circle(myWorld2, level2, QPointF(84.0,463), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle4 = new Circle(myWorld2, level2, QPointF(128.0,421), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle5 = new Circle(myWorld2, level2, QPointF(170.0,379), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle6 = new Circle(myWorld2, level2, QPointF(212.0,337), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle7 = new Circle(myWorld2, level2, QPointF(256.0,295), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle8 = new Circle(myWorld2, level2, QPointF(212.0,337), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle9 = new Circle(myWorld2, level2, QPointF(256.0,295), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle10 = new Circle(myWorld2, level2, QPointF(298.0,253), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle11 = new Circle(myWorld2, level2, QPointF(340.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle12 = new Circle(myWorld2, level2, QPointF(382.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle13 = new Circle(myWorld2, level2, QPointF(424.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle14 = new Circle(myWorld2, level2, QPointF(466.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle23 = new Circle(myWorld2, level2, QPointF(508.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle24 = new Circle(myWorld2, level2, QPointF(550.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle25 = new Circle(myWorld2, level2, QPointF(592.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle26 = new Circle(myWorld2, level2, QPointF(634.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle29 = new Circle(myWorld2, level2, QPointF(676.0,211), 0*(3.14/180.0), b2_staticBody, circle,"obs");

     obstaclescircle15 = new Circle(myWorld2, level2, QPointF(982.0,547.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle16 = new Circle(myWorld2, level2, QPointF(940.0,505), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle17 = new Circle(myWorld2, level2, QPointF(898.0,463), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle18 = new Circle(myWorld2, level2, QPointF(856.0,421), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle19 = new Circle(myWorld2, level2, QPointF(814.0,379), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle20 = new Circle(myWorld2, level2, QPointF(212.0,337), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle21 = new Circle(myWorld2, level2, QPointF(256.0,295), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle22 = new Circle(myWorld2, level2, QPointF(982.0,547.0), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle23 = new Circle(myWorld2, level2, QPointF(940.0,505), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle24 = new Circle(myWorld2, level2, QPointF(898.0,463), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle25 = new Circle(myWorld2, level2, QPointF(856.0,421), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle26 = new Circle(myWorld2, level2, QPointF(814.0,379), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle27 = new Circle(myWorld2, level2, QPointF(772.0,337), 0*(3.14/180.0), b2_staticBody, circle,"obs");
     obstaclescircle28 = new Circle(myWorld2, level2, QPointF(730.0,295), 0*(3.14/180.0), b2_staticBody, circle,"obs");

     obstaclesrec1=new Block(myWorld2,level2,b2Vec2(530,380),0,100,40,b2_staticBody,1.0,"obs");


     trampoline = new Trampoline(myWorld2,level2,b2Vec2(650,525),0,100,40,b2_staticBody,1.0,"obs");
     recyclebin1 = new RecycleBin(myWorld2, level2, QPointF(500,508),QPointF(510,508),QPointF(530,568),QPointF(520,568), 0.0, b2_staticBody);
     recyclebin2 = new RecycleBin(myWorld2, level2, QPointF(550,568),QPointF(570,508),QPointF(580,508),QPointF(560,568), 0.0, b2_staticBody);
     recyclebin3 = new RecycleBinGraphics(level2);

     bottom= new MeinElement(myWorld2, level2, b2Vec2(0.0,level2->height()-200), level2->width(), 22, b2_staticBody, 0.1);

     ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);

     obstaclescircle1->draw(); //Static Elemente lassen sich auch hier "drawn"
     //obstaclescircle2->draw();

     ball->drawBall1();

     bottom->drawBottom();
     umrandung1->graphics->hide();
     umrandung2->graphics->hide();

}

/*!
 * \brief Level_2::rotateLeft
 * possibility to rotate objects to the left
 */
void Level_2::rotateLeft(){
    qreal angle;
    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock1->graphics);
            addblock1 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle-0.5235;
           // QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock1->graphics);
            addblock1 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle-0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock2->graphics);
            addblock2 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
        }

    }
    if(counterTriangle==1){
        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1--;

            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }
            else if(counterTriangleangle1==0){
                angle=0;
            }

            level2->removeItem(addtriangle1->graphics);
            addtriangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
        }
    }

    if(counterTriangle==2){


        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1--;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level2->removeItem(addtriangle1->graphics);
            addtriangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");

        }else if(addtriangle2->graphics->isSelected()){
            counterTriangleangle2--;
            if(abs(counterTriangleangle2)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle2)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle2)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle2)==4){
                angle=0;
                counterTriangleangle2=0;
            }
            else if(counterTriangleangle1==0){
                angle=0;
             }

            level2->removeItem(addtriangle2->graphics);
            addtriangle2 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");

       }
    }
}

/*!
 * \brief Level_2::rotateRight
 * possibility to rotate right
 */
void Level_2::rotateRight(){
    qreal angle;
    if(counterRec==1){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
            //QPointF pos=addblock1->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock1->graphics);
            addblock1 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
        }
    }
    if(counterRec==2){
        if(addblock1->graphics->isSelected()){
            qreal angle=addblock1->angle+0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock1->graphics);
            addblock1 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock1->graphics->setRotation(degreeangle);
        }
        if(addblock2->graphics->isSelected()){
            qreal angle=addblock2->angle+0.5235;
           // QPointF pos=addblock2->graphics->pos();
            qreal degreeangle=angle*180/3.1415;
            level2->removeItem(addblock2->graphics);
            addblock2 =new Block(myWorld2, level2, b2Vec2 (50,20),angle , 100, 40, b2_staticBody,1.0,"tool");
            addblock2->graphics->setRotation(degreeangle);
        }

    }
    if(counterTriangle==1){
        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1++;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level2->removeItem(addtriangle1->graphics);
            addtriangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");
        }

    }
    if(counterTriangle==2){


        if(addtriangle1->graphics->isSelected()){
            counterTriangleangle1++;
            if(abs(counterTriangleangle1)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle1)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle1)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle1)==4){
                angle=0;
                counterTriangleangle1=0;
            }else if(counterTriangleangle1==0){
                angle=0;
            }

            level2->removeItem(addtriangle1->graphics);
            addtriangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");

        }else if(addtriangle2->graphics->isSelected()){
            counterTriangleangle2++;
            if(abs(counterTriangleangle2)==1){
                angle=1.57;
            }else if(abs(counterTriangleangle2)==2){
                angle=3.1415;
            }else if(abs(counterTriangleangle2)==3){
                angle=4.7124;
            }else if(abs(counterTriangleangle2)==4){
                angle=0;
                counterTriangleangle2=0;
            }
            else if(counterTriangleangle1==0){
                angle=0;
             }

            level2->removeItem(addtriangle2->graphics);
            addtriangle2 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0),angle, b2_staticBody, 1.0,"tool");

       }
    }
}
