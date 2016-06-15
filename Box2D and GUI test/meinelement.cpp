#include "meinelement.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>



MeinElement::MeinElement(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0;
    circleFixtureDef.restitution = 0.6;
    body->CreateFixture(&circleFixtureDef);

}

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal )
{
    b2PolygonShape polygon;
    polygon.SetAsBox(length/2, width/2, center, angle);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1.0;

    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=1.0;
    //polygonFixtureDef.friction=friction;
    body->CreateFixture(&polygonFixtureDef);

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);


    int x=center.x-length/4;
    int y=center.y-width/4;

    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);

    drawRec(x+length/2,y+width/2);

}

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

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);


    int x=center.x;
    int y=center.y;
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);


//  body->SetLinearVelocity(b2Vec2(0.0,0.0));
//  QPixmap bkgnd(":/new/prefix1/paper.png");
//  bkgnd.scaled(QSize(42,42));
//  graphics = scene->addPixmap(bkgnd);
}

 void MeinElement::draw()
 {
     b2Vec2 v=body->GetPosition();

     graphics->setPos(QPointF(v.x,v.y));
     qreal a=body->GetAngle();

 }

 void MeinElement::drawBall()
 {
     b2Vec2 v=body->GetPosition();
     qreal a=body->GetAngle();
     qreal grad=a*(180.0/3.14);


     graphics->setPos(v.x,v.y);


//     graphics->setRotation(grad); //Urechnung von rad in grad; Box2D gibt in rad zurück muss aber in grad an QTGraphicsItem übergeben werden


 }

 void MeinElement::drawRec(int x,int y){

     graphics->setPos(QPointF(x,y));
     qreal a=body->GetAngle();
     graphics->setRotation(a);

 }

 void MeinElement::drawBottom(){
     b2Vec2 v=body->GetPosition();
     graphics->setPos(QPointF(v.x,v.y));
 }

 void MeinElement::drawGraphics(){
     QPointF v=graphics->pos();
     body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
 }

