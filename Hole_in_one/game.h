#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game : public QGraphicsView
{
public:
    /*!Constructor of the Game*/
    Game(QWidget* parent=NULL);

    /*!public methods*/
    void displayMenu();

    /*!public Attributes*/
    QGraphicsScene* scene;

public slots:
    void levelMenu();
    void highscore();

};

#endif // GAME_H
