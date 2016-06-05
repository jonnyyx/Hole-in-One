#include "mainwindow.h"
#include "meinelement.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
{
    /*!Screen setup. No scroll bar available*/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*!Scene setup*/
    level = new QGraphicsScene();
    level->setSceneRect(0,0,1024,768);
    setScene(level);

    b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!

    myWorld = new b2World(gravity);

    float32 timeStep = 1.0/100.0;     //the length of time passed to simulate (seconds)
    int32 velocityIterations = 8.0;   //how strongly to correct velocity
    int32 positionIterations = 3.0;   //how strongly to correct position

    myWorld->Step(timeStep, velocityIterations, positionIterations);

    b2CircleShape circle;
    circle.m_radius = 21.0;
    b2PolygonShape polygon;  //manchmal ist b2PolygonShape.SetBox(hx,hy) nötig //Assertion error

    elem  = new MeinElement(myWorld, level, QPointF(100.0,40.0), 0*(3.14/180.0), b2_dynamicBody, circle);
    elem1 = new MeinElement(myWorld, level, QPointF(80.0,170), 0*(3.14/180.0), b2_staticBody, circle);
    elem2 = new MeinElement(myWorld, level, QPointF(120.0,500.0), 0*(3.14/180.0), b2_staticBody, circle);
    elem3 = new MeinElement(myWorld, level, QPointF(330.0,200.0), QPointF(400.0,200.0), QPointF(400.0,300.0), QPointF(330.0,300.0), b2_staticBody, polygon);

    //anzahl=myWorld->GetBodyCount();
    positionElem=elem->body->GetPosition(); //falls sich neues Objakt bewegen soll, muss >> positionElem=elemX->body->GetPosition();

    elem1->draw(); //Static Elemente lassen sich auch hier "drawn"
    elem2->draw();
    elem3->draw();

    timer=new QTimer(this);
    timer->setInterval(1.0/120.0*1000.0);
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
    myWorld->Step(framerate, 20, 20);
    elem->draw(); //nur bewegende Elemente in Update

}
