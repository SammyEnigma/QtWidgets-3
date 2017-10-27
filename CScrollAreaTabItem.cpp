#include "CScrollAreaTabItem.h"

CScrollAreaTabItem::CScrollAreaTabItem(QWidget *parent) : QWidget(parent)
{
    m_pLayout = new QVBoxLayout(this);
    this->setLayout(m_pLayout);
    this->InitScrollArea();
}

void CScrollAreaTabItem::InitScrollArea()
{
    //////////////////////////////////////    手动调整     //////////////////////////////////////
    QLabel* pImageLabel = new QLabel(this);
    QPixmap pixmap(":/Image/logo");
    pixmap = pixmap.scaled(200, 200);
    pImageLabel->setPixmap(pixmap);
    pImageLabel->setAlignment(Qt::AlignCenter);     //  图片居中

    QScrollArea* pScrollArea = new QScrollArea(this);
    pScrollArea->setBackgroundRole(QPalette::Dark);     //  背景色
    pScrollArea->setWidget(pImageLabel);
    pScrollArea->setAlignment(Qt::AlignCenter); //  居中对齐
    pScrollArea->widget()->resize(260, 260);    //  手动调整大小，为了显示label白色背景

    //  add into layout
    m_pLayout->addWidget(pScrollArea);
    //////////////////////////////////////    手动调整     //////////////////////////////////////

    //////////////////////////////////////    自动调整     //////////////////////////////////////
    QLabel* pImageLabel2 = new QLabel(this);
    QPixmap pixmap2(":/Image/logo");
    pixmap2 = pixmap2.scaled(200, 200);
    pImageLabel2->setPixmap(pixmap2);
    pImageLabel2->setAlignment(Qt::AlignCenter);     //  图片居中

    QScrollArea* pScrollArea2 = new QScrollArea(this);
    pScrollArea2->setBackgroundRole(QPalette::Dark);     //  背景色
    pScrollArea2->setWidget(pImageLabel2);
    pScrollArea2->setAlignment(Qt::AlignCenter); //  居中对齐
    pScrollArea2->setWidgetResizable(true);    //  自动调整，为了显示label白色背景

    //  add into layout
    m_pLayout->addWidget(pScrollArea2);
    //////////////////////////////////////    自动调整     //////////////////////////////////////
}
