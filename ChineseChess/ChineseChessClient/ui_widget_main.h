/********************************************************************************
** Form generated from reading UI file 'widget_main.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MAIN_H
#define UI_WIDGET_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_main
{
public:

    void setupUi(QWidget *Widget_main)
    {
        if (Widget_main->objectName().isEmpty())
            Widget_main->setObjectName(QStringLiteral("Widget_main"));
        Widget_main->resize(400, 300);

        retranslateUi(Widget_main);

        QMetaObject::connectSlotsByName(Widget_main);
    } // setupUi

    void retranslateUi(QWidget *Widget_main)
    {
        Widget_main->setWindowTitle(QApplication::translate("Widget_main", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget_main: public Ui_Widget_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MAIN_H
