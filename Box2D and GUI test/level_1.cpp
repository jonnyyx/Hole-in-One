#include "level_1.h"
#include "meinelement.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <qdebug.h>





Level_1::Level_1(QWidget *parent)
{
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);



    /*!Scene setup*/
    level = new QGraphicsScene();
    level->setSceneRect(0,0,1024,768);
    setScene(level);



   //Start Button
    bt_start=new QPushButton();
    bt_start->setText("Start");
    bt_start->move(900.0,620.0);
    connect(bt_start,SIGNAL(clicked()),this,SLOT(startLevel()));
    level->addWidget(bt_start);


    //Pause Button
    bt_pause=new QPushButton();
    bt_pause->setText("Pause");
    bt_pause->setEnabled(false);
    bt_pause->move(900.0,660.0);

    connect(bt_pause,SIGNAL(clicked()),this,SLOT(pauseLevel()));
    level->addWidget(bt_pause);

    //Resume Button
    bt__resume=new QPushButton();
    bt__resume->setText("Resume");
    bt__resume->setEnabled(false);
    bt__resume->move(900.0,700.0);
    connect(bt__resume,SIGNAL(clicked()),this,SLOT(resumeLevel()));
    level->addWidget(bt__resume);

    //Rect Button
    bt__rect=new QPushButton();
    bt__rect->setText("Rectangle");
    bt__rect->setEnabled(true);
    bt__rect->move(200.0,700.0);
    connect(bt__rect,SIGNAL(clicked()),this,SLOT(addRectangle()));
    level->addWidget(bt__rect);

    //Circle Button
    bt__circle=new QPushButton();
    bt__circle->setText("Circle");
    bt__circle->setEnabled(true);
    bt__circle->move(400.0,700.0);
    connect(bt__circle,SIGNAL(clicked()),this,SLOT(addCircle()));
    level->addWidget(bt__circle);








    b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!

    myWorld = new b2World(gravity);

    float32 timeStep = 1.0/100.0;     //the length of time passed to simulate (seconds)
    int32 velocityIterations = 8.0;   //how strongly to correct velocity
    int32 positionIterations = 3.0;   //how strongly to correct position

    myWorld->Step(timeStep, velocityIterations, positionIterations);

    b2CircleShape circle;
    circle.m_radius = 21.0;

    //b2PolygonShape polygon;  //manchmal ist b2PolygonShape.SetBox(hx,hy) nötig //Assertion error
    //polygon.SetAsBox(1.0,1.0);


    ball  = new MeinElement(myWorld, level, QPointF(81.0,40.0), 0*(3.14/180.0), b2_dynamicBody, circle);
    kreis1 = new MeinElement(myWorld, level, QPointF(80.0,170), 0*(3.14/180.0), b2_staticBody, circle);
    kreis2 = new MeinElement(myWorld, level, QPointF(120.0,500.0), 0*(3.14/180.0), b2_staticBody, circle);
    rechteck1 = new MeinElement(myWorld, level, b2Vec2 (45.0,170.0), 0, 100, 100, b2_staticBody,1.0);
    //elem3 = new MeinElement(myWorld, level, QPointF(330.0,200.0), QPointF(400.0,200.0), QPointF(400.0,300.0), QPointF(330.0,300.0), b2_staticBody, polygon);
    bottom= new MeinElement(myWorld, level, b2Vec2(0.0,level->height()-200), level->width(), 22, b2_staticBody,20.0);
    //anzahl=myWorld->GetBodyCount();
    //positionElem=elem->body->GetPosition(); //falls sich neues Objakt bewegen soll, muss >> positionElem=elemX->body->GetPosition();

    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    kreis1->draw(); //Static Elemente lassen sich auch hier "drawn"
    kreis2->draw();
    //rechteck1->draw();
    //elem3->drawRec(elem3->body->GetPosition());
    bottom->drawBottom();




}

/*void Level_1::displayLevel(){

    QPixmap bkgnd(":/new/prefix1/paper.png");
    //bkgnd.scaled(10,Qt::IgnoreAspectRatio);

    level->addPixmap(bkgnd);

}
*/

void Level_1::update(){
    myWorld->Step(framerate, 20, 20);
    ball->drawBall(); //nur bewegende Elemente in Update

}

void Level_1::startLevel(){

    rechteck1->drawGraphics();
    kreis1->drawGraphics();
    kreis2->drawGraphics();
    ball->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    kreis1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    kreis2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    rechteck1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);


    if(counterRec==1){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterRec==2){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem5->drawGraphics();
        elem5->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterRec==3){
        elem4->drawGraphics();
        elem4->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem5->drawGraphics();
        elem5->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        elem6->drawGraphics();
        elem6->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==1){
        circle1->drawGraphics();
        circle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==2){
        circle1->drawGraphics();
        circle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        circle2->drawGraphics();
        circle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }

    if(counterCircle==3){
        circle1->drawGraphics();
        circle1->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        circle2->drawGraphics();
        circle2->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        circle3->drawGraphics();
        circle3->graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }


    timer=new QTimer(this);
    timer->setInterval(1.0/120.0*1000.0);
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);

    leveltime_elapsed.start();
    leveltime_normal.start();

}
void Level_1::pauseLevel(){
    timer->stop();
    bt_pause->setEnabled(false);
    bt__resume->setEnabled(true);
    bt_start->setEnabled(false);

    qDebug()<<leveltime_elapsed.elapsed()<<"milliseconds";
    qDebug()<<leveltime_normal.elapsed()<<"milliseconds";
}

void Level_1::resumeLevel()
{
    timer->start();
    bt_pause->setEnabled(true);
    bt__resume->setEnabled(false);
    bt_start->setEnabled(false);
}


void Level_1::addRectangle()
{
    counterRec++;


    if (counterRec==1){
        elem4 = new MeinElement(myWorld, level, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);
        elem4->draw();



    }

    else if(counterRec==2){
        elem5 = new MeinElement(myWorld, level, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);
        elem5->draw();
    }

    else if(counterRec==3){
        elem6 = new MeinElement(myWorld, level, b2Vec2 (400.0,400.0), 0, 100, 100, b2_staticBody,1.0);
        elem6->draw();

        bt__rect->setEnabled(false);
        bt__circle->setEnabled(false);
    }

}

void Level_1::addCircle(){
    counterCircle++;

    b2CircleShape circle;

    qDebug()<<counterCircle;
    if(counterCircle==1){
        circle.m_radius = 21.0;
        circle1 = new MeinElement(myWorld, level, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);
        circle1->draw();

    }

    if(counterCircle==2){
        circle.m_radius = 10.0;
        circle2 = new MeinElement(myWorld, level, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);
        circle2->draw();

    }

    if(counterCircle==3){
        circle.m_radius = 10.0;
        circle3 = new MeinElement(myWorld, level, QPointF(200.0,170), 0*(3.14/180.0), b2_staticBody, circle);
        circle3->draw();

        bt__rect->setEnabled(false);
        bt__circle->setEnabled(false);

    }

}







