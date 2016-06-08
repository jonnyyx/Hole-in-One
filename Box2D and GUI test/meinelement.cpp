#include "meinelement.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 20;
    circleFixtureDef.restitution = 0.6;
    body->CreateFixture(&circleFixtureDef);

//  body->SetLinearVelocity(b2Vec2(0.0,0.0));

    QPixmap bkgnd(":/new/prefix1/paper.png");
    bkgnd.scaled(QSize(42,42));


    graphics = level->addPixmap(bkgnd);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
}

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal friction)
{
    b2PolygonShape polygon;
    polygon.SetAsBox(length, width, center, angle);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1000.0;

    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=20;
    polygonFixtureDef.friction=friction;
    body->CreateFixture(&polygonFixtureDef);

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);


    int x=center.x;
    int y=center.y;
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);

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
     graphics->setRotation(a);
 }

 void MeinElement::drawGraphics(){
     QPointF v=graphics->pos();
     body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
 }

