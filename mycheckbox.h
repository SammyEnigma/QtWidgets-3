#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>
#include <QMouseEvent>
#include <QtWidgets>


class MyCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    explicit MyCheckBox(QWidget* parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual bool event(QEvent *event) override;
};

#endif // MYCHECKBOX_H
