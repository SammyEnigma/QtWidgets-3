#ifndef CTRAYMENU_H
#define CTRAYMENU_H

#include <QMenu>

class CTrayMenu : public QMenu
{
    Q_OBJECT
public:
    explicit CTrayMenu(QWidget* parent = 0);
    ~CTrayMenu(){}

signals:
    void showWindow();

private:
    void InitActions();

private:
    QAction* m_pShowAction;
    QAction* m_pSettingAction;
    QAction* m_pHomeAction;
    QAction* m_pHelpAction;
    QAction* m_pAboutAction;
    QAction* m_pUpgradeAction;
    QAction* m_pQuitAction;
};

#endif // CTRAYMENU_H
