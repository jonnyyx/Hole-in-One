#include "block.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

/*!
 * \brief Block::Block
 * \param world : Box2D world for physic engine
 * \param level : Scene for the game
 * \param center : is the centerposition of the block
 * \param m_angle: angle for the block
 * \param m_length : length bock
 * \param m_width : width block
 * \param type : Box2D type of the Bbock(if it's static or dynamic)
 * \param friction : friction for the Block
 * \param mode : is it a obstacle or a tool
 */
Block::Block(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, b2BodyType type, qreal friction,QString mode)
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

    body->CreateFixture(&polygonFixtureDef);



    int x=center.x-length/2;
    int y=center.y-width/2;


    if(mode=="obs"){
        QPixmap bkgnd(":/pic/block_obs.png");
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



/*!
 * \brief Block::drawGraphics
 * connects the Box2D-Object to the Graphics after relocation
 */
void Block::drawGraphics()
{
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
}



