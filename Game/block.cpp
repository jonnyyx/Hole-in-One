#include "block.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>


Block::Block(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal friction)
{
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

    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);


    graphics->setFlag(QGraphicsItem::ItemIsSelectable,true);
    graphics->setTransformOriginPoint(x+length/2,y+width/2);

    drawRec(x,y);

}

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

void Block::drawGraphics(){
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x()-21,v.y()-21),body->GetAngle());
}

void Block::rotateright(){
    Block::drawGraphics();
    QPointF v=graphics->pos();
    qreal a=body->GetAngle();
    //b2Vec2 p=body->GetPosition();
    body->SetTransform(b2Vec2(v.x(),v.y()),0); // FEHLER bei 0 wird der body nicht gedreht und der Ball fällt nicht durch
    // bei angle ungleich 0 wird der body irgendwohin verschoben und ich checks nicht...
    //ansonsten müsst so passen, man kann das rechteck irgendwo hin machen und es wird an der stelle dann gedreht.

    graphics->setRotation(a-30);

    //b2Vec2 b=body->GetPosition();
    //body->SetTransform(b,a-30);
    //QPointF v=graphics->pos();
    //body->SetTransform(b2Vec2(v.x()-21,v.y()-21),a-30);
    //Block::drawGraphics();

}
void Block::rotateleft(){

    qreal a=body->GetAngle();
    graphics->setRotation(a+30);
    b2Vec2 b=body->GetPosition();
    body->SetTransform(b,a+30);
    graphics->setRotation(a+30);
}
