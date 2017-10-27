#include "ckeypressfater.h"
#include <QEvent>
#include <QKeyEvent>

CKeyPressFater::CKeyPressFater(QObject *parent) : QObject(parent)
{

}

bool CKeyPressFater::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        qDebug("Ate key press %d", keyEvent->key());
        return true;
    }
    else
        return QObject::eventFilter(watched, event);
}
