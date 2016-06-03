#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Box2D/Box2D.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "meinelement.h"

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    //void displayLevel();

public slots:
    void update();
    double getCurrentTimeInSecounds();

private:
    b2World* myWorld;
    QGraphicsScene* level;
    MeinElement* elem;
    MeinElement* elem1;
    QTimer* timer;
    int anzahl;
    b2Vec2 positionElem;

    const float updateInterval = 1.0f/60.0f;
    const double secoundsPerUpdate = 0.1;

};

#endif // MAINWINDOW_H
