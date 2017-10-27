#include "CLineEditTabItem.h"

#include <QtCore>

CLineEditTabItem::CLineEditTabItem(QWidget *parent) : QWidget(parent)
{
    m_pLayout = new QVBoxLayout(this);
    this->setLayout(m_pLayout);
    this->InitLineEdit();
}

void CLineEditTabItem::onLineEditActionTriggered(bool checked)
{
    QString strText = m_pLineEdit->text();
    m_pLabel->setText(QString(u8"输入内容：%1").arg(strText));
}

void CLineEditTabItem::onLineEditReturnPressed()
{
    this->onLineEditActionTriggered(false);
}

void CLineEditTabItem::onSearchByLayout()
{
    QString strText = m_pSearchLineEdit->text();
    if(!strText.isEmpty())
    {
        QMessageBox::information(this, u8"搜索", QString(u8"搜索内容为%1").arg(strText));
    }
}

void CLineEditTabItem::InitLineEdit()
{
    this->InitEchoEdit();
    this->InitCustomSearchEdit();
    this->InitValidatorEdit();
    this->InitInputMaskEdit();
    this->InitLayoutSearchLineEdit();
}

void CLineEditTabItem::InitEchoEdit()
{
    //////////////////////////////////////    EchoMode     //////////////////////////////////////
    QLineEdit* pNormalLineEdit = new QLineEdit();
    QLineEdit* pNoEchoLineEdit = new QLineEdit();
    QLineEdit* pPwdLineEdit = new QLineEdit();
    QLineEdit* pPwdEchoOnEditLineEdit = new QLineEdit();

    pNormalLineEdit->setPlaceholderText("Normal");
    pNoEchoLineEdit->setPlaceholderText("NoEcho");
    pPwdLineEdit->setPlaceholderText("Password");
    pPwdEchoOnEditLineEdit->setPlaceholderText("PasswordEchoOnEdit");

    //  设置显示效果
    pNormalLineEdit->setEchoMode(QLineEdit::Normal);
    pNoEchoLineEdit->setEchoMode(QLineEdit::NoEcho);
    pPwdLineEdit->setEchoMode(QLineEdit::Password);
    pPwdEchoOnEditLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    //  添加进布局
    m_pLayout->addWidget(pNormalLineEdit);
    m_pLayout->addWidget(pNoEchoLineEdit);
    m_pLayout->addWidget(pPwdLineEdit);
    m_pLayout->addWidget(pPwdEchoOnEditLineEdit);
    //////////////////////////////////////    EchoMode     //////////////////////////////////////
}

void CLineEditTabItem::InitCustomSearchEdit()
{
    //////////////////////////////////////    自定义搜索框     //////////////////////////////////////
    m_pLineEdit = new QLineEdit();
    m_pLabel = new QLabel();

    m_pLineEdit->setPlaceholderText(u8"请输入搜索内容");

    //  添加头action
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setEnabled(false);
    pLeadingAction->setIcon(QIcon(":/Image/leading"));
    m_pLineEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);

    //  添加尾action
    QAction* pTrailAction = m_pLineEdit->addAction(QIcon(":/Image/search"), QLineEdit::TrailingPosition);
    connect(pTrailAction, SIGNAL(triggered(bool)), this, SLOT(onLineEditActionTriggered(bool)));
    connect(m_pLineEdit, SIGNAL(returnPressed()), this, SLOT(onLineEditReturnPressed()));

    //  添加进布局
    m_pLayout->addWidget(m_pLineEdit);
    m_pLayout->addWidget(m_pLabel);
    //////////////////////////////////////    自定义搜索框     //////////////////////////////////////
}

void CLineEditTabItem::InitValidatorEdit()
{
    //////////////////////////////////////    验证器     //////////////////////////////////////
    QLineEdit* pIntLineEdit = new QLineEdit();
    QLineEdit* pDoubleLineEdit = new QLineEdit();
    QLineEdit* pValidatorLineEdit = new QLineEdit();

    pIntLineEdit->setPlaceholderText(u8"整型");
    pDoubleLineEdit->setPlaceholderText(u8"浮点型");
    pValidatorLineEdit->setPlaceholderText(u8"字母和数字");

    //  整型 范围[1, 99]
    QIntValidator* pIntValidator = new QIntValidator(1, 99, this);
    pIntLineEdit->setValidator(pIntValidator);

    //  浮点型 范围[-360, 360]精度，小数点后2位
    QDoubleValidator* pDoubleValidator = new QDoubleValidator(-360, 360, 2, this);
    pDoubleValidator->setNotation(QDoubleValidator::StandardNotation);
    pDoubleLineEdit->setValidator(pDoubleValidator);

    //  字符和数字
    QRegExpValidator* pValidator = new QRegExpValidator(this);
    QRegExp reg("[a-zA-Z0-9]+$");
    pValidator->setRegExp(reg);
    pValidatorLineEdit->setValidator(pValidator);

    //  添加进布局
    m_pLayout->addWidget(pIntLineEdit);
    m_pLayout->addWidget(pDoubleLineEdit);
    m_pLayout->addWidget(pValidatorLineEdit);
    //////////////////////////////////////    验证器     //////////////////////////////////////
}

void CLineEditTabItem::InitInputMaskEdit()
{
    //////////////////////////////////////    输入掩码     //////////////////////////////////////
    QLineEdit* pIPLineEdit = new QLineEdit();
    QLineEdit* pMACLineEdit = new QLineEdit();
    QLineEdit* pDateLineEdit = new QLineEdit();
    QLineEdit* pLicneseLineEdit = new QLineEdit();

    //  设置掩码
    pIPLineEdit->setInputMask("000.000.000.000;_");
    pMACLineEdit->setInputMask("HH:HH:HH:HH:HH:HH;_");
    pDateLineEdit->setInputMask("0000-00-00");
    pLicneseLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");

    //  添加进布局
    m_pLayout->addWidget(pIPLineEdit);
    m_pLayout->addWidget(pMACLineEdit);
    m_pLayout->addWidget(pDateLineEdit);
    m_pLayout->addWidget(pLicneseLineEdit);
    //////////////////////////////////////    输入掩码     //////////////////////////////////////
}

void CLineEditTabItem::InitLayoutSearchLineEdit()
{
    m_pSearchLineEdit = new QLineEdit();
    m_pSearchLineEdit->setPlaceholderText(u8"请输入搜索内容");
    m_pSearchLineEdit->setFixedHeight(32);

    QPushButton* searchBtn = new QPushButton();
    searchBtn->setToolTip(u8"搜索");
    searchBtn->setFixedSize(32, 32);
    searchBtn->setCursor(Qt::PointingHandCursor);
    searchBtn->setStyleSheet("QPushButton{border-image:url(:/Image/search-normal); background:transparent;} \
                              QPushButton:hover{border-image:url(:/Image/search-hover)} \
                              QPushButton:pressed{border-image:url(:/Image/search-pressed)}");

    //  防止文本框输入内容位于按钮之下
    QMargins margins = m_pSearchLineEdit->textMargins();
    m_pSearchLineEdit->setTextMargins(margins.left(), margins.top(), searchBtn->width(), margins.bottom());


    //  布局
    QHBoxLayout* pSearchLayout = new QHBoxLayout();
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(searchBtn);
    pSearchLayout->addSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    m_pSearchLineEdit->setLayout(pSearchLayout);    //  将布局添加到LineEdit中
    m_pLayout->addWidget(m_pSearchLineEdit);

    connect(searchBtn, SIGNAL(clicked(bool)), this, SLOT(onSearchByLayout()));
}
