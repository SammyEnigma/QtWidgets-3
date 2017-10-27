#ifndef CPUSHBUTTONTABITEM_H
#define CPUSHBUTTONTABITEM_H

//#include <QWidget>
#include <QtWidgets>

class CPushButtonTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CPushButtonTabItem(QWidget *parent = nullptr);

signals:

public slots:
    void onClicked();

private:
    void InitBtn();

private:
    QVBoxLayout* m_pLayout;
    QPushButton* m_pPushButton;
};

#endif // CPUSHBUTTONTABITEM_H
