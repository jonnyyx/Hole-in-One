#include "mainwindow.h"
#include "meinelement.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
{
    /*!Screen setup. No scroll bar available*/
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    /*!Scene setup*/
    level = new QGraphicsScene();
    level->setSceneRect(0,0,1024,768);
    setScene(level);

    b2Vec2 gravity(0, -9.8); //normal earth gravity, 9.8 m/s/s straight down!

    myWorld = new b2World(gravity);
    myWorld->SetGravity(gravity);
    //world->SetGravity( b2Vec2(0,0) );

    float32 timeStep = 1.0/20.0;      //the length of time passed to simulate (seconds)
    int32 velocityIterations = 8.0;   //how strongly to correct velocity
    int32 positionIterations = 3.0;   //how strongly to correct position

    myWorld->Step(timeStep, velocityIterations, positionIterations);

    elem = new MeinElement(myWorld, level, QPointF(100.0,100.0), 0*(3.14/180.0)); // Position des 1. Objektes kann geändert werden
    elem1 = new MeinElement(myWorld, level, QPointF(100.0,150.0), 0*(3.14/180.0)); // Position des 2. Objektes nicht veränderbar
    anzahl=myWorld->GetBodyCount();
    positionElem=elem->body->GetPosition();

    timer=new QTimer(this);
    timer->setInterval(1.0/20.0*1000.0);
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

    elem->draw();
    elem1->draw();

    //elem->body->ApplyLinearImpulse(b2Vec2(1.0, 1.0), b2Vec2(0.0, 0.0), true);

    std::cout<<"Anzahl der Objekte in der Welt:" <<anzahl<<"\n";
    std::cout<<"x-Position von elem:"<<positionElem.x<<"\n";
    std::cout<<"y-Position von elem:"<<positionElem.y<<"\n";

}

double MainWindow::getCurrentTimeInSecounds()
{
    static struct timeval currentTime;
    gettimeofday(&current Time, nullptr);

}
