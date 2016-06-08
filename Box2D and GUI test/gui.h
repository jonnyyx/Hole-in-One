#ifndef GUI_H
#define GUI_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <button.h>
#include <picbutton.h>


class GUI : public QGraphicsView
{
    Q_OBJECT

public:
    GUI(QWidget* parent=NULL);  //constructor

    void displayGUI();

    QGraphicsScene* scene;  //attributes

    picButton* mutepicButton;

    bool ismute;

public slots:
    void levelMenu();
    void highscore();
    void back();
    void showLevel1();
    void help();
    void mute();

private:


};

#endif // GUI_H
