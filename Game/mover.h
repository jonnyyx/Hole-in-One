#ifndef MOVER_H
#define MOVER_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

class Mover
{
public:
    Mover(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, qreal friction, QString mode);



    qreal length;
    qreal width;
    qreal angle;
    b2Body* body;
    QGraphicsItem* graphics;



};

#endif // MOVER_H
