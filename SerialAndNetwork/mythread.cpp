#include "mythread.h"

MyThread::MyThread(QTcpSocket * tcpSocket)
{
    m_tcpSocket = tcpSocket;
}

//向套接字写入
void MyThread::Write(QByteArray sendbuffer)
{
    m_tcpSocket->write(sendbuffer);
}

QString MyThread::GetIP()
{
    return m_IP_Port;
}

//从套接字读取
void MyThread::ReadData()
{
    QByteArray readBuff = m_tcpSocket->readAll();

    emit ReadDataReady(m_IP_Port, readBuff);
}

//套接字断开
void MyThread::DisconnectedSlot()
{
    if(m_tcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
         m_tcpSocket->destroyed();
    }
    this->quit();
    emit ConnectionBreakReady(m_IP_Port);
}



void MyThread::run()
{
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(DisconnectedSlot()));
    m_IP_Port = tr("[%1]:%2").arg(m_tcpSocket->peerAddress().toString().split("::ffff:")[1]).arg(m_tcpSocket->peerPort());

    emit NewConnectionReady(m_IP_Port);
    qDebug() << currentThreadId();
}


