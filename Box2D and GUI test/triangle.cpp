#include "triangle.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

Triangle::Triangle(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type, qreal friction)
{
    b2BodyDef myBodyDef;
    myBodyDef.type = type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.angle = angle;

    body = world->CreateBody(&myBodyDef);

    //set each vertex of polygon in an array
    b2Vec2 vertices[3];
    vertices[0].Set(a.x(), a.y());
    vertices[1].Set(b.x(), b.y());
    vertices[2].Set(c.x(), c.y());

    b2PolygonShape polygon;
    polygon.Set(vertices, 3); //pass array to the shape

    b2FixtureDef triangleFixtureDef;
    triangleFixtureDef.shape = &polygon; //change the shape of the fixture
    triangleFixtureDef.friction=friction;
    body->CreateFixture(&triangleFixtureDef); //add a fixture to the body

    QPolygonF triangle;
    triangle << a << b << c;
    graphics = level->addPolygon(triangle);

    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
}

void Triangle::draw()
{
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    qreal a=body->GetAngle();
}

void Triangle::drawGraphics()
{
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
}
