#ifndef LEVEL_3_H
#define LEVEL_3_H
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
#include "trampoline.h"
#include "block.h"




#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO

class Level_3 : public QGraphicsView
{
    Q_OBJECT

public:
    Level_3();

signals:
    void levelcompleted();

public slots:
    void update();
    void startLevel();
    void pauseLevel();
    void resumeLevel();
    void addRectangle();
    void addCircle();
    void addTriangle();
    void reset();

    void closeLevel();
    void rotateLeft();
    void rotateRight();



    void getTime();
    void highscoreCounter();



private:

    b2World* myWorld3;///< Scene of Box2D
    QGraphicsScene* level3;///<Scene for QGraphicsItem
    QGraphicsItem* backgnd;///< Background of level

    bool newhighscore=false;///< is it a new Highscore?
    void saveLevel();
    QList <QString> levelenab;///< read out and rewrite file for Highscore
    void closeEvent(QCloseEvent *);

    //Elements to add
    Block* addblock1;///< Tool rectangle
    Block* addblock2;///< Tool rectangle


    RecycleBin* recyclebin1;///< build the goal
    RecycleBin* recyclebin2;///< build the goal
    RecycleBinGraphics* recyclebin3;///< graphic for the goal

    Triangle* addtriangle1;///< Tool triangle
    Triangle* addtriangle2;///< Tool triangle

    Circle* addcircle1;///< Tool circle
    Circle* addcircle2;///< Tool circle


    //fixed Elements

    Paperball* ball;///< game ball
    Circle* obstaclescircle1;///< obstacle circle
    Circle* obstaclescircle2;///< obstacle circle
    Circle* obstaclescircle3;///< obstacle circle
    Circle* obstaclescircle4;///< obstacle circle
    Circle* obstaclescircle5;///< obstacle circle
    Circle* obstaclescircle6;///< obstacle circle
    Circle* obstaclescircle7;///< obstacle circle
    Circle* obstaclescircle8;///< obstacle circle
    Circle* obstaclescircle9;///< obstacle circle
    Circle* obstaclescircle10;///< obstacle circle
    Circle* obstaclescircle11;///< obstacle circle
    Circle* obstaclescircle12;///< obstacle circle
    Circle* obstaclescircle13;///< obstacle circle
    Circle* obstaclescircle14;///< obstacle circle
    Circle* obstaclescircle15;///< obstacle circle
    Circle* obstaclescircle16;///< obstacle circle
    Circle* obstaclescircle17;///< obstacle circle
    Circle* obstaclescircle18;///< obstacle circle
    Circle* obstaclescircle19;///< obstacle circle
    Circle* obstaclescircle20;///< obstacle circle

    Block* obstaclesrec1;///< obstacle rectangle
    Block* obstaclesrec2;///< obstacle rectangle
    Block* obstaclesrec3;///< obstacle rectangle
    Block* obstaclesrec4;///< obstacle rectangle
    Block* obstaclesrec5;///< obstacle rectangle
    Block* obstaclesrec6;///< obstacle rectangle
    Block* obstaclesrec7;///< obstacle rectangle

    Trampoline* trampoline1;///< trampolin as obstacle
    Trampoline* trampoline2;///< trampolin as obstacle

    Triangle* obstacletriangle1;///< obstacle triangle
    Triangle* obstacletriangle2;///< obstacle triangle
    Triangle* obstacletriangle3;///< obstacle triangle
    Triangle* obstacletriangle4;///< obstacle triangle
    Triangle* obstacletriangle5;///< obstacle triangle



    MeinElement* bottom;///< bottom of playground
    MeinElement* umrandung1;///< border of playground, ball cannot roll out of screen
    MeinElement* umrandung2;///< border of playground, ball cannot roll out of screen
    MeinElement* msgbox;///< messagebox at the end of game

    QTimer* timer;///< timer for starting game

    picButton* bt_start;///< button for starting game
    picButton* bt_pause;///< button for pause game
    picButton* bt__resume;///< button for resume game
    QElapsedTimer leveltime_elapsed;///< time of finishing level for highscore
    QTime leveltime_normal;///< time in millisecond after starting game
    picButton* bt__rect;///< button for add tool rectangle
    picButton* bt__circle;///< button for add tool circle
    picButton* bt__triangle;///< button for add tool triangle

    picButton* bt__reset;///< button for reset game
    picButton* bt__left;///< button for rotating left selected tool object
    picButton* bt__right;///< button for rotating right selected tool object


    int counterRec = 0;///< counter for added tool rectangles
    int counterCircle=0;///< counter for added tool circles
    int counterTriangle=0;///< counter for added tool triangles
    int highscore = 0;///< counter for highscore
    int counterTogether = 0;///< counting score
    double leveltime;///< time for level
    bool win = false;///< is ball in goal
    int counterTriangleangle1=0;///< rotation of tool triangle 1
    int counterTriangleangle2=0;///< rotation of tool triangle 2

    void showLevel();


};

#endif // LEVEL_3_H
