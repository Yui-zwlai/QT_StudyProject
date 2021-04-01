#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTime>
#include <QTimer>
#include "serial.h"
#include <QMovie>
#include <QDebug>
#define cout qDebug() << "[" <<__FILE__ <<":"<<__LINE__ <<"]"

#include <QMediaPlayer>


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
    void on_pushButton_open_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_2_clicked();

    void readData();

    void on_pushButton_recording_clicked();

    void on_pushButton_auto_clicked();

    void TimerTimeOut();

private:
    Ui::Widget *ui;

    Serial *m_serial;
    QStringList m_serialList;

    QString m_filePath;

    QFile *m_saveFile;

    QList<int> intList;

    QTimer * m_timer;

    QMediaPlayer *player;
};

#endif // WIDGET_H
