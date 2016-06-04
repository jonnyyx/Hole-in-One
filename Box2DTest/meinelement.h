#ifndef MEINELEMENT_H
#define MEINELEMENT_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

class MeinElement
{
public:
    MeinElement(b2World* world, QGraphicsScene* level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle);
    MeinElement(b2World* world, QGraphicsScene* level, QPointF a, QPointF b, QPointF c, QPointF d, b2BodyType type, b2PolygonShape &polygon);
    void draw();
    b2Body* body;

private:
    QGraphicsItem* graphics;
};

#endif // MEINELEMENT_H
