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
    void levelMenu();   //for level menu-button
    void highscore();   //for highscore menu-button
    void back();        //for back-button
    void showLevel1();
    void help();        //for help-menu-button
    void mute();        //for mute-button
    void box();         //instruction-button for rect
    void circle();      //instruction-button for circle
    void triangle();    //instruction-button for triangle
    void spring();      //instruction-button for spring
    void trampoline();  //instruction-button for trampoline
    void conveyor();    //instruction-button for conveyor

private:


};

#endif // GUI_H
