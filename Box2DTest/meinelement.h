#ifndef MEINELEMENT_H
#define MEINELEMENT_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>


class MeinElement
{
public:
    MeinElement(b2World* world,QGraphicsScene* scene,QPointF position,qreal angle);
    void draw();
private:
    QGraphicsItem* graphics;
    b2Body* body;
};

#endif // MEINELEMENT_H
