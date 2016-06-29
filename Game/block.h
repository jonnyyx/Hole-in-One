#ifndef BLOCK_H
#define BLOCK_H
#include"Box2D/Box2D.h"
#include"QGraphicsItem"
#include<QPointF>
#include "meinelement.h"

class MainWindow;

/*!
 * \brief The Block class
 */
class Block : public QObject
{

public:
    /*!
     * \brief Block::Block
     * \param world : Box2D world for physic engine
     * \param level : Scene for the game
     * \param center : is the centerposition of the block
     * \param m_angle: angle for the block
     * \param m_length : length bock
     * \param m_width : width block
     * \param type : Box2D type of the Bbock(if it's static or dynamic)
     * \param friction : friction for the Block
     * \param mode : is it a obstacle or a tool
     */
    Block(b2World *world, QGraphicsScene *level, b2Vec2 center, qreal m_angle, qreal m_length, qreal m_width, b2BodyType type, qreal friction, QString mode);
    void drawGraphics();


    qreal length; ///< lenth of the object
    qreal width; ///< width of the object
    qreal angle; ///< angle of the object
    b2Body* body; ///< Box2D Body of object
    QGraphicsItem* graphics; ///< graphic of object





private:

};

#endif // BLOCK_H
