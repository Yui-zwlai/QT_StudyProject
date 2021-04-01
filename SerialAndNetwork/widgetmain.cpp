#include "widgetmain.h"
#include "ui_widgetmain.h"


WidgetMain::WidgetMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMain)
{
    ui->setupUi(this);
}

WidgetMain::~WidgetMain()
{
    delete ui;
}

void WidgetMain::on_pushButton_clicked()
{
    s = new WidgetSerial;

    s->show();

    this->hide();
}

void WidgetMain::on_pushButton_2_clicked()
{
    n = new WidgetNetwork;

    n->show();

    this->hide();
}
