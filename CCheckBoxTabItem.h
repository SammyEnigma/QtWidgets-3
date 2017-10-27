#ifndef CCHECKBOXTABITEM_H
#define CCHECKBOXTABITEM_H

#include <QtWidgets>

#include "mycheckbox.h"
#include "ckeypressfater.h"

class CCheckBoxTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CCheckBoxTabItem(QWidget *parent = nullptr);

signals:

public slots:

private:
    void InitCheckBox();

    void InstallCustomEventFilter();

private:
    QVBoxLayout* m_pLayout;
    MyCheckBox* m_pMyCheckBox;

private:
    CKeyPressFater* m_pEventFilter;
};

#endif // CCHECKBOXTABITEM_H
