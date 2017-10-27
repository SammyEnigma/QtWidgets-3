#include "CTrayMenu.h"
#include <QApplication>


CTrayMenu::CTrayMenu(QWidget *parent) : QMenu(parent)
{
    this->InitActions();
}

void CTrayMenu::InitActions()
{
    m_pShowAction = new QAction(QIcon(":/Image/open"), u8"显示", this);
    m_pSettingAction = new QAction(QIcon(":/Image/setting"), u8"设置", this);
    m_pHomeAction = new QAction(QIcon(":/Image/home"), u8"登录网页", this);
    m_pHelpAction = new QAction(QIcon(":/Image/help"), u8"帮助", this);
    m_pAboutAction = new QAction(QIcon(":/Image/about"), u8"关于", this);
    m_pUpgradeAction = new QAction(QIcon(":/Image/upgrade"), u8"检查更新", this);
    m_pQuitAction = new QAction(QIcon(":/Image/quit"), u8"退出", this);

    addAction(m_pShowAction);
    addAction(m_pSettingAction);
    addAction(m_pHomeAction);
    addSeparator();
    addAction(m_pHelpAction);
    addAction(m_pAboutAction);
    addAction(m_pUpgradeAction);
    addSeparator();
    addAction(m_pQuitAction);

    connect(m_pShowAction, SIGNAL(triggered(bool)), this, SIGNAL(showWindow()));
    connect(m_pQuitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}
