#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <button.h>
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

<<<<<<< HEAD
    void showGuiagain();


=======
>>>>>>> 801c904528106710f2a95fb1cc148f9cc6f4ff9b
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
