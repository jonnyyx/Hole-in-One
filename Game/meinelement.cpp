#include "meinelement.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>


MeinElement::MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal length, qreal width, b2BodyType type, qreal friction)
{
    b2PolygonShape polygon;
    polygon.SetAsBox(length, width, center,0);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1.0;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=1.0;
    polygonFixtureDef.friction=friction;
    body->CreateFixture(&polygonFixtureDef);




    int x=center.x;
    int y=center.y;
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);



}



MeinElement::MeinElement(QGraphicsScene *level, QPointF center, qreal length, qreal width)
{
    int x=center.x();
    int y=center.y();
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    QPixmap bk(":/pic/white.png");
    bk.scaled(QSize(length, width));
    white = level->addPixmap(bk);
    white->setPos(center.x(),center.y());

    //Aplause for Win
    applause = new QMediaPlayer();
    applause->setMedia(QUrl("qrc:/pic/applause.mp3"));
    applause->setVolume(100);
    applause->play();
}





 void MeinElement::drawBottom(){
     b2Vec2 v=body->GetPosition();
     graphics->setPos(QPointF(v.x,v.y));
 }



