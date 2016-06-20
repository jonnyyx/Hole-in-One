#include "circle.h"
#include "Box2D/Box2D.h"
#include <QGraphicsScene>
#include <QDebug>

/*!
 * \brief Circle::Circle
 * \param world
 * \param level
 * \param position
 * \param angle
 * \param type
 * \param circle
 * \param mode
 */
Circle::Circle(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle,QString mode)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 0.8;
    circleFixtureDef.restitution = 0.6;
    body->CreateFixture(&circleFixtureDef);

//  body->SetLinearVelocity(b2Vec2(0.0,0.0));
    if(mode=="obs"){
        QPixmap bkgnd(":/pic/circle_obs.png");
        bkgnd.scaled(QSize(42,42));
        graphics = level->addPixmap(bkgnd);
        graphics->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    else if(mode=="tool"){
        QPixmap bkgnd(":/pic/circle_tool.png");
        bkgnd.scaled(QSize(42,42));
        graphics = level->addPixmap(bkgnd);
        graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
    }
    draw();
}

/*!
 * \brief Circle::draw
 * connects the Graphics to the Box2D-Object
 */
void Circle::draw()
{
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    //qreal a=body->GetAngle();

}

/*!
 * \brief Circle::drawBall1
 * connects the Graphics to the Box2D-Object
 * \return
 */
bool Circle::drawBall1()
{
    b2Vec2 v=body->GetPosition();
    //qreal a=body->GetAngle();
    //qreal grad=a*(180.0/3.14);
    //qDebug() << v.x << v.y;
    graphics->setPos(v.x,v.y);

    qreal dx=549;
    qreal dy=510;


    if ((v.x<=dx)&&(v.x>=518)&&(v.y>=dy)){ //set postition of win for level_1

        return true;
    }
    else{
        return false;
    }
}

/*!
 * \brief Circle::drawBall2
 * connects the Graphics to the Box2D-Object
 * \return
 */
bool Circle::drawBall2()
{
    b2Vec2 v=body->GetPosition();
    //qreal a=body->GetAngle();
    //qreal grad=a*(180.0/3.14);
    //qDebug() << v.x << v.y;
    graphics->setPos(v.x,v.y);

    qreal dx=549;
    qreal dy=510;

    if ((v.x<=dx)&&(v.x>=548)&&(v.y>=dy)){ //set postition of win for level_1
        return true;
    }
    else{
        return false;
    }
}

/*!
 * \brief Circle::drawGraphics
 * connects the Box2D-Object to the Graphics after relocation
 */
void Circle::drawGraphics(){
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
}

