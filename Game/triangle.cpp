#include "triangle.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

/*!
 * \brief Triangle::Triangle
 * \param world box2d world
 * \param level scene of qt
 * \param a left upper corner, default setting if rotate calculate new position of a
 * \param b right upper corner, default setting if rotate calculate new position of b
 * \param c right lower corner, default setting if rotate calculate new position of c
 * \param angle box2d angle
 * \param type static or dynamic object
 * \param friction box2d friction
 *
 */
Triangle::Triangle(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type, qreal friction, QString mode)
{
    b2BodyDef myBodyDef;
    myBodyDef.type = type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body


    body = world->CreateBody(&myBodyDef);

    //set each vertex of polygon in an array
    b2Vec2 vertices[3];
    if(angle==0){
        vertices[0].Set(a.x(), a.y());
        vertices[1].Set(b.x(), b.y());
        vertices[2].Set(c.x(), c.y());
    }else if(angle==1.57){
        vertices[0].Set(a.x()+100, a.y());
        vertices[1].Set(b.x(), b.y()+100);
        vertices[2].Set(c.x()-100, c.y());
    }else if(angle==3.1415){
        vertices[0].Set(a.x(), a.y());
        vertices[1].Set(b.x()-100, b.y()+100);
        vertices[2].Set(c.x(), c.y());
    }else if(angle==4.7124){
        vertices[0].Set(a.x(), a.y());
        vertices[1].Set(b.x(), b.y());
        vertices[2].Set(c.x()-100, c.y());
    }




    b2PolygonShape polygon;
    polygon.Set(vertices, 3); //pass array to the shape

    b2FixtureDef triangleFixtureDef;
    triangleFixtureDef.shape = &polygon; //change the shape of the fixture
    triangleFixtureDef.friction=friction;
    body->CreateFixture(&triangleFixtureDef); //add a fixture to the body

    QPolygonF triangle;
    triangle << a << b << c;
    if(mode=="obs"){
        if(angle==0){
            QPixmap bkgnd(":/pic/triangle_obs.png");
            bkgnd.scaled(QSize(100,100));
            graphics = level->addPixmap(bkgnd);
            graphics->setPos(QPointF(a.x()+21,a.y()+21));
            graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
            graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        }else if(angle==1.57){
            QPixmap bkgnd(":/pic/triangle_obs_90degree.png");
            bkgnd.scaled(QSize(100,100));
            graphics = level->addPixmap(bkgnd);
            graphics->setPos(QPointF(a.x()+21,a.y()+21));

            graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
            graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        }else if(angle==3.1415){

            QPixmap bkgnd(":/pic/triangle_obs_180degree.png");
            bkgnd.scaled(QSize(100,100));
            graphics = level->addPixmap(bkgnd);
            graphics->setPos(QPointF(a.x()+21,a.y()+21));

            graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
            graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        }else if(angle==4.7124){

            QPixmap bkgnd(":/pic/triangle_obs_270degree.png");
            bkgnd.scaled(QSize(100,100));
            graphics = level->addPixmap(bkgnd);
            graphics->setPos(QPointF(a.x()+21,a.y()+21));

            graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
            graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
        }

    }else if(mode=="tool"){
        if(angle==0){
        QPixmap bkgnd(":/pic/triangle_tool.png");
        bkgnd.scaled(QSize(100,100));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPointF(a.x()+21,a.y()+21));

        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);

    }else if(angle==1.57){

        QPixmap bkgnd(":/pic/triangle_tool_90degree.png");
        bkgnd.scaled(QSize(100,100));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPointF(a.x()+21,a.y()+21));

        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
    }else if(angle==3.1415){

        QPixmap bkgnd(":/pic/triangle_tool_180degree.png");
        bkgnd.scaled(QSize(100,100));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPointF(a.x()+21,a.y()+21));

        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
    }else if(angle==4.7124){

        QPixmap bkgnd(":/pic/triangle_tool_270degree.png");
        bkgnd.scaled(QSize(100,100));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPointF(a.x()+21,a.y()+21));

        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
    }

}

}



/*!
 * \brief Triangle::drawGraphics
 * connects the Box2D-Object to the Graphics after relocation
 */

void Triangle::drawGraphics()
{
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());

}


