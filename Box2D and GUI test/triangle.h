#ifndef TRIANGLE_H
#define TRIANGLE_H

#endif // TRIANGLE_H

#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

class Triangle
{
public:
    Triangle(b2World* world, QGraphicsScene* level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type);

    void draw();
    void drawGraphics();

    b2Body* body;
    QGraphicsItem* graphics;

private:

};
