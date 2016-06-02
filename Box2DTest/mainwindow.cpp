#include "mainwindow.h"
#include "meinelement.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    /*!Screen setup. No scroll bar available*/
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1900,1900);

    /*!Scene setup*/
    level = new QGraphicsScene();
    level->setSceneRect(0,0,1900,1900);
    setScene(level);

    b2Vec2 gravity(0, -9.8); //normal earth gravity, 9.8 m/s/s straight down!

    myWorld = new b2World(gravity);

    //world->SetGravity( b2Vec2(0,0) );

    float32 timeStep = 1.0/20.0;      //the length of time passed to simulate (seconds)
    int32 velocityIterations = 8.0;   //how strongly to correct velocity
    int32 positionIterations = 3.0;   //how strongly to correct position

    myWorld->Step(timeStep, velocityIterations, positionIterations);

    elem = new MeinElement(myWorld, level, QPointF(500.0,500.0), 0*(3.14/180.0));
    elem1 = new MeinElement(myWorld, level, QPointF(250.0,250.0), 90*(3.14/180.0));
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
    std::cout<<"Anzahl der Objekte in der Welt:" <<anzahl<<"\n";
    std::cout<<"x-Positionvon elem:"<<positionElem.x<<"\n";
    std::cout<<"y-Position von elem:"<<positionElem.y<<"\n";

}
