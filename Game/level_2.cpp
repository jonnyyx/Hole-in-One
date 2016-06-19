#include "level_2.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <qdebug.h>
#include <QFile>
#include <QTextStream>
#include "string"


using namespace std;


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

void Level_2::update(){
    myWorld2->Step(framerate, 20, 20);

    win = ball->drawBall2(); //nur bewegende Elemente in Update

        if (win==true){
        Level_2::pauseLevel();

        msgbox = new MeinElement(level2,QPointF(375,275),300,175);

        QGraphicsTextItem * winText = new QGraphicsTextItem;
        winText->setPos(400,300);
        winText->setPlainText("You have finished Level 2");
        level2->addItem(winText);
        QGraphicsTextItem * timeText = new QGraphicsTextItem;
        timeText->setPos(400,350);
        QString time = QString("Time: %1").arg(leveltime);
        timeText->setPlainText( time);
        level2->addItem(timeText);
        QPushButton* quitLevel = new QPushButton("Quit");
        quitLevel->move(400,400);
        level2->addWidget(quitLevel);
        connect(quitLevel, SIGNAL(clicked()),this,SLOT(quitLevel()));
    }

}

/*!
 * \brief Level_1::startLevel
 * Set the flag of the QGraphicsItem, after click Start.
 */
void Level_2::startLevel(){

    rechteck1->drawGraphics();

    triangle1->drawGraphics();

    recyclebin1->drawGraphics();
    recyclebin1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    recyclebin2->drawGraphics();
    recyclebin2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->drawGraphics();
    //obstaclescircle2->drawGraphics();

    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    obstaclescircle1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    //obstaclescircle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    //obstaclescircle2->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);

    rechteck1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    rechteck1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    triangle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    triangle1->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);


    if(counterRec==1){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem4->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterRec==2){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem4->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        elem5->drawGraphics();
        elem5->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem5->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }

    if(counterRec==3){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem4->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        elem5->drawGraphics();
        elem5->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem5->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        elem6->drawGraphics();
        elem6->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem6->graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
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

void Level_2::resumeLevel()
{
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);

}

void Level_2::addRectangle()
{
    counterRec++;


    if (counterRec==1){
        elem4 = new Block(myWorld2, level2, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);

        bt__rect->setText("Rectangle (2)");
        //bt__circle->setText("Circle (2)");

        elem4->draw();
    }

    else if(counterRec==2){
        elem5 = new Block(myWorld2, level2, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);

        bt__rect->setText("Rectangle (1)");
        //bt__circle->setText("Circle (1)");

        elem5->draw();
    }

    else if(counterRec==3){
        elem6 = new Block(myWorld2, level2, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);
        elem6->draw();

        bt__rect->setEnabled(false);
        bt__circle->setEnabled(false);
    }

}

/*!
 * \brief Level_1::addCircle
 * Create new Circle and count the circle items. If you want to add more than 3 Circle, don't add a new Circle anymore.
 */

void Level_2::addCircle(){
    counterCircle++;

    b2CircleShape circle;

    if(counterCircle==1){
        circle.m_radius = 21.0;
        addcircle1 = new Circle(myWorld2, level2, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);

        bt__circle->setText("Circle (2)");

        addcircle1->draw();

    }

    if(counterCircle==2){
        circle.m_radius = 21.0;
        addcircle2 = new Circle(myWorld2, level2, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);

        bt__circle->setText("Circle (1)");

        addcircle2->draw();

    }

    if(counterCircle==3){
        circle.m_radius = 21.0;
        addcircle3 = new Circle(myWorld2, level2, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);

        bt__circle->setText("Circle (0)");

        addcircle3->draw();

        bt__rect->setEnabled(false);
        bt__circle->setEnabled(false);

    }

}

/*!
 * \brief Level_1::getTime
 * Stop time and convert it to ms.
 */
void Level_2::getTime(){
    leveltime = leveltime_elapsed.elapsed(); //leveltime in msec
    leveltime = leveltime/1000; //leveltime in sec
}

/*!
 * \brief Level_1::highscoreCounter
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
 * \brief Level_1::reset
 * Clear scene and load Level again.
 */
void Level_2::reset(){
    pauseLevel();
   level2->clear();
   counterRec = 0;
   counterCircle = 0;

   showLevel();

}

void Level_2::quitLevel()
{
    QFile file("level2.txt");

    if(file.exists("level2.txt")){
       file.remove("level2.txt");

       QFile file("level2.txt");
    }
    file.open(QIODevice::WriteOnly |QIODevice::Text);
    QTextStream out(&file);

    //out.reset();

    out<<"true"<<endl<<"false"<<endl<<"false"<<endl<<"false"<<endl<<"Highscore"<<endl<<leveltime<<endl<<counterTogether<<endl<<highscore<<endl;


    file.close();
    this->close();
}

