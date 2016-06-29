#ifndef RECYCLEBINGRAPHICS2_H
#define RECYCLEBINGRAPHICS2_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

/*!
 * \brief The RecycleBinGraphics class
 */
class RecycleBinGraphics {

public:
    RecycleBinGraphics(QGraphicsScene *level);

    QGraphicsItem* graphics; ///<Graphic of Recyclebinobject
};

#endif // RECYCLEBIN2_H
