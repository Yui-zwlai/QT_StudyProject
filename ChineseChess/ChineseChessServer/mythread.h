#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

#include <QHostAddress>
class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread(QTcpSocket *tcpSocket);
    void Write(QByteArray sendbuffer);
    QString GetIP();

    QTcpSocket *m_tcpSocket;

protected:
    void run();

signals:
    void ReadDataReady(const QString &ip, const QByteArray &data);
    void NewConnectionReady(QString);
    void ConnectionBreakReady(QString);

private slots:
    void ReadData();
    void DisconnectedSlot();

private:
    QString m_IP_Port;
};

#endif // MYTHREAD_H
