#include "meinelement.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle)
{


    b2BodyDef myBodyDef;
    myBodyDef.type=type;//b2_staticBody, b2_kinematicBody,b2_dynamicBody
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape=&circle;
    circleFixtureDef.density=10;

    body->CreateFixture(&circleFixtureDef);

    //body->SetLinearVelocity(b2Vec2(0.0,0.0));
    //body->ApplyLinearImpulse(b2Vec2(10.0,3.0),b2Vec2(4.0,0.0),true);
    QGraphicsEllipseItem* circ = new QGraphicsEllipseItem();
    //circle.setRect(qreal 10, qreal 5, qreal 10,qreal 10);
    circ->setVisible(true);

    //QPixmap bkgnd(":/new/prefix1/paper.png");
    //bkgnd.scaled(QSize(10,10),Qt::IgnoreAspectRatio);

//    graphics = level->addPixmap(bkgnd);
    graphics = level->addEllipse(1,3,40,40); //---------------------



}

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, QPointF d,  b2BodyType type, b2PolygonShape &polygon)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type;//b2_staticBody, b2_kinematicBody,b2_dynamicBody
    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=10;
    //polygonFixtureDef.friction=10;
    body->CreateFixture(&polygonFixtureDef);

//    QGraphicsPolygonItem* poly = new QGraphicsPolygonItem();
//    poly->setVisible(true);
    QPolygonF polyf;
    polyf<< a << b << c << d;
    graphics = level->addPolygon(polyf); //-----------------------
}
void MeinElement::draw()
 {
     b2Vec2 v=body->GetPosition();
     graphics->setPos(QPointF(v.x,v.y));
     qreal a=body->GetAngle();
     graphics->setRotation(a);
 }

