#include "CPushButtonTabItem.h"
#include "customdialog.h"

CPushButtonTabItem::CPushButtonTabItem(QWidget *parent) :
    QWidget(parent),
    m_pLayout(nullptr),
    m_pPushButton(nullptr)
{
    m_pLayout = new QVBoxLayout(this);
    setLayout(m_pLayout);

    this->InitBtn();
}

void CPushButtonTabItem::onClicked()
{
    qDebug() << "Enter...";
    CustomDialog* pDialog = new CustomDialog(this);
    pDialog->setWindowTitle(u8"半模式对话框");

    //  关键代码
    pDialog->setModal(true);
    pDialog->show();
}

void CPushButtonTabItem::InitBtn()
{
    m_pPushButton = new QPushButton("Cli&ck Me");
    m_pPushButton->setCheckable(true);  //  设置可选中
    //  设置图标、图标大小、文本
    m_pPushButton->setIcon(QIcon(":/Image/logo"));
    m_pPushButton->setIconSize(QSize(18, 18));
    m_pLayout->addWidget(m_pPushButton);

    //  连接信号与槽
    connect(m_pPushButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));

    //  btn可多选
    QPushButton* pBtn = new QPushButton("test");
    pBtn->setCheckable(true);
    m_pLayout->addWidget(pBtn);

    //  设置btn互斥
    QButtonGroup* pBtnGrp = new QButtonGroup(this);
    pBtnGrp->setExclusive(true);
    pBtnGrp->addButton(m_pPushButton);
    pBtnGrp->addButton(pBtn);
}
