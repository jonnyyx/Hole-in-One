#ifndef TRIANGLE_H
#define TRIANGLE_H

#endif // TRIANGLE_H

#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

class MainWindow;

class Triangle: public QObject
{

public:
    Triangle(b2World* world, QGraphicsScene* level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type, qreal friction);

    void draw();
    void drawGraphics();
    void rotateleft();
    void rotateright();

    b2Body* body;
    QGraphicsItem* graphics;

private:

};
