#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>
#include <QLCDNumber>

namespace Ui {
class CustomDialog;
}

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomDialog(QWidget *parent = 0);
    ~CustomDialog();

signals:

public slots:
    void openUrl(const QString& link);
    void onTimeOut();

private:
    void InitLabel();
    void InitLCDNumber();
    void InitTimer();

private:
    Ui::CustomDialog *ui;

    QLCDNumber* m_pLCD;
};

#endif // CUSTOMDIALOG_H
