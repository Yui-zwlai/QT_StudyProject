#include "widget_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_Login w;
    w.show();

    return a.exec();
}
