#include "CCheckBoxTabItem.h"

CCheckBoxTabItem::CCheckBoxTabItem(QWidget *parent) : QWidget(parent)
{
    m_pLayout = new QVBoxLayout(this);
    setLayout(m_pLayout);

    this->InitCheckBox();

    m_pEventFilter = new CKeyPressFater(this);
}

void CCheckBoxTabItem::InitCheckBox()
{
    m_pMyCheckBox = new MyCheckBox();
    m_pMyCheckBox->setText("checkbox");
    m_pLayout->addWidget(m_pMyCheckBox);
}

void CCheckBoxTabItem::InstallCustomEventFilter()
{
    m_pEventFilter = new CKeyPressFater(this);
    QCoreApplication::instance()->installEventFilter(m_pEventFilter);
    QCoreApplication::instance()->sendEvent(m_pMyCheckBox, new QMouseEvent(QEvent::MouseButtonPress, mapFromGlobal(this->pos()), Qt::LeftButton, Qt::NoButton, Qt::NoModifier));
    //ui->pushButton->installEventFilter(m_pEventFilter);
    //ui->listView->installEventFilter(m_pEventFilter);
}
