#include "mainwindow.h"
#include <QGraphicsTextItem>

Button::Button(QString buttonName, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    /*Rectangle for buttons!*/
    setRect(0,0,250,80);
    QBrush buttonBrush;
     /*!solid color*/
    buttonBrush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
     /*!now set the brush*/
    setBrush(buttonBrush);

     /*!Text on the scene*/
    text = new QGraphicsTextItem(buttonName, this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(x,y);

     /*!Hovering mouse*/
    setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
     /*!when hovering -> change Color*/
    QBrush buttonBrush;
    buttonBrush.setStyle(Qt::SolidPattern);
    buttonBrush.setColor(Qt::red);
    setBrush(buttonBrush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
     /*!Change color Back*/
    QBrush buttonBrush;
    buttonBrush.setStyle(Qt::SolidPattern);
    buttonBrush.setColor(Qt::darkRed);
    setBrush(buttonBrush);
}

void Button::displayMenu()
{

}
