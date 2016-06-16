#ifndef MEINELEMENT_H
#define MEINELEMENT_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

class MeinElement: public QObject
{
public:
    MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal friction);
    MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal length, qreal width, b2BodyType type, qreal friction);
    //Triangle
    MeinElement(b2World* world, QGraphicsScene* level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type, qreal friction);
    void draw();
    void drawGraphics();
    void drawBottom();
    void drawRec(int x,int y);

    b2Body* body;
    QGraphicsItem* graphics;



private:

};

#endif // MEINELEMENT_H