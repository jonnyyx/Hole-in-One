#include "mainwindow.h"
#include "meinelement.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <QDebug>
#include "gui.h"


MainWindow::MainWindow(QWidget *parent)
{
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,700);

    /*!Scene setup*/
    level = new QGraphicsScene(this);
    level->setSceneRect(0,0,1200,700);
    setScene(level);

    b2Vec2 gravity(0.0,9.8); //normal earth gravity, 9.8 m/s/s straight down!

    myWorld = new b2World(gravity);

    //world->SetGravity( b2Vec2(0,0) );


    //int32 velocityIterations = 8.0;   //how strongly to correct velocity
    //int32 positionIterations = 3.0;   //how strongly to correct position


    b2CircleShape circle;
    circle.m_radius=20.0;
    b2PolygonShape polygon;
    polygon.SetAsBox(10,20);


    elem = new MeinElement(myWorld, level, QPointF(100.0,40.0), 0*(3.14/180.0), b2_dynamicBody, circle); // level...
    elem1 = new MeinElement(myWorld, level, QPointF(80.0,170.0), 0*(3.14/180.0), b2_staticBody, circle);
    elem2 = new MeinElement(myWorld, level, QPointF(120.0,500.0), 0*(3.14/180.0), b2_staticBody, circle);
    elem3 = new MeinElement(myWorld, level, QPointF(30.0,500.0),QPointF(400.0,600.0),QPointF(400.0,650.0),QPointF(30.0,550.0),b2_staticBody, polygon);
    elem1->draw();
    elem2->draw();
    elem3->draw();
    //anzahl=myWorld->GetBodyCount();
    positionElem=elem->body->GetPosition();

    timer=new QTimer(this);
    timer->setInterval(1.0/110.0*1000.0);
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();

}

/*void MainWindow::displayLevel(){

    QPixmap bkgnd(":/new/prefix1/paper.png");
    //bkgnd.scaled(10,Qt::IgnoreAspectRatio);

    level->addPixmap(bkgnd);

}
*/

void MainWindow::update(){
//qDebug()<<"update";
myWorld->Step(framerate, 10, 10);  //velocityIterations // positionIterations


    elem->draw();

    //elem

}
