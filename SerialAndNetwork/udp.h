#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>

class Udp : public QObject
{
    Q_OBJECT

public:
    Udp();

    void Bind(int prot);
    void Close();
    QByteArray GetReadBuf();
    QString GetIP();
    void CleanReadBuf();
    void CleanIP();
    void SendData(QByteArray,QString,int);

signals:
    void ReadDataReady();

private slots:
    void ReadData();

private:
    QUdpSocket * m_udpSocket;

    QByteArray m_readBuf;
    QString m_IP;
};

#endif // UDP_H
