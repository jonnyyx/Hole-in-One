#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <picbutton.h>

/*!
 * \brief The GUI class
 */
class GUI : public QGraphicsView
{
    Q_OBJECT

public:
    GUI(QWidget* parent=NULL);  //constructor

    void displayGUI();
     void checkLevel();
    QGraphicsScene* scene;  ///<Scene for GUI

    picButton* mutepicButton; ///<Mutepicbutton for Sound

    bool ismute = false; ///<Check if Sound is on or off


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

    QStringList levelenab; ///<List if Level is enabled or not
    QMediaPlayer *clicksnd; ///<Mediaplayer for Clicksound
    QMediaPlayer *bksnd; ///<Mediaplayer for Backgrounsound
    QMediaPlaylist *playlist; ///<Playlist for Backgroundsound

};

#endif // GUI_H
