/********************************************************************************
** Form generated from reading UI file 'widget_login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LOGIN_H
#define UI_WIDGET_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Login
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_Account;
    QLineEdit *lineEdit_Account;
    QLabel *label_Password;
    QLineEdit *lineEdit__Password;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Exit;

    void setupUi(QWidget *Widget_Login)
    {
        if (Widget_Login->objectName().isEmpty())
            Widget_Login->setObjectName(QStringLiteral("Widget_Login"));
        Widget_Login->resize(291, 180);
        Widget_Login->setMinimumSize(QSize(291, 0));
        Widget_Login->setMaximumSize(QSize(291, 180));
        Widget_Login->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(Widget_Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(54, 78, 184, 79));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Account = new QLabel(widget);
        label_Account->setObjectName(QStringLiteral("label_Account"));

        gridLayout_2->addWidget(label_Account, 0, 0, 1, 1);

        lineEdit_Account = new QLineEdit(widget);
        lineEdit_Account->setObjectName(QStringLiteral("lineEdit_Account"));

        gridLayout_2->addWidget(lineEdit_Account, 0, 1, 1, 1);

        label_Password = new QLabel(widget);
        label_Password->setObjectName(QStringLiteral("label_Password"));

        gridLayout_2->addWidget(label_Password, 1, 0, 1, 1);

        lineEdit__Password = new QLineEdit(widget);
        lineEdit__Password->setObjectName(QStringLiteral("lineEdit__Password"));

        gridLayout_2->addWidget(lineEdit__Password, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Login = new QPushButton(widget);
        pushButton_Login->setObjectName(QStringLiteral("pushButton_Login"));

        gridLayout->addWidget(pushButton_Login, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_Exit = new QPushButton(widget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));

        gridLayout->addWidget(pushButton_Exit, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 2);


        retranslateUi(Widget_Login);

        QMetaObject::connectSlotsByName(Widget_Login);
    } // setupUi

    void retranslateUi(QWidget *Widget_Login)
    {
        Widget_Login->setWindowTitle(QApplication::translate("Widget_Login", "\344\270\255\345\233\275\350\261\241\346\243\213", Q_NULLPTR));
        label_Account->setText(QApplication::translate("Widget_Login", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        label_Password->setText(QApplication::translate("Widget_Login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton_Login->setText(QApplication::translate("Widget_Login", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_Exit->setText(QApplication::translate("Widget_Login", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget_Login: public Ui_Widget_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LOGIN_H
