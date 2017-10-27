#include "CToolBoxTabItem.h"

CToolBoxTabItem::CToolBoxTabItem(QWidget *parent) : QToolBox(parent)
{
    m_pLayout = new QVBoxLayout(this);
    //this->setLayout(m_pLayout);
    this->setStyleSheet("background: rgb(104, 104, 104);");
    this->InitToolBox();

    connect(this, SIGNAL(currentChanged(int)), this, SLOT(onCurrentChanged(int)));
}

void CToolBoxTabItem::onCurrentChanged(int nIndex)
{
    QString strText = itemText(nIndex);
    qDebug() << strText;
}

void CToolBoxTabItem::InitToolBox()
{
    User user[3][5] =
    {
        {
            {true, u8"香香公主", ":/QQ/1", u8"金庸笔下的第一美女"},
            {true, u8"小龙女", ":/QQ/2", u8"玉女心经"},
            {true, u8"王语嫣", ":/QQ/3", u8"熟读各派武学秘笈"},
            {false, u8"赵敏", ":/QQ/4", u8"大元第一美人"},
            {false, u8"周芷若", ":/QQ/5", u8"光复汉家河山，光大峨嵋"}
        },

        {
            {true, u8"萧峰", ":/QQ/6", u8"丐帮帮主 - 智勇双全、胆略过人、豪迈飒爽"},
            {true, u8"令狐冲", ":/QQ/8", u8"独孤九剑"},
            {true, u8"杨过", ":/QQ/9", u8"黯然销魂掌"},
            {false, u8"郭靖", ":/QQ/7", u8"降龙十八掌"},
            {false, u8"胡一刀", ":/QQ/10", u8"辽东大侠"}
        },

        {
            {true, u8"金轮法王", ":/QQ/11", u8"龙象般若功"},
            {true, u8"丁春秋", ":/QQ/13", u8"星宿老仙，法力无边"},
            {false, u8"裘千仞", ":/QQ/12", u8"铁掌水上飘"},
            {false, u8"成昆", ":/QQ/14", u8"混元霹雳手"},
            {false, u8"李莫愁", ":/QQ/15", u8"冰魄银针，杀人如麻"}
        }
    };

    QStringList groupList;
    groupList << u8"大美女" << u8"大英雄" << u8"大恶人";

    //  初始化列表
    for(int i = 0; i < sizeof(user)/sizeof(user[0]); ++i)
    {
        QGroupBox* pGroupBox = new QGroupBox(this);
        pGroupBox->setStyleSheet("background: rgb(70, 70, 70);");
        QVBoxLayout* pLayout = new QVBoxLayout(pGroupBox);
        pLayout->setSpacing(10);
        pLayout->setContentsMargins(10, 10, 10, 10);

        for(auto item : user[i])
        {
            QWidget* pWidget = InitWidget(item);
            pLayout->addWidget(pWidget);
        }
        pLayout->addStretch();

        //  添加分组
        addItem(pGroupBox, groupList.at(i));
    }

    //m_pLayout->addWidget();
}

QWidget* CToolBoxTabItem::InitWidget(const CToolBoxTabItem::User &user)
{
    //  图标
    QLabel* pIconLabel = new QLabel(this);
    pIconLabel->setPixmap(QPixmap(user.strIcon));

    //  名称
    QLabel* pNameLabel = new QLabel(user.strNmae, this);
    pNameLabel->setStyleSheet(QString("color: %1").arg(user.bVIP ? "red" : "white"));   //  vip为红色

    //  描述
    QLabel* pDescLabel = new QLabel(user.strDesc, this);
    pDescLabel->setStyleSheet("color: gray");

    QVBoxLayout* pVLayout = new QVBoxLayout();
    pVLayout->addStretch();
    pVLayout->addWidget(pNameLabel);
    pVLayout->addWidget(pDescLabel);
    pVLayout->addStretch();
    pVLayout->setSpacing(5);
    pVLayout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pHLayout->addWidget(pIconLabel);
    pHLayout->addLayout(pVLayout);
    pHLayout->addStretch();
    pHLayout->setContentsMargins(0, 0, 0, 0);

    QWidget* pWidget = new QWidget(this);
    pWidget->setLayout(pHLayout);

    return pWidget;
}
