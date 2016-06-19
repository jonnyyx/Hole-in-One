#include "block.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>


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

    qreal graphicangle=angle*180/3.1415;
    graphics->setRotation(graphicangle);
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

//FEHLER TODO der body ist nach rechts unten versetzt. krieg ihn nicht auf die richtige pos..
//also wenn jemand bock hat hier weitermachen

void Block::draw()
{
    b2Vec2 v=body->GetPosition();




}

void Block::drawRec(int x,int y){


    b2Vec2 a=body->GetPosition();
    graphics->setPos(QPointF(a.x,a.y));

}

void Block::drawGraphics()
{
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());

}



