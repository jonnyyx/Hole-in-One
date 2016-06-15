#ifndef GUI_H
#define GUI_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <button.h>
#include <picbutton.h>


class GUI : public QGraphicsView
{
    Q_OBJECT

public:
    GUI(QWidget* parent=NULL);  //constructor

    void displayGUI();

    QGraphicsScene* scene;  //attributes

    //for sound
    picButton* mutepicButton;
    QMediaPlayer * click;
    QMediaPlayer * win;
    QMediaPlayer * move;
    bool ismute;


public slots:
    void levelMenu();   //for level menu-button
    void highscore();   //for highscore menu-button
    void back();        //for back-button
    void showLevel1();
    void showLevel2();
    void help();        //for help-menu-button
    void mute();        //for mute-button
    void box();         //instruction-button for rect
    void circle();      //instruction-button for circle
    void triangle();    //instruction-button for triangle
    void spring();      //instruction-button for spring
    void trampoline();  //instruction-button for trampoline
    void conveyor();    //instruction-button for conveyor

private:
    void checkLevel();
    QStringList levelenab;

};

#endif // GUI_H
