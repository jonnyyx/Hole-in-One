#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QGraphicsRectItem{

public:
    /*!constructor of Buttons in MainMenu*/
    Button(QString buttonName, QGraphicsItem* parent=NULL);
    /*!functions in MainMenu*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
private:
    QString buttonText;

};


#endif // MAINWINDOW_H
