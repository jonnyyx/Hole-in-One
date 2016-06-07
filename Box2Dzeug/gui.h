#ifndef GUI_H
#define GUI_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <button.h>

class MainWindow;

class GUI : public QGraphicsView
{
    Q_OBJECT

public:
    GUI(QWidget* parent=NULL);  //constructor

    void displayGUI();

    QGraphicsScene* scene;  //attributes

public slots:
    void levelMenu();
    void highscore();
    void back();
    void showLevel1();
};

#endif // GUI_H
