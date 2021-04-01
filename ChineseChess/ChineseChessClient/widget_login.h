#ifndef WIDGET_LOGIN_H
#define WIDGET_LOGIN_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTime>

#include "widget_main.h"
#include "tcpclient.h"


#include <QFile>

#define cout qDebug() << "[" <<__FILE__ <<":"<<__LINE__ <<"]"

namespace Ui {
class Widget_Login;
}

class Widget_Login : public QWidget
{
    Q_OBJECT

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);


public:
    explicit Widget_Login(QWidget *parent = 0);
    ~Widget_Login();

private slots:


    void on_pushButton_Exit_clicked();

    void on_pushButton_Login_clicked();

private:
    Ui::Widget_Login *ui;

    Widget_main * W_main;

    QPoint m_pt;

    TcpClient *m_tcpClient;

    QFile f;

};

#endif // WIDGET_LOGIN_H
