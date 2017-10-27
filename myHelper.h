#ifndef MYHELPER_H
#define MYHELPER_H

#include <QtCore>
#include <QtGui>

class myHelper : public QObject
{
    //Q_OBJECT

public:
    //  设置皮肤样式
    static void SetStyle(const QString& styleName)
    {
        QFile file(QString(":/skin/css/%1.css").arg(styleName));
        file.open(QFile::ReadOnly);
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        qApp->setPalette(QPalette(QColor("#F0F0F0")));
    }
};

#endif // MYHELPER_H
