#ifndef CTOLLBOXTABITEM_H
#define CTOLLBOXTABITEM_H

#include <QtWidgets>

class CToolBoxTabItem : public QToolBox
{
    Q_OBJECT
    struct User;
public:
    explicit CToolBoxTabItem(QWidget *parent = nullptr);

signals:

private slots:
    void onCurrentChanged(int nIndex);

private:
    void InitToolBox();
    QWidget* InitWidget(const User& user);

private:
    struct User
    {
        bool bVIP;
        QString strNmae;
        QString strIcon;
        QString strDesc;
    };

private:
    QVBoxLayout* m_pLayout;
};

#endif // CTOLLBOXTABITEM_H
