#ifndef MEINELEMENT_H
#define MEINELEMENT_H
#include "Box2D/Box2D.h"
#include "QGraphicsItem"
#include <QMediaPlayer>
#include <QPointF>

class MainWindow;

class MeinElement: public QObject
{
public:
    /*!
     * \brief MeinElement::MeinElement
     * \param world : Box2D world for physic engine
     * \param level : Scene for the game
     * \param center : center of the object
     * \param length : length of the object
     * \param width : Breite of the object
     * \param type : Box2D type of the Bbock(if it's static or dynamic)
     * \param friction : friction for the Block
     */
    MeinElement(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal length, qreal width, b2BodyType type, qreal friction);

    /*!
     * \brief MeinElement::MeinElement
     * \param level : Scene for the game
     * \param center : Center of object (coordinates)
     * \param length : length of object
     * \param width : length of object
     * Message Box Background for 'Finished Level'
     */
    MeinElement(QGraphicsScene *level, QPointF center, qreal length, qreal width);

    void drawBottom();

    b2Body* body; ///< Box2D Body of object
    QGraphicsItem* graphics; ///< graphic of object
    QGraphicsItem* white; ///< graphic of box, where 'Finished' message is written.
    QMediaPlayer* applause; ///< Soundplayer for successfully finished level




};

#endif // MEINELEMENT_H
