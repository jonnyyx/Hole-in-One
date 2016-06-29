#ifndef CIRCLE_H
#define CIRCLE_H
#include "Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

class Circle : public QObject
{

public:
    /*!
     * \brief Circle::Circle
     * \param world : Box2D world for physic engine
     * \param level : Scene for the game
     * \param position : left upper corner
     * \param angle : angle for the circle
     * \param type : Box2D type of the circle(if it's static or dynamic)
     * \param circle : Box2D knows that it is a circle
     * \param mode : is it a obstacle or a tool
     */
    Circle(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle,QString mode);

    void createCircle(b2World world, QGraphicsScene levelscene, QPointF pos, qreal angle, b2BodyType type, b2CircleShape &circle);
    void draw();

    b2Body* body; ///< Box2D Body of object
    QGraphicsItem* graphics; ///< graphic of object
    bool drawBall1();

    void drawGraphics();
};

#endif // CIRCLE_H
