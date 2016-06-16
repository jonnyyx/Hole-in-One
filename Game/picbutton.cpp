#include "picbutton.h"

picButton::picButton(QPixmap _defaultpic, QPixmap _hoverpic)
{
    defaultpic=_defaultpic;
    hoverpic=_hoverpic;
    QIcon ButtonIcon(defaultpic);

    hover=true;

    setFixedSize(ButtonIcon.actualSize(ButtonIcon.availableSizes().first()));
    setIcon(ButtonIcon);
    setIconSize(ButtonIcon.availableSizes().first());
    setAttribute(Qt::WA_TranslucentBackground, false);

    /*!Hovering mouse*/
    setMouseTracking(true);

}

picButton::picButton(QPixmap _defaultpic, QPixmap _hoverpic, bool _hover)
{
    defaultpic=_defaultpic;
    hoverpic=_hoverpic;
    QIcon ButtonIcon(defaultpic);

    hover=_hover;

    setFixedSize(ButtonIcon.actualSize(ButtonIcon.availableSizes().first()));
    setIcon(ButtonIcon);
    setIconSize(ButtonIcon.availableSizes().first());
    setAttribute(Qt::WA_TranslucentBackground, false);

    /*!Hovering mouse*/
    setMouseTracking(true);

}

void picButton::enterEvent(QEvent *event)
{

    if(hover==true){
        /*!when hovering -> change pic*/
        QIcon ButtonIcon(hoverpic);
        setIcon(ButtonIcon);
    }

}

void picButton::leaveEvent(QEvent *event)
{
    if(hover==true){
        /*!Change pic back*/
        QIcon ButtonIcon(defaultpic);
        setIcon(ButtonIcon);
    }


}

void picButton::setdefaultpic(QPixmap _defaultpic){
    defaultpic=_defaultpic;
    QIcon ButtonIcon(defaultpic);
    setIcon(ButtonIcon);

}
void picButton::sethoverpic(QPixmap _hoverpic){
    hoverpic=_hoverpic;
    QIcon ButtonIcon(hoverpic);
    setIcon(ButtonIcon);
}

