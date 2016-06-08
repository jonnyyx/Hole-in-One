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
    MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal friction);
    void draw();
    b2Body* body;

private:
    QGraphicsItem* graphics;
};

#endif // MEINELEMENT_H
