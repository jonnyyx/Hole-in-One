#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>



class picButton : public QPushButton
{
public:
    picButton(QPixmap _defaultpic, QPixmap _hoverpic);
    picButton(QPixmap _defaultpic, QPixmap _hoverpic, bool hover);

    QPixmap defaultpic;
    QPixmap hoverpic;

    bool hover;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    void setdefaultpic(QPixmap defaultpic);
    void sethoverpic(QPixmap hoverpic);


};

#endif // PICBUTTON_H
