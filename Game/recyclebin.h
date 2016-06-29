#ifndef RECYCLEBIN_H
#define RECYCLEBIN_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

/*!
 * \brief The RecycleBin class
 */
class RecycleBin {

public:
    RecycleBin(b2World *world, QGraphicsScene *level, QPointF a, QPointF b, QPointF c, QPointF d, qreal angle, b2BodyType type);

    void drawGraphics();

    b2Body* body; ///<Box2D Body of Object
    QGraphicsItem* graphics; ///<Graphic of Object
};

#endif // RECYCLEBIN_H
