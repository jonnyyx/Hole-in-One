#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <picbutton.h>

class GUI : public QGraphicsView
{
    Q_OBJECT

public:
    GUI(QWidget* parent=NULL);  //constructor

    void displayGUI();
     void checkLevel();
    QGraphicsScene* scene;  //attributes

    picButton* mutepicButton;

    bool ismute = false;


public slots:
    void levelMenu();   //for level menu-button
    void highscore();   //for highscore menu-button
    void back();        //for back-button
    //void displayGUI();

    void showLevel1();
    void showLevel2();
    void showLevel3();
    void showLevel4();


    void showGuiagain();

    void help();        //for help-menu-button

    void box();         //instruction for rect
    void circle();      //instruction for circle
    void triangle();    //instruction for triangle

    //sound slots
    void mute();        //for mute-button
    void csnd();

private:

    QStringList levelenab;
    QMediaPlayer *clicksnd;
    QMediaPlayer *bksnd;
    QMediaPlaylist *playlist;

};

#endif // GUI_H