/*!
 * \brief Level_1::showLevel
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
     bt_start=new QPushButton();
     bt_start->setText("Start");
     bt_start->move(900.0,620.0);
     connect(bt_start,SIGNAL(clicked()),this,SLOT(startLevel()));
     level2->addWidget(bt_start);


     //Pause Button
     bt_pause=new QPushButton();
     bt_pause->setText("Pause");
     bt_pause->setEnabled(false);
     bt_pause->move(900.0,660.0);

     connect(bt_pause,SIGNAL(clicked()),this,SLOT(getTime()));
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(highscoreCounter()));
     connect(bt_pause,SIGNAL(clicked()),this,SLOT(pauseLevel()));
     level2->addWidget(bt_pause);

     //Resume Button
     bt__resume=new QPushButton();
     bt__resume->setText("Resume");
     bt__resume->setEnabled(false);
     bt__resume->move(900.0,700.0);
     connect(bt__resume,SIGNAL(clicked()),this,SLOT(resumeLevel()));
     level2->addWidget(bt__resume);

     //Reset
     bt__reset=new QPushButton();
     bt__reset->setText("Reset");
     bt__reset->setEnabled(true);
     bt__reset->move(900.0, 740.0);
     connect(bt__reset, SIGNAL(clicked()), this, SLOT(reset()), Qt::QueuedConnection);
     level2->addWidget(bt__reset);

     //Rect Button
     bt__rect=new QPushButton();
     bt__rect->setText("Rectangle (3)");
     bt__rect->setEnabled(true);
     bt__rect->move(200.0,700.0);
     connect(bt__rect,SIGNAL(clicked()),this,SLOT(addRectangle()));
     level2->addWidget(bt__rect);

     //Circle Button
     bt__circle=new QPushButton();
     bt__circle->setText("Circle  (3)");
     bt__circle->setEnabled(true);
     bt__circle->move(400.0,700.0);
     connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()));
     level2->addWidget(bt__circle);

     //Rotate Left
     bt__left=new QPushButton();
     bt__left->setText("Rotate Left");
     bt__left->setEnabled(true);
     bt__left->move(5.0,650.0);
     connect(bt__left,SIGNAL(clicked()),this,SLOT(rotateLeft()));
     level2->addWidget(bt__left);

     //Rotate Left
     bt__right=new QPushButton();
     bt__right->setText("Rotate Right");
     bt__right->setEnabled(true);
     bt__right->move(105.0,650.0);
     connect(bt__right,SIGNAL(clicked()),this,SLOT(rotateRight()));
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
     obstaclescircle1 = new Circle(myWorld2, level2, QPointF(400.0,170), 0*(3.14/180.0), b2_staticBody, circle);
     rechteck1 = new Block(myWorld2, level2, b2Vec2 (300,150), 0, 100, 40, b2_staticBody,1.0);
     recyclebin1 = new RecycleBin(myWorld2, level2, QPointF(500,508),QPointF(510,508),QPointF(530,568),QPointF(520,568), 0.0, b2_staticBody, 0.5);
     recyclebin2 = new RecycleBin(myWorld2, level2, QPointF(550,568),QPointF(570,508),QPointF(580,508),QPointF(560,568), 0.0, b2_staticBody, 0.5);
     recyclebin3 = new RecycleBinGraphics(level2);
     triangle1 = new Triangle(myWorld2, level2, QPointF(0.0,0.0), QPointF(100.0,0.0), QPointF(100.0,100.0), 0, b2_staticBody, 1.0);

     bottom= new MeinElement(myWorld2, level2, b2Vec2(0.0,level2->height()-200), level2->width(), 22, b2_staticBody, 0.1);

     ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);

     obstaclescircle1->draw(); //Static Elemente lassen sich auch hier "drawn"
     //obstaclescircle2->draw();

     ball->drawBall2();

     bottom->drawBottom();
     umrandung1->graphics->hide();
     umrandung2->graphics->hide();

}

void Level_2::rotateLeft(){

    if(rechteck1->graphics->isSelected()){


    }

    if(counterRec==1){
        if(elem4->graphics->isSelected()){

        }

    }
    if(counterRec==2){
        if(elem4->graphics->isSelected()){

        }

        else if(elem5->graphics->isSelected()){

        }
    }

    if(counterRec==3){
        if(elem4->graphics->isSelected()){

        }

        else if(elem5->graphics->isSelected()){

        }

        else if(elem6->graphics->isSelected()){

        }
    }

    if(triangle1->graphics->isSelected()){

    }

}

void Level_2::rotateRight(){

    if(rechteck1->graphics->isSelected()){

    }

    if(counterRec==1){
        if(elem4->graphics->isSelected()){

        }

    }
    if(counterRec==2){
        if(elem4->graphics->isSelected()){

        }

        else if(elem5->graphics->isSelected()){

        }
    }

    if(counterRec==3){
        if(elem4->graphics->isSelected()){

        }

        else if(elem5->graphics->isSelected()){

        }

        else if(elem6->graphics->isSelected()){

        }
    }

    if(triangle1->graphics->isSelected()){

    }
}
