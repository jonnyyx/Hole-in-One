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
#include "recyclebingraphics.h"
#include "circle.h"
#include "gui.h"
#include <QItemSelection>
#include "paperball.h"

#include "block.h"




#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO

class Level_1 : public QGraphicsView
{
    Q_OBJECT

public:
    Level_1();
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
    void reset();
    void quitLevel();


    void rotateLeft();
    void rotateRight();
//    void enableRotation();
//    void disableRotation();


    void getTime();
    void highscoreCounter();



private:

    b2World* myWorld;
    QGraphicsScene* level;
    QGraphicsItem* backgnd;



    //Elements to add
    Block* elem4;
    Block* elem5;
    Block* elem6;

    RecycleBin* recyclebin1;
    RecycleBin* recyclebin2;
    RecycleBinGraphics* recyclebin3;
    Triangle* triangle1;

    QStringList levelenab;
    Circle* addcircle1;
    Circle* addcircle2;
    Circle* addcircle3;

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

    MeinElement* bottom;
    MeinElement* umrandung1;
    MeinElement* umrandung2;
    MeinElement* msgbox;

    QTimer* timer;
    QTimer* timer2;
    QPointF oldpos;
    int anzahl;
    b2Vec2 positionElem;
    QPushButton* bt_start;
    QPushButton* bt_pause;
    QPushButton* bt__resume;
    QElapsedTimer leveltime_elapsed;
    QTime leveltime_normal;
    QPushButton* bt__rect;
    QPushButton* bt__circle;
    QPushButton* bt__reset;
    QPushButton* bt__left;
    QPushButton* bt__right;
    int counterRec = 0;
    int counterCircle=0;
    int highscore = 0;
    int counterTogether = 0;
    int leveltime;
	bool win = false;
	
    void showLevel();


};

#endif // LEVEL_1_H
