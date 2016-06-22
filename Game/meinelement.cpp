#include "meinelement.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>



MeinElement::MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal angle, qreal length, qreal width, b2BodyType type, qreal friction)
{
    b2PolygonShape polygon;
    polygon.SetAsBox(length/2, width/2, center, angle);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1.0;

    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=1.0;
    polygonFixtureDef.friction=friction;
    body->CreateFixture(&polygonFixtureDef);

    //  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
    //  poly->setVisible(true);


    int x=center.x-length/4;
    int y=center.y-width/4;

    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);

    drawRec(x+length/2,y+width/2);

}

MeinElement::MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal length, qreal width, b2BodyType type, qreal friction)
{
    b2PolygonShape polygon;
    polygon.SetAsBox(length, width, center,0);
    b2BodyDef myBodyDef;
    myBodyDef.type=type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.active = true;
    myBodyDef.gravityScale = 1.0;


    body=world->CreateBody(&myBodyDef);

    b2FixtureDef polygonFixtureDef;
    polygonFixtureDef.shape=&polygon;
    polygonFixtureDef.density=1.0;
    polygonFixtureDef.friction=friction;
    body->CreateFixture(&polygonFixtureDef);

//  QGraphicsPolygonItem *poly = new QGraphicsPolygonItem();
//  poly->setVisible(true);


    int x=center.x;
    int y=center.y;
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);


//  body->SetLinearVelocity(b2Vec2(0.0,0.0));
//  QPixmap bkgnd(":/new/prefix1/paper.png");
//  bkgnd.scaled(QSize(42,42));
//  graphics = scene->addPixmap(bkgnd);
}

MeinElement::MeinElement(b2World* world, QGraphicsScene* level, QPointF a, QPointF b, QPointF c, qreal angle, b2BodyType type, qreal friction){

    b2BodyDef myBodyDef;
    myBodyDef.type = type; // Unterscheidung zwischen Dynamic, Static and Kinematic Body
    myBodyDef.angle = angle;

    body = world->CreateBody(&myBodyDef);

    //set each vertex of polygon in an array
    b2Vec2 vertices[3];
    vertices[0].Set(a.x(), a.y());
    vertices[1].Set(b.x(), b.y());
    vertices[2].Set(c.x(), c.y());

    b2PolygonShape polygon;
    polygon.Set(vertices, 3); //pass array to the shape

    b2FixtureDef triangleFixtureDef;
    triangleFixtureDef.shape = &polygon; //change the shape of the fixture
    triangleFixtureDef.friction=friction;
    body->CreateFixture(&triangleFixtureDef); //add a fixture to the body

    QPolygonF triangle;
    triangle << a << b << c;
    graphics = level->addPolygon(triangle);

    graphics->setFlag(QGraphicsItem::ItemIsMovable,true);
}

MeinElement::MeinElement(QGraphicsScene *level, QPointF center, qreal length, qreal width)
{
    int x=center.x();
    int y=center.y();
    QRectF polyf(QPoint(x,y),QSize(length,width));
    graphics = level->addRect(polyf);
    QPixmap bk(":/pic/white.png");
    bk.scaled(QSize(length, width));
    white = level->addPixmap(bk);
    white->setPos(center.x(),center.y());

    //Aplause for Win
    applause = new QMediaPlayer();
    applause->setMedia(QUrl("qrc:/pic/applause.mp3"));
    applause->setVolume(100);
    applause->play();
}

 void MeinElement::draw()
 {
     b2Vec2 v=body->GetPosition();

     graphics->setPos(QPointF(v.x,v.y));
     //qreal a=body->GetAngle();

 }


 void MeinElement::drawRec(int x,int y){

     graphics->setPos(QPointF(x,y));
     qreal a=body->GetAngle();
     graphics->setRotation(a);

 }

 void MeinElement::drawBottom(){
     b2Vec2 v=body->GetPosition();
     graphics->setPos(QPointF(v.x,v.y));
 }

 void MeinElement::drawGraphics(){
     QPointF v=graphics->pos();
     body->SetTransform(b2Vec2(v.x(),v.y()),body->GetAngle());
 }

