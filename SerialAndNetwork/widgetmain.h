#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include <QWidget>
#include "widgetserial.h"
#include "widgetnetwork.h"

namespace Ui {
class WidgetMain;
}

class WidgetMain : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetMain(QWidget *parent = 0);
    ~WidgetMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WidgetMain *ui;

    WidgetSerial *s;
    WidgetNetwork *n;
};

#endif // WIDGETMAIN_H
