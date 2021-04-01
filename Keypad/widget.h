#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>

#define cout qDebug() << "[" <<__FILE__ <<":"<<__LINE__ <<"]"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void TimerTimeOut();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void ConnectSQL();
    void WriteSQL(QByteArray);
private:
    Ui::Widget *ui;

    QSqlDatabase   db;
    QSqlQuery *query;

    QString path;

    QTimer * m_timer;
};

#endif // WIDGET_H
