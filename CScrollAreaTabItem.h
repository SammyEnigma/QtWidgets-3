#ifndef CSCROLLAREATABITEM_H
#define CSCROLLAREATABITEM_H

#include <QtWidgets>

class CScrollAreaTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CScrollAreaTabItem(QWidget *parent = nullptr);

signals:

public slots:

private:
    void InitScrollArea();

private:
    QVBoxLayout* m_pLayout;
};

#endif // CSCROLLAREATABITEM_H
