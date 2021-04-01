#include "udp.h"
#include <QDebug>
#include <QHostAddress>
Udp::Udp()
{
    m_udpSocket = new QUdpSocket;
}

void Udp::Bind(int port)
{
    m_udpSocket->bind(QHostAddress::AnyIPv4,port);

    connect(m_udpSocket,SIGNAL(readyRead()),this,SLOT(ReadData()));
}

void Udp::Close()
{
    m_udpSocket->close();
}

QByteArray Udp::GetReadBuf()
{
    return m_readBuf;
}

QString Udp::GetIP()
{
    return m_IP;
}

void Udp::CleanReadBuf()
{
    m_readBuf.clear();
}

void Udp::CleanIP()
{
    m_IP.clear();
}

void Udp::SendData(QByteArray data,QString host, int port)
{
    if(host == "ALL")
        m_udpSocket->writeDatagram(data,QHostAddress::Broadcast,port);
}

void Udp::ReadData()
{
    char data[1024] = "";
    QHostAddress host;
    quint16 port;

    if(m_udpSocket->readDatagram(data,sizeof(data),&host,&port))
    {
        m_IP = tr("[%1]:%2").arg(host.toString()).arg(port);

    }
    m_readBuf = QString::fromUtf8(data).toLatin1();
    emit ReadDataReady();
}

