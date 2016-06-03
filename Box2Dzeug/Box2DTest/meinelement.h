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
    b2Body* body;
private:
    QGraphicsItem* graphics;
};

#endif // MEINELEMENT_H
