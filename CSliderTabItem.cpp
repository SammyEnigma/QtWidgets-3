#include "CSliderTabItem.h"

CSliderTabItem::CSliderTabItem(QWidget *parent) : QWidget(parent)
{
    m_pLayout = new QVBoxLayout(this);
    this->setLayout(m_pLayout);
    this->InitSlider();
}

void CSliderTabItem::InitSlider()
{
    //////////////////////////////////////    Slider     //////////////////////////////////////
    int nMin = 0;
    int nMax = 200;
    int nStep = 10;

    //  微调框
    QSpinBox* pSpinBox = new QSpinBox(this);
    pSpinBox->setRange(nMin, nMax);
    pSpinBox->setSingleStep(nStep);

    //  滑动条
    QSlider* pSlider = new QSlider(this);
    pSlider->setOrientation(Qt::Horizontal);
    pSlider->setRange(nMin, nMax);
    pSlider->setSingleStep(nStep);
    pSlider->setTickPosition(QSlider::TicksAbove);
    pSlider->setTickInterval(10);

    //  连接信号槽（相互改变）
    connect(pSpinBox, SIGNAL(valueChanged(int)), pSlider, SLOT(setValue(int)));
    connect(pSlider, SIGNAL(valueChanged(int)), pSpinBox, SLOT(setValue(int)));

    // add into layout
    QHBoxLayout* pHor = new QHBoxLayout(this);
    pHor->addWidget(pSpinBox);
    pHor->addWidget(pSlider);
    m_pLayout->addLayout(pHor);

    pSpinBox->setValue(10);
    //////////////////////////////////////    Slider     //////////////////////////////////////

    //////////////////////////////////////    Progress     //////////////////////////////////////
    QProgressBar* pProgress = new QProgressBar(this);
    pProgress->setRange(0, 0);  //  繁忙状态

    //  add into layout
    QHBoxLayout* pHor2 = new QHBoxLayout(this);
    pHor2->addWidget(pProgress);
    m_pLayout->addLayout(pHor2);
    //////////////////////////////////////    Progress     //////////////////////////////////////
}
