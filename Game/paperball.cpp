#include "paperball.h"
#include "Box2D/Box2D.h"
#include <QGraphicsScene>

Paperball::Paperball(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef paperFixtureDef;
    paperFixtureDef.shape = &circle;
    paperFixtureDef.density = 0.8;
    paperFixtureDef.restitution = 0.6;
    body->CreateFixture(&paperFixtureDef);

//  body->SetLinearVelocity(b2Vec2(0.0,0.0));

    QPixmap bkgnd(":/pic/paper.png");
    bkgnd.scaled(QSize(42,42));


    graphics = level->addPixmap(bkgnd);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);

}
void Paperball::draw()
{
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    qreal a=body->GetAngle();

}

void Paperball::drawBall()
{
    b2Vec2 v=body->GetPosition();
    qreal a=body->GetAngle();
    qreal grad=a*(180.0/3.14);


    graphics->setPos(v.x,v.y);

}

void Paperball::drawGraphics(){
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
}

