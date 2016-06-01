#include "mainwindow.h"
#include "meinelement.h"

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
    //bool doSleep = true;

    b2World* world = new b2World(gravity);
   // myWorld->SetGravity( b2Vec2(0,0) );

    elem = new MeinElement(world, level, QPointF(5,5),0);
    timer=new QTimer(this);
    timer->setInterval(1.0/60.0*1000.0);
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
}

void MainWindow::displayLevel(){

    QPixmap bkgnd(":/new/prefix1/paper.png");
    //bkgnd.scaled(10,Qt::IgnoreAspectRatio);

    level->addPixmap(bkgnd);

}
void MainWindow::update(){
    elem->draw();

}
