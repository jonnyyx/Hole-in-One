#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Box2D/Box2D.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "meinelement.h"
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>

#define framerate 1.0/35.0  //2 framerates eines grafik eines physic nötig //TODO

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    //void displayLevel();


public slots:
    void update();
    void startLevel();
    void pauseLevel();
    void resumeLevel();

private:
    b2CircleShape circle;
    b2World* myWorld;
    QGraphicsScene* level;
    MeinElement* elem;
    MeinElement* elem1;
    MeinElement* elem2;
    MeinElement* elem3;
    MeinElement* bottom;
    QTimer* timer;
    int anzahl;
    b2Vec2 positionElem;
    QPushButton* bt_start;
    QPushButton* bt_pause;
    QPushButton* bt__resume;
};

#endif // MAINWINDOW_H
