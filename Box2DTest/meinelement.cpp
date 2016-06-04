#include "meinelement.h"
#include <QGraphicsScene>

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
    body->CreateFixture(&circleFixtureDef);

//  body->SetLinearVelocity(b2Vec2(0.0,0.0));

    QPixmap bkgnd(":/new/prefix1/paper.png");
    bkgnd.scaled(QSize(42,42));


    graphics = level->addPixmap(bkgnd);
}

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, QPointF d, b2BodyType type, b2PolygonShape &polygon)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body

    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=20;
//  polygonFixtureDef.friction=XX;
    body->CreateFixture(&polygonFixtureDef);

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);

    QPolygonF polyf;
    polyf << a << b << c << d;
    graphics = level->addPolygon(polyf);

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

