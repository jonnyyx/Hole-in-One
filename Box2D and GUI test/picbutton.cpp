#include "picbutton.h"

picButton::picButton(QPixmap _defaultpic, QPixmap _hoverpic)
{
    defaultpic=_defaultpic;
    hoverpic=_hoverpic;
    QIcon ButtonIcon(hoverpic);

    setFixedSize(ButtonIcon.actualSize(ButtonIcon.availableSizes().first()));
    setIcon(ButtonIcon);
    setIconSize(ButtonIcon.availableSizes().first());
    setAttribute(Qt::WA_TranslucentBackground, false);

    /*!Hovering mouse*/
   setMouseTracking(true);

}


void picButton::enterEvent(QEvent *event)
{
     /*!when hovering -> change pic*/
    QIcon ButtonIcon(defaultpic);
    setIcon(ButtonIcon);
    qDebug("Hover");

}

void picButton::leaveEvent(QEvent *event)
{
     /*!Change pic back*/
    QIcon ButtonIcon(hoverpic);
    setIcon(ButtonIcon);
    qDebug("LEave");
}

