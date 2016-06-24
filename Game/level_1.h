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
#include <QMediaPlayer>
#include "block.h"




#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO
class GUI;
class Level_1 : public QGraphicsView
{
    Q_OBJECT

public:
    Level_1();
    //void displayLevel();

    std::vector<Block*> vectb;
    std::vector<Triangle*> vectt;

signals:
    void levelcompleted();

public slots:
    void update();
    void startLevel();
    void pauseLevel();
    void resumeLevel();
    void addRectangle();
    void addCircle();
    void reset();

    void closeLevel();
    void rotateLeft();
    void rotateRight();

    void getTime();
    void highscoreCounter();



private:

    b2World* myWorld;
    QGraphicsScene* level;
    QGraphicsItem* backgnd;
    QMediaPlayer *applause;
    bool newhighscore=false;
    void saveLevel();
    QList <QString> levelenab;
    void closeEvent(QCloseEvent *);
    //QAction *right;
    //QAction *left;


    //Elements to add
    Block* addblock1;
    Block* addblock2;
    Block* addblock3;

    RecycleBin* recyclebin1;
    RecycleBin* recyclebin2;
    RecycleBinGraphics* recyclebin3;

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
    Circle* obstaclescircle17;

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

    MeinElement* bottom;
    MeinElement* umrandung1;
    MeinElement* umrandung2;
    MeinElement* msgbox;       // Problem beim linksrotieren für 270 Grad -> 180 Grad & 90 Grad -> 0 Grad ok. Also 0 Grad -> 270 Grad funktioniert

    QTimer* timer;
    QTimer* timer2;
    QPointF oldpos;
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
    int highscore = 0;
    int counterTogether = 0;
    double leveltime;
    double leveltime1;
	bool win = false;
	
    void showLevel();


};

#endif // LEVEL_1_H
