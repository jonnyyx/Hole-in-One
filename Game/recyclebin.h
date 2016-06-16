#ifndef RECYCLEBIN_H
#define RECYCLEBIN_H

#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
class MainWindow;
class RecycleBin
{
public:
    RecycleBin(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, QPointF d, qreal angle, b2BodyType type, qreal fricition);

    void drawGraphics();
    void draw();
    b2Body* body;
    QGraphicsItem* graphics;
};

#endif // RECYCLEBIN_H
