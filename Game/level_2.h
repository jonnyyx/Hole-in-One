#ifndef LEVEL_2_H
#define LEVEL_2_H
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
#include "recyclebingraphics.h"
#include "circle.h"
#include "gui.h"
#include <QItemSelection>
#include <paperball.h>
#include "triangle.h"
#include "picbutton.h"
#include "block.h"
#include "trampoline.h"




#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO

class Level_2 : public QGraphicsView
{
    Q_OBJECT

public:
    Level_2();
    //void displayLevel();

    std::vector<Block*> vectb;
    std::vector<Triangle*> vectt;

public slots:
    void update();
    void startLevel();
    void pauseLevel();
    void resumeLevel();
    void addRectangle();
    void addCircle();
    void addTriangle();
    void reset();


    void rotateLeft();
    void rotateRight();
//    void enableRotation();
//    void disableRotation();


    void getTime();
    void highscoreCounter();



private:

    b2World* myWorld2;
    QGraphicsScene* level2;
    QGraphicsItem* backgnd;

    bool newhighscore=false;
    void saveLevel();
    QList <QString> levelenab;


    //Elements to add
    Block* addblock1;
    Block* addblock2;


    RecycleBin* recyclebin1;
    RecycleBin* recyclebin2;
    RecycleBinGraphics* recyclebin3;
    Triangle* addtriangle1;
    Triangle* addtriangle2;

    Circle* addcircle1;
    Circle* addcircle2;

    Trampoline* trampoline1;
    Trampoline* trampoline2;


    //fixed Elements

    Paperball* ball;
    Circle* obstaclescircle1;
    Circle* obstaclescircle2;
    Circle* obstaclescircle3;
    Circle* obstaclescircle4;
    Circle* obstaclescircle5;
    Circle* obstaclescircle6;
    Circle* obstaclescircle7;
    Circle* obstaclescircle8;
    Circle* obstaclescircle9;
    Circle* obstaclescircle10;
    Circle* obstaclescircle11;
    Circle* obstaclescircle12;
    Circle* obstaclescircle13;
    Circle* obstaclescircle14;
    Circle* obstaclescircle15;
    Circle* obstaclescircle16;
    Circle* obstaclescircle17;
    Circle* obstaclescircle18;
    Circle* obstaclescircle19;
    Circle* obstaclescircle20;
    Circle* obstaclescircle21;
    Circle* obstaclescircle22;
    Circle* obstaclescircle23;
    Circle* obstaclescircle24;
    Circle* obstaclescircle25;
    Circle* obstaclescircle26;
    Circle* obstaclescircle27;
    Circle* obstaclescircle28;
    Circle* obstaclescircle29;
    Circle* obstaclescircle30;
    Circle* obstaclescircle31;
    Circle* obstaclescircle32;
    Circle* obstaclescircle33;
    Circle* obstaclescircle34;
    Circle* obstaclescircle35;
    Circle* obstaclescircle36;
    Circle* obstaclescircle37;
    Circle* obstaclescircle38;
    Circle* obstaclescircle39;
    Circle* obstaclescircle40;
    Circle* obstaclescircle41;
    Circle* obstaclescircle42;
    Circle* obstaclescircle43;
    Circle* obstaclescircle44;
    Circle* obstaclescircle45;
    Circle* obstaclescircle46;
    Circle* obstaclescircle47;
    Circle* obstaclescircle48;
    Circle* obstaclescircle49;
    Circle* obstaclescircle50;

    Block* obstaclesrec1;
    Block* obstaclesrec2;
    Block* obstaclesrec3;
    Block* obstaclesrec4;
    Block* obstaclesrec5;
    Block* obstaclesrec6;
    Block* obstaclesrec7;
    Block* obstaclesrec8;
    Block* obstaclesrec9;
    Block* obstaclesrec10;
    Block* obstaclesrec11;
    Block* obstaclesrec12;
    Block* obstaclesrec13;
    Block* obstaclesrec14;
    Block* obstaclesrec15;
    Block* obstaclesrec16;
    Block* obstaclesrec17;
    Block* obstaclesrec18;
    Block* obstaclesrec19;

    Triangle* obstacletriangle1;
    Triangle* obstacletriangle2;
    Triangle* obstacletriangle3;
    Triangle* obstacletriangle4;
    Triangle* obstacletriangle5;
    Triangle* obstacletriangle6;
    Triangle* obstacletriangle7;
    Triangle* obstacletriangle8;
    Triangle* obstacletriangle9;
    Triangle* obstacletriangle10;
    Triangle* obstacletriangle11;


    MeinElement* bottom;
    MeinElement* umrandung1;
    MeinElement* umrandung2;
    MeinElement* msgbox;

    QTimer* timer;
    int anzahl;
    b2Vec2 positionElem;
    picButton* bt_start;
    picButton* bt_pause;
    picButton* bt__resume;
    QElapsedTimer leveltime_elapsed;
    QTime leveltime_normal;
    picButton* bt__rect;
    picButton* bt__circle;
    picButton* bt__triangle;

    picButton* bt__reset;
    picButton* bt__left;
    picButton* bt__right;

    int counterRec = 0;
    int counterCircle=0;
    int counterTriangle=0;
    int highscore = 0;
    int counterTogether = 0;
    int leveltime;
    bool win = false;
    int counterTriangleangle1=0;
    int counterTriangleangle2=0;

    void showLevel();


};

#endif // LEVEL_2_H
