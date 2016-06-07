#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>


class picButton : public QPushButton
{
public:
    picButton(QPixmap defaultpic, QPixmap hoverpic);

    QPixmap defaultpic;
    QPixmap hoverpic;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);






};

#endif // PICBUTTON_H
