#include "paperball.h"
#include "Box2D/Box2D.h"
#include <QGraphicsScene>

/*!
 * \brief Paperball::Paperball
 * \param world
 * \param level
 * \param position
 * \param angle
 * \param type
 * \param circle
 */
Paperball::Paperball(b2World *world, QGraphicsScene *level, QPointF position, qreal angle, b2BodyType type, b2CircleShape &circle)
{
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.position.Set(position.x(),position.y());
    myBodyDef.angle=angle;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef paperFixtureDef;
    paperFixtureDef.shape = &circle;
    paperFixtureDef.density = 0.8;
    paperFixtureDef.restitution = 0.6;
    body->CreateFixture(&paperFixtureDef);

//  body->SetLinearVelocity(b2Vec2(0.0,0.0));

    QPixmap bkgnd(":/pic/paper.png");
    bkgnd.scaled(QSize(42,42));
    graphics = level->addPixmap(bkgnd);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);

}

/*!
 * \brief Paperball::draw
 * connects the Graphics to the Box2D-Object
 */
void Paperball::draw()
{
    b2Vec2 v=body->GetPosition();

    graphics->setPos(QPointF(v.x,v.y));
    //qreal a=body->GetAngle();

}

/*!
 * \brief Paperball::drawBall1
 * connects the Graphics to the Box2D-Object
 * checkout if paperball fell into the recyclebin
 * \return
 */
bool Paperball::drawBall1()
{
    b2Vec2 v=body->GetPosition();
    //qreal a=body->GetAngle();
    //qDebug() << v.x << v.y;
    graphics->setPos(v.x,v.y);

    qreal dx=519;
    qreal dy=510;


    if ((v.x<=dx)&&(v.x>=518)&&(v.y>=dy)){ //set postition of win for level_1

        return true;
    }
    else{
        return false;
    }
}

/*!
 * \brief Paperball::drawBall2
 * connects the Graphics to the Box2D-Object
 * checkout if paperball fell into the recyclebin
 * \return
 */
bool Paperball::drawBall2()
{
    b2Vec2 v=body->GetPosition();
    //qreal a=body->GetAngle();
    //qDebug() << v.x << v.y;
    graphics->setPos(v.x,v.y);

    qreal dx=519;
    qreal dy=510;

     if ((v.x<=dx)&&(v.x>=518)&&(v.y>=dy)){ //set postition of win for level_1
       return true;
     }
     else{
       return false;
     }
}

/*!
 * \brief Paperball::drawGraphics
 * connects the Box2D-Object to the Graphics after relocation
 */
void Paperball::drawGraphics(){
    QPointF v=graphics->pos();
    body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
}

