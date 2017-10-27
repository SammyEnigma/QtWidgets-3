#ifndef CSLIDERTABITEM_H
#define CSLIDERTABITEM_H

#include <QtWidgets>

class CSliderTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CSliderTabItem(QWidget *parent = nullptr);

signals:

public slots:

private:
    void InitSlider();

private:
    QVBoxLayout* m_pLayout;
};

#endif // CSLIDERTABITEM_H
