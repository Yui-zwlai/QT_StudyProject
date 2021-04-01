#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QList>
#include <QDebug>

#include "mythread.h"
class TcpServer : public QObject
{
    Q_OBJECT


public:
    TcpServer();

    bool Listen(int port);
    void Break();
    QByteArray GetReadBuf();
    QString GetClientIP();
    void CleanReadBuf();
    void CleanIP();
    void SendData(QByteArray sendbuffer,QString IP);

signals:
    void ReadDataReady();//有数据信号
    void NewConnectionReady(QString);//新连接信号
    void ConnectionBreakReady(QString);//连接断开信号

private slots:
    void NewConnectionSlot();
    void ReadData(QString,QByteArray);

public:
    QList<MyThread*> m_threadList;//线程列表，存放每个客户端线程

private:
    QTcpServer *m_tcpServer;

    QByteArray m_readBuffer;//接收的数据
    QString m_IP_Port;//接收的IP


};

#endif // TCPSERVER_H
