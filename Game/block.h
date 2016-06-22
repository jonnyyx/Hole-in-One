#ifndef BLOCK_H
#define BLOCK_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

class MainWindow;

class Block : public QObject
{
public:
    Block(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, b2BodyType type, qreal friction, QString mode);
    void drawGraphics();
    void drawRec(int x,int y);

    qreal length;
    qreal width;
    qreal angle;
    b2Body* body;
    QGraphicsItem* graphics;





private:

};

#endif // BLOCK_H
