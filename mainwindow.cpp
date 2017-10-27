#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customdialog.h"

#include "CPushButtonTabItem.h"
#include "CCheckBoxTabItem.h"
#include "CLineEditTabItem.h"
#include "CSpinBoxTabItem.h"
#include "CSliderTabItem.h"
#include "CScrollAreaTabItem.h"
#include "CToolBoxTabItem.h"
#include "CTrayMenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pTabWgt(nullptr)
{
    ui->setupUi(this);

    m_pTabWgt = new QTabWidget(this);
    ui->verticalLayout->addWidget(m_pTabWgt);

    CPushButtonTabItem* pPushButtonItem = new CPushButtonTabItem(this);
    m_pTabWgt->addTab(pPushButtonItem, "PushButton");

    CCheckBoxTabItem* pCheckBoxItem = new CCheckBoxTabItem(this);
    m_pTabWgt->addTab(pCheckBoxItem, "CheckBox");

    CLineEditTabItem* pLineEditItem = new CLineEditTabItem(this);
    m_pTabWgt->addTab(pLineEditItem, "LineEdit");

    CSpinBoxTabItem* pSpinBoxItem = new CSpinBoxTabItem(this);
    m_pTabWgt->addTab(pSpinBoxItem, "SpinBox");

    CSliderTabItem* pSliderItem = new CSliderTabItem(this);
    m_pTabWgt->addTab(pSliderItem, "Slider");

    CScrollAreaTabItem* pScrollItem = new CScrollAreaTabItem(this);
    m_pTabWgt->addTab(pScrollItem, "ScrollArea");

    CToolBoxTabItem* pToolBoxItem = new CToolBoxTabItem(this);
    m_pTabWgt->addTab(pToolBoxItem, "ToolBox");

    //  菜单
    this->InitBtnMenu();
    this->InitToolBtn();

    //  初始化托盘
    this->InitSystemTray();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showWindow()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
}

void MainWindow::onActivvationReason(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        {
            this->showWindow();
        }
        break;
    case QSystemTrayIcon::DoubleClick:
        {

        }
        break;
    default:
        break;
    }
}

void MainWindow::InitBtnMenu()
{
    QMenu* pMenu = new QMenu(this);
    pMenu->addAction(u8"设置");
    pMenu->addAction(u8"版本检测");
    pMenu->addSeparator();
    pMenu->addAction(u8"关于我们");
    pMenu->addAction(u8"退出");

    //  按钮
    QPushButton* pBtn = new QPushButton(this);
    pBtn->setText(u8"主菜单");

    //  设置菜单
    pBtn->setMenu(pMenu);

    //  设置布局
    ui->verticalLayout->insertWidget(0, pBtn);
}

void MainWindow::InitToolBtn()
{
    QToolButton* pBtn = new QToolButton(this);
    //pBtn->setArrowType(Qt::LeftArrow);
    //pBtn->setText("Left Arrow");

    //  设置默认QAction
    QAction* pAction = new QAction(this);
    pAction->setText("wangds");
    pAction->setIcon(QIcon(":/Image/logo"));
    pBtn->setIconSize(QSize(48, 48));
    pAction->setToolTip("C++ Developer");
    pBtn->setDefaultAction(pAction);


    pBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->verticalLayout->insertWidget(0, pBtn);
}

void MainWindow::InitSystemTray()
{
    //  创建系统托盘
    QSystemTrayIcon* pSystemTray = new QSystemTrayIcon(QIcon(":/Image/login"), this);
    pSystemTray->setToolTip(u8"我就是托盘");

    //  创建托盘上下文菜单
    CTrayMenu* pTrayMenu = new CTrayMenu(this);

    //  设置系统托盘的上下文菜单
    pSystemTray->setContextMenu(pTrayMenu);

    //  连接信号槽
    connect(pTrayMenu, SIGNAL(showWindow()), this, SLOT(showWindow()));
    connect(pSystemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivvationReason(QSystemTrayIcon::ActivationReason)));

    //  显示系统托盘
    pSystemTray->show();

    //  显示系统托盘提示信息
    pSystemTray->showMessage(u8"托盘标题", u8"托盘显示内容");
}
