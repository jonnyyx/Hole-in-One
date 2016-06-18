#include "triangle.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

/*!
 * \brief Triangle::Triangle
 * \param world
 * \param level
 * \param a
 * \param b
 * \param c
 * \param angle
 * \param type
 * \param friction
 */
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
//    graphics = level->addPolygon(triangle);

    QPixmap bkgnd(":/pic/triangle_tool.png");
    bkgnd.scaled(QSize(100,100));
    graphics = level->addPixmap(bkgnd);
    graphics->setPos(a);

    graphics->setTransformOriginPoint(b);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
    graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);

}

/*!
 * \brief Triangle::draw
 */
void Triangle::draw()
{
    /*!
     * \brief v
     */
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    qreal a=body->GetAngle();
}
/*!
 * \brief Triangle::drawGraphics
 */

void Triangle::drawGraphics()
{
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
}

void Triangle::rotateright(){

    qreal a=body->GetAngle();
    graphics->setRotation(a-30);
    b2Vec2 b=body->GetPosition();
    body->SetTransform(b,a-30);
}
void Triangle::rotateleft(){

    qreal a=body->GetAngle();
    graphics->setRotation(a+30);
    b2Vec2 b=body->GetPosition();
    body->SetTransform(b,a+30);
}
