#include "picbutton.h"

/*!
 * \brief picButton::picButton
 * \param _defaultpic
 * \param _hoverpic
 */
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
/*!
 * \brief picButton::picButton
 * \param _defaultpic picture of button
 * \param _hoverpic picture if you hover over button
 * \param _hover does mouse hover
 */
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
/*!
 * \brief picButton::enterEvent
 * \param event clickevent
 */
void picButton::enterEvent(QEvent *event)
{

    if(hover==true){
        /*!when hovering -> change pic*/
        QIcon ButtonIcon(hoverpic);
        setIcon(ButtonIcon);
    }

}
/*!
 * \brief picButton::leaveEvent
 * \param event mouse leave butto area
 */
void picButton::leaveEvent(QEvent *event)
{
    if(hover==true){
        /*!Change pic back*/
        QIcon ButtonIcon(defaultpic);
        setIcon(ButtonIcon);
    }


}
/*!
 * \brief picButton::setdefaultpic
 * \param _defaultpic insert picutre
 */
void picButton::setdefaultpic(QPixmap _defaultpic){
    defaultpic=_defaultpic;
    QIcon ButtonIcon(defaultpic);
    setIcon(ButtonIcon);

}
/*!
 * \brief picButton::sethoverpic
 * \param _hoverpic insert picture
 */
void picButton::sethoverpic(QPixmap _hoverpic){
    hoverpic=_hoverpic;
    QIcon ButtonIcon(hoverpic);
    setIcon(ButtonIcon);
}

