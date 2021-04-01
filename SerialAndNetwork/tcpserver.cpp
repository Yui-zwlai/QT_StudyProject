#include "tcpserver.h"


TcpServer::TcpServer()
{
    m_tcpServer = NULL;

    m_tcpServer = new QTcpServer(this);

    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}

//服务端监听
bool TcpServer::Listen(int port)
{
    bool ok = m_tcpServer->listen(QHostAddress::Any,port);
    return ok;
}

//服务端断开
void TcpServer::Break()
{
    for(int i =  m_threadList.length()-1; i >= 0;i--)
    {
        m_threadList[i]->m_tcpSocket->disconnectFromHost();
        m_threadList[i]->quit();
        m_threadList.removeAt(i);
    }
    qDebug()<<m_threadList;
    m_tcpServer->close();     //不再监听端口
}

//获取数据
QByteArray TcpServer::GetReadBuf()
{

    return m_readBuffer;
}

//获取IP
QString TcpServer::GetClientIP()
{
    return m_IP_Port;
}

//清除数据
void TcpServer::CleanReadBuf()
{
    m_readBuffer.clear();
}

//清除IP
void TcpServer::CleanIP()
{
    m_IP_Port.clear();
}

//发送数据 向所有客户端
void TcpServer::SendData(QByteArray sendbuffer,QString IP)
{
    if(IP == "ALL")
        for(int i = 0; i < m_threadList.length(); i++)
            m_threadList[i]->Write(sendbuffer);
    else
    {
        for(int i = 0; i < m_threadList.length(); i++)
            if(m_threadList[i]->GetIP() == IP)
            {
                m_threadList[i]->Write(sendbuffer);
                return;
            }
    }
}

//新连接建立
void TcpServer::NewConnectionSlot()
{
    MyThread *thread = new MyThread(m_tcpServer->nextPendingConnection());//创建线程
    m_threadList.append(thread);

    connect(thread, SIGNAL(ReadDataReady(QString,QByteArray)),this,SLOT(ReadData(QString,QByteArray)));
    connect(thread, SIGNAL(NewConnectionReady(QString)),this,SIGNAL(NewConnectionReady(QString)));
    connect(thread, SIGNAL(ConnectionBreakReady(QString)),this,SIGNAL(ConnectionBreakReady(QString)));

    thread->start();//线程启动
    qDebug()<<m_threadList;
}

//新数据及IP的获取
void TcpServer::ReadData(QString IP,QByteArray data)
{
    m_IP_Port = IP;
    m_readBuffer = data;
    emit ReadDataReady();
}


