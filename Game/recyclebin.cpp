#include "recyclebin.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

/*!
 * \brief RecycleBin::RecycleBin
 * \param world
 * \param level
 * \param a
 * \param b
 * \param c
 * \param d
 * \param angle
 * \param type
 */
RecycleBin::RecycleBin(b2World *world, QGraphicsScene *level, QPointF a, QPointF b,QPointF c, QPointF d, qreal angle, b2BodyType type)
{

    b2BodyDef myBodyDef;
    myBodyDef.type = type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.angle = angle;


    body = world->CreateBody(&myBodyDef);


    //set each vertex of polygon in an array
    b2Vec2 vertices[4];
    vertices[0].Set(a.x(), a.y());
    vertices[1].Set(b.x(), b.y());
    vertices[2].Set(c.x(), c.y());
    vertices[3].Set(d.x(), d.y());

    b2PolygonShape polygon;
    polygon.Set(vertices, 4); //pass array to the shape


    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape = &polygon; //change the shape of the fixture
    body->CreateFixture(&polygonFixtureDef); //add a fixture to the body

    QPolygonF polygon2;
    polygon2 << a << b << c << d;
    graphics = level->addPolygon(polygon2);

    graphics->setFlag(QGraphicsItem::ItemIsMovable, false);




}


/*!
 * \brief RecycleBin::drawGraphics
 * connects the Box2D-Object to the Graphics after relocation
 */
void RecycleBin::drawGraphics(){
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
}




