#include "trampoline.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

/*!
 * \brief Trampoline::Trampoline
 * \param world
 * \param level
 * \param center
 * \param m_angle
 * \param m_length
 * \param m_width
 * \param type
 * \param friction
 * \param mode
 */
Trampoline::Trampoline(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, b2BodyType type, qreal friction,QString mode)
{
    angle=m_angle;
    length=m_length;
    width=m_width;
    b2PolygonShape polygon;
    polygon.SetAsBox(length/2, width/2,center, angle);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1.0;

    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=1;
    polygonFixtureDef.friction=friction;
    polygonFixtureDef.restitution=1;

    body->CreateFixture(&polygonFixtureDef);



    int x=center.x-length/2;
    int y=center.y-width/2;


    if(mode=="obs"){
        QPixmap bkgnd(":/pic/tram_obs.png");
        bkgnd.scaled(QSize(length,width));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPoint(x+21,y+21));
        graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }
    else if(mode=="tool"){
        QPixmap bkgnd(":/pic/block_tool.png");
        bkgnd.scaled(QSize(length,width));
        graphics = level->addPixmap(bkgnd);
        graphics->setPos(QPoint(x+21,y+21));
        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
        graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
    }

    graphics->setTransformOriginPoint(x+length/2,y+width/2);



}









