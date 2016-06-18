#include "recyclebingraphics.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QSize>
#include <qdebug.h>

RecycleBinGraphics::RecycleBinGraphics(QGraphicsScene *level)
{
    QPixmap bkgnd(":/pic/basket.png");
    bkgnd.scaled(QSize(86,86));
    graphics = level->addPixmap(bkgnd);
    graphics->setPos(498,505); //Set Graphic of Bin to desired position
    graphics->setFlag(QGraphicsItem::ItemIsMovable, false);
}
