#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTime>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>

#include "tcpserver.h"

#define cout qDebug() << "[" <<__FILE__ <<":"<<__LINE__ <<"]"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT



public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void ReadData();
    void NewConnection(QString);
    void ConnectionBreak(QString);

public:
    void Delay();

private:
    Ui::Widget *ui;

    TcpServer *m_tcpServer;

    int m_connectionNumber;
    int m_confrontationNumber;



    bool m_player1;
    bool m_player2;
    bool m_player1Ready;
    bool m_player2Ready;
    QString m_player1ID;
    QString m_player2ID;







};

#endif // WIDGET_H
