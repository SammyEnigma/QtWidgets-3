#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void showWindow();
    void onActivvationReason(QSystemTrayIcon::ActivationReason reason);

private:
    void InitBtnMenu();
    void InitToolBtn();
    void InitSystemTray();

private:
    Ui::MainWindow *ui;

    QTabWidget* m_pTabWgt;
};

#endif // MAINWINDOW_H
