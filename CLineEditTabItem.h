#ifndef CLINEEDITTABITEM_H
#define CLINEEDITTABITEM_H

#include <QtWidgets>

class CLineEditTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CLineEditTabItem(QWidget *parent = nullptr);

signals:

public slots:
    void onLineEditActionTriggered(bool checked = false);
    void onLineEditReturnPressed();
    void onSearchByLayout();

private:
    void InitLineEdit();
    void InitEchoEdit();
    void InitCustomSearchEdit();
    void InitValidatorEdit();
    void InitInputMaskEdit();

    void InitLayoutSearchLineEdit();

private:
    QVBoxLayout* m_pLayout;

    //  自定义搜索框
    QLineEdit* m_pLineEdit;
    QLabel* m_pLabel;

    //  布局自定义搜索框
    QLineEdit* m_pSearchLineEdit;
};

#endif // CLINEEDITTABITEM_H
