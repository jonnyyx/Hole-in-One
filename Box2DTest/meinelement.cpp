#include "meinelement.h"
#include <QGraphicsScene>

MeinElement::MeinElement(b2World *world, QGraphicsScene *scene, QPointF position, qreal angle)
{


   b2BodyDef myBodyDef;
   myBodyDef.type=b2_dynamicBody;
   myBodyDef.position.Set(position.x(),position.y());
   myBodyDef.angle;

   body=world->CreateBody(&myBodyDef);

   b2CircleShape circleShape;
   circleShape.m_radius=5.5;

   b2FixtureDef circleFixtureDef;
   circleFixtureDef.shape=&circleShape;
   circleFixtureDef.density=1;
   body->CreateFixture(&circleFixtureDef);

   QPixmap bkgnd(":/new/prefix1/paper.png");
   //bkgnd.scaled(10,Qt::IgnoreAspectRatio);

   graphics = scene->addPixmap(bkgnd);



}

void MeinElement::draw()
{
    b2Vec2 v=body->GetPosition();
    graphics->setPos(v.x,v.y);
    qreal a=body->GetAngle();
    graphics->setRotation(a);
}

