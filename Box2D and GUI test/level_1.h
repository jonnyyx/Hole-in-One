#ifndef LEVEL_1_H
#define LEVEL_1_H
#include"Box2D/Box2D.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "meinelement.h"
#include "triangle.h"
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QElapsedTimer>
#include <QTime>
#include "recyclebin.h"
#include "circle.h"
#include "gui.h"

#include <block.h>


#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO

class Level_1 : public QGraphicsView
{
    Q_OBJECT

public:
    Level_1(QWidget *parent = 0);
    //void displayLevel();


public slots:
    void update();
    void startLevel();
    void pauseLevel();
    void resumeLevel();
    void addRectangle();
    void addCircle();

    void reset();
    void getTime();


private:

    b2World* myWorld;
    QGraphicsScene* level;
    //Elements to add

    Block* elem4;
    Block* elem5;
    Block* elem6;

	RecycleBin* recyclebin1;
    RecycleBin* recyclebin2;
    Triangle* triangle1;
    void highscoreCounter();


    Circle* addcircle1;
    Circle* addcircle2;
    Circle* addcircle3;

    //fixed Elements

    Circle* ball;
    Circle* obstaclescircle1;
    Circle* obstaclescircle2;


    Block* rechteck1;

    MeinElement* bottom;
    MeinElement* umrandung1;
    MeinElement* umrandung2;

    QTimer* timer;
    int anzahl;
    b2Vec2 positionElem;
    QPushButton* bt_start;
    QPushButton* bt_pause;
    QPushButton* bt__resume;
    QElapsedTimer leveltime_elapsed;
    QPushButton* bt__rect;
    QPushButton* bt__circle;
    QPushButton* bt_reset;
    int counterRec = 0;
    int counterCircle=0;
    int highscore = 0;
    int counterTogether = 0;
    int leveltime = 0;

    void showLevel();
};

#endif // LEVEL_1_H
