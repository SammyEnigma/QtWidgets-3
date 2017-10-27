#ifndef CSPINBOXTABITEM_H
#define CSPINBOXTABITEM_H

#include <QtWidgets>

class IconSizeSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit IconSizeSpinBox(QWidget* parent = 0) : QSpinBox(parent) {}
    virtual ~IconSizeSpinBox() {}

protected:
    virtual int valueFromText(const QString &text) const override
    {
        QRegExp regExp("(\\d+)(\\s*[xx]\\s*\\d+)?");
        if(regExp.exactMatch(text))
        {
            return regExp.cap(1).toInt();
        }
        else
            return 0;
    }
    virtual QString textFromValue(int value) const override
    {
        return QString("%1 x %1").arg(value);
    }
};

class CSpinBoxTabItem : public QWidget
{
    Q_OBJECT
public:
    explicit CSpinBoxTabItem(QWidget *parent = nullptr);

signals:

public slots:

private:
    void InitSpinBox();
    void InitSpecialSpinBox();
    void InitCustomSpinBox();
    void InitDoubleSpinBox();

private:
    QVBoxLayout* m_pLayout;
};

#endif // CSPINBOXTABITEM_H
