#include "meinelement.h"
#include <QGraphicsScene>

MeinElement::MeinElement(b2World *world, QGraphicsScene *scene, QPointF position, qreal angle, b2BodyType type)
{


    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;

    body=world->CreateBody(&myBodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius=23.0;

    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape=&circleShape;
    circleFixtureDef.density=10;
    body->CreateFixture(&circleFixtureDef);

    body->SetLinearVelocity(b2Vec2(0.0,0.0));

    QPixmap bkgnd(":/new/prefix1/paper.png");
    bkgnd.scaled(QSize(42,42));


    graphics = scene->addPixmap(bkgnd);



 }

 void MeinElement::draw()
 {
     b2Vec2 v=body->GetPosition();
     graphics->setPos(QPointF(v.x,v.y));
     qreal a=body->GetAngle();
     graphics->setRotation(a);
 }

