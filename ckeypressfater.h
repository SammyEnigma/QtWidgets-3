#ifndef CKEYPRESSFATER_H
#define CKEYPRESSFATER_H

#include <QObject>

class CKeyPressFater : public QObject
{
    Q_OBJECT
public:
    explicit CKeyPressFater(QObject *parent = nullptr);

signals:

public slots:

protected:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // CKEYPRESSFATER_H
