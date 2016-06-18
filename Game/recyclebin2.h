#ifndef RECYCLEBIN2_H
#define RECYCLEBIN2_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

class RecycleBin2 {

public:
    RecycleBin2(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, QPointF d, qreal angle, b2BodyType type, qreal fricition);

    void drawGraphics();
    void draw();
    b2Body* body;
    QGraphicsItem* graphics;
};

#endif // RECYCLEBIN2_H
