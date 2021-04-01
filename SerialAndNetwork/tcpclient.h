#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class TcpClient : public QObject
{
    Q_OBJECT



public:
    TcpClient();
    bool ConnectToHost(const QString IP,const int port);
    void DisconnectFromHost();
    QByteArray GetReadBuf();
    QString GetServerIP();
    void CleanReadBuf();
    void CleanIP();
    void SendData(QByteArray data);

signals:
    void ConnectErrorReady(const QString errorString);//连接失败信号
    void ReadDataReady();//有数据信号

private slots:
    void ReadData();
    void ConnectError(QAbstractSocket::SocketError);

private:
    QTcpSocket *m_tcpSocket;

    QByteArray m_readBuffer;
    QString m_IP;

};

#endif // TCPCLIENT_H
