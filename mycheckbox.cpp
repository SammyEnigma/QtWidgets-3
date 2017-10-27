#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QWidget *parent) :
    QCheckBox(parent)
{

}

void MyCheckBox::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug("Press LeftButton");
    }

    QCheckBox::mousePressEvent(e);
}

bool MyCheckBox::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* ke = static_cast<QKeyEvent*>(event);
        if(ke->key() == Qt::Key_Tab)
        {
            qDebug("MyCheckBox press Tab Key");
            return true;
        }
    }

    return QCheckBox::event(event);
}
