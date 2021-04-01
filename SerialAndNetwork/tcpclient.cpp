#include "tcpclient.h"

TcpClient::TcpClient()
{
    m_tcpSocket = new QTcpSocket;
    m_tcpSocket->abort();//取消原有连接


    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(ReadData()));
    connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), \
            this, SLOT(ConnectError(QAbstractSocket::SocketError)));
}

bool TcpClient::ConnectToHost(const QString IP,const int port)
{
    m_tcpSocket->connectToHost((QHostAddress)IP,port);
    return ((m_tcpSocket->state() == QAbstractSocket::UnconnectedState)||m_tcpSocket->waitForConnected(1000));
}

void TcpClient::DisconnectFromHost()
{
    m_tcpSocket->disconnectFromHost();
}

QByteArray TcpClient::GetReadBuf()
{
    return m_readBuffer;
}

QString TcpClient::GetServerIP()
{
    return m_IP;
}

void TcpClient::CleanReadBuf()
{
    m_readBuffer.clear();
}

void TcpClient::CleanIP()
{
    m_IP.clear();
}

void TcpClient::SendData(const QByteArray data)
{
    m_tcpSocket->write(data);
}

void TcpClient::ReadData()
{
    m_readBuffer = m_tcpSocket->readAll();

    m_IP = tr("[%1]:%2").arg(m_tcpSocket->peerAddress().toString()).arg(m_tcpSocket->peerPort());
    emit ReadDataReady();
}

void TcpClient::ConnectError(QAbstractSocket::SocketError)
{
    m_tcpSocket->disconnectFromHost();
    emit ConnectErrorReady(m_tcpSocket->errorString());
}
