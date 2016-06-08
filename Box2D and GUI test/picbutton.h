#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>

class GUI;
class MeinElement;
class MainWindow;
class Button;
class picButton : public QPushButton
{
public:
    picButton(QPixmap _defaultpic, QPixmap _hoverpic);

    QPixmap defaultpic;
    QPixmap hoverpic;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);






};

#endif // PICBUTTON_H
