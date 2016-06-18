#ifndef RECYCLEBINGRAPHICS2_H
#define RECYCLEBINGRAPHICS2_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>

class MainWindow;

class RecycleBinGraphics {

public:
    RecycleBinGraphics(QGraphicsScene *level);

    QGraphicsItem* graphics;
};

#endif // RECYCLEBIN2_H
