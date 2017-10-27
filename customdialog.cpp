#include "customdialog.h"
#include "ui_customdialog.h"

#include <QMovie>
#include <QDesktopServices>
#include <QUrl>
#include <QTimer>
#include <QDateTime>

CustomDialog::CustomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog),
    m_pLCD(nullptr)
{
    ui->setupUi(this);

    this->InitLabel();

    this->InitLCDNumber();
    ui->verticalLayout->addWidget(m_pLCD);
    this->InitTimer();
}

CustomDialog::~CustomDialog()
{
    delete ui;
}

void CustomDialog::openUrl(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}

void CustomDialog::onTimeOut()
{
    //  获取系统当前时间
    QDateTime dateTime = QDateTime::currentDateTime();
    //  显示的内容
    m_pLCD->display(dateTime.toString("yyyy-MM-dd HH:mm:ss.zzz"));
}

void CustomDialog::InitLabel()
{
    ui->label->setWordWrap(true);
    QString strText = u8"一去二三里，烟村四五家。亭台六七座，八九十枝花。";

    //  设置行高
//    QString strHeightText = "<p styple=\"line-height:%1\">%2</p>";
//    strText = strHeightText.arg(150).arg(strText);

    //  省略
//    QString strElidedText = ui->label->fontMetrics().elidedText(strText, Qt::ElideRight, 200, Qt::TextShowMnemonic);

    //  富文本html
//    QString strHtml = QString("<html>"
//                      "<head><style>font{color:white;} #f{font-size:18px; color:green;}</style></head>"
//                      "<body>"
//                      "<font>%1</font>"
//                      "<font id=\"f\">%2</font>"
//                      "<br /><br />"
//                      "<img src=\":/Image/logo\" width=\"100\" height=\"100\" />"
//                      "</body>"
//                      "</html>").arg("I am a ").arg("Qter");
//    ui->label->setAlignment(Qt::AlignCenter);

    //  显示图像
//    QPixmap pixmap(":/Image/log");
//    ui->label->setPixmap(pixmap);
//    ui->label->setFixedSize(100, 100);
//    ui->label->setScaledContents(true);

    //  显示动画
    QMovie* pMovie = new QMovie(":/Images/movie.gif");
    ui->label->setMovie(pMovie);
    //ui->label->setFixedSize(this->width(), 200);
    ui->label->setScaledContents(true);
    pMovie->start();

    //  超链接
    //  方法一
//    ui->label->setText(QString("<a href = \"%1\">%2</a>").arg("https://github.com/andywong569").arg(u8("一去丶二三里")));
//    ui->label->setOpenExternalLinks(true);
    //  方法二
//    ui->label->setText(QString("<a href = \"%1\">%2</a>").arg("https://github.com/andywong569").arg(u8("一去丶二三里")));
//    connect(ui->label, SIGNAL(linkActivated(QString)), this, SLOT(openUrl(QString)));

//    ui->label->setText(strHtml);
}

void CustomDialog::InitLCDNumber()
{
    if(m_pLCD == nullptr)
    {
        m_pLCD = new QLCDNumber(this);
        m_pLCD->setDigitCount(25);
        m_pLCD->setMode(QLCDNumber::Dec);
        m_pLCD->setSegmentStyle(QLCDNumber::Flat);
        m_pLCD->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    }
}

void CustomDialog::InitTimer()
{
    QTimer* pTimer = new QTimer(this);
    //  设置时间间隔
    pTimer->setInterval(1000);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    //  启动定时器
    pTimer->start();
}
