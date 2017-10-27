#include "CSpinBoxTabItem.h"



CSpinBoxTabItem::CSpinBoxTabItem(QWidget *parent) : QWidget(parent)
{
    m_pLayout = new QVBoxLayout(this);
    this->setLayout(m_pLayout);

    this->InitSpinBox();
    this->InitSpecialSpinBox();
    this->InitCustomSpinBox();
    this->InitDoubleSpinBox();
}

void CSpinBoxTabItem::InitSpinBox()
{
    QSpinBox* pSpinBox = new QSpinBox(this);
    pSpinBox->setRange(20, 200);
    pSpinBox->setSingleStep(10);
    pSpinBox->setPrefix("$ ");
    pSpinBox->setSuffix(" %");
    pSpinBox->setWrapping(true);    //  开启循环

    //  由于valueChanged()是一个重载信号，所以需要进行参数类别区分
    connect(pSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int value)
            {
                qDebug() << "Value : " << value;
                qDebug() << "Text : "<< pSpinBox->text();
            });

    connect(pSpinBox, static_cast<void(QSpinBox::*)(const QString&)>(&QSpinBox::valueChanged),
            [=](const QString& text)
            {
                qDebug() << "Text Value : " << text;
                qDebug() << "Clean Text : " << pSpinBox->cleanText();
            });

    //  add into layout
    m_pLayout->addWidget(pSpinBox);
}

void CSpinBoxTabItem::InitSpecialSpinBox()
{
    QSpinBox *zoomSpinBox = new QSpinBox(this);
    zoomSpinBox->setRange(0, 1000);  // 范围
    zoomSpinBox->setSingleStep(10);  // 步长
    zoomSpinBox->setSuffix("%");  // 前缀
    zoomSpinBox->setSpecialValueText(u8"Automatic");  // 特殊文本值 只要当前值等于微调框的最小值时，将显示该文本，而不是一个数值
    zoomSpinBox->setValue(100);  // 当前值

    //  add into layout
    m_pLayout->addWidget(zoomSpinBox);
}

void CSpinBoxTabItem::InitCustomSpinBox()
{
    QSpinBox* iconSizeSpinBox = new IconSizeSpinBox(this);
    iconSizeSpinBox->setRange(1, 100);  // 范围
    iconSizeSpinBox->setSingleStep(10);  // 步长
    iconSizeSpinBox->setValue(10);  // 当前值

    //  add into layout
    m_pLayout->addWidget(iconSizeSpinBox);

    connect(iconSizeSpinBox, static_cast<void(QSpinBox::*)(const QString&)>(&QSpinBox::valueChanged),
            [=](const QString& text)
            {
                qDebug() << "Text Value : " << iconSizeSpinBox->text();
                qDebug() << "Clean Text : " << iconSizeSpinBox->cleanText();
                qDebug() << "Value : " << iconSizeSpinBox->value();
            });
}

void CSpinBoxTabItem::InitDoubleSpinBox()
{
    QDoubleSpinBox* pSpinBox = new QDoubleSpinBox(this);
    pSpinBox->setRange(0, 20);
    pSpinBox->setDecimals(3);
    pSpinBox->setSingleStep(0.005);

    connect(pSpinBox, static_cast<void(QDoubleSpinBox::*)(const QString&)>(&QDoubleSpinBox::valueChanged),
            [=](const QString& text)
    {
        qDebug() << text;
    });

    //  add into layout
    m_pLayout->addWidget(pSpinBox);
}
