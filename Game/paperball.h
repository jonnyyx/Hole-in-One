#ifndef PAPERBALL_H
#define PAPERBALL_H

#include "Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

/*!
 * \brief The Paperball class
 */
class Paperball : public QObject
{

public:
    Paperball(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle);

    void createPaper(b2World world, QGraphicsScene levelscene, QPointF pos, qreal angle, b2BodyType type, b2CircleShape &circle);


    b2Body* body; ///<Box2D Body of Object
    QGraphicsItem* graphics; ///<Graphic of Object
    bool drawBall1();


};

#endif // PAPERBALL_H
