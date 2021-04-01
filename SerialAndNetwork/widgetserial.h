#ifndef WIDGETSERIAL_H
#define WIDGETSERIAL_H

#include <QWidget>
#include <qpainter.h>
#include <QMessageBox>
#include <QString>
#include <QByteArray>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>

#include "serial.h"
namespace Ui {
class WidgetSerial;
}

class WidgetSerial : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSerial(QWidget *parent = 0);
    ~WidgetSerial();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_SwitchButton_clicked();//串口开关
    void on_SendButton_clicked();
    void on_CleanReciveButton_clicked();
    void on_CleanSendButton_clicked();
    void on_checkBox_ReciveHex_clicked(bool checked);
    void on_checkBox_SendHex_clicked(bool checked);
    void on_pushButton_emptyCount_clicked();

    void ReadSerialData();//读取从自定义串口类获得的数据
    void TimerTimeOut();//定时器


    void on_pushButton_openFile_clicked();

private:
    Ui::WidgetSerial *ui;
    Serial *m_serial;//实例串口类


    QStringList serialStrList;//用于存储串口列表

    QString intTextback;//十进制文本保存字符串

    int receiveCount;//接收计数器
    int sendCount;//发送计数器

    QByteArray m_fileArray;//发送文件缓存
    QString m_fileName;//打开文件路径

    QTimer *m_timer;//定时器
};

#endif // WIDGETSERIAL_H
