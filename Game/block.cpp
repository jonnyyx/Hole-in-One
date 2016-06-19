#include "block.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>


Block::Block(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, b2BodyType type, qreal friction)
{
    angle=m_angle;
    length=m_length;
    width=m_width;
    b2PolygonShape polygon;
    polygon.SetAsBox(length/2, width/2, center, angle);
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

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);

    int x=center.x-length/2;
    int y=center.y-width/2;

    //QRectF polyf(QPoint(x,y),QSize(length,width));

//    graphics = level->addRect(polyf);
//    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
//    graphics->setRotation(30);

//    graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
//    graphics->setTransformOriginPoint(x+length/2,y+width/2);

//    drawRec(x,y);
    //body->SetTransform(b2Vec2(center.x,center.y),0);
    QPixmap bkgnd(":/pic/block_tool.png");
    bkgnd.scaled(QSize(length,width));
    graphics = level->addPixmap(bkgnd);
    //graphics->setPos(x,y);

    graphics->setTransformOriginPoint(x+length/2,y+width/2);
//    graphics->setPos(x,y);

    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
    graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
//    drawGraphics();
    drawRec(x,y);
}

//FEHLER TODO der body ist nach rechts unten versetzt. krieg ihn nicht auf die richtige pos..
//also wenn jemand bock hat hier weitermachen

void Block::draw()
{
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    qreal a=body->GetAngle();

}

void Block::drawRec(int x,int y){

    graphics->setPos(QPointF(x,y));
    qreal a=body->GetAngle();
    graphics->setRotation(a);


}

void Block::drawGraphics()
{
    QPointF v=graphics->pos();
//    b2Vec2 vv=body->GetPosition();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
//    graphics1->setPos(vv.x,vv.y);
}

