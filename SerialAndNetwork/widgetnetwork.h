#ifndef WIDGETNETWORK_H
#define WIDGETNETWORK_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QFile>

#include "tcpserver.h"
#include "mythread.h"
#include "tcpclient.h"
#include "udp.h"

namespace Ui {
class WidgetNetwork;
}

class WidgetNetwork : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetNetwork(QWidget *parent = 0);
    ~WidgetNetwork();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_Connect_clicked();
    void on_pushButton_Send_clicked();
    void on_comboBox_Protocol_currentIndexChanged(const QString &arg1);
    void on_pushButton_SeendClean_clicked();
    void on_pushButton_ReciveClean_clicked();
    void on_checkBox_Timer_clicked(bool checked);
    void on_checkBox_SendHex_clicked(bool checked);
    void on_pushButton_ReciveSave_clicked();


    void ReadData();
    void ConnectError(QString errorQString);
    void ConnectionAdd(QString connection);
    void ConnectionRemove(QString connection);
    void TimerTimeOut();
    void ShortCutButton();



    void on_toolButton_clicked();

private:
    Ui::WidgetNetwork *ui;

    TcpServer *m_tcpServer;//用于Tcp服务器
    TcpClient *m_tcpClient;//用于Tcp客户端
    Udp *m_udp;//用于Udp

    QTimer *m_timer;//定时器

    QString IP;//接收框上条消息的IP
};

#endif // WIDGETNETWORK_H
