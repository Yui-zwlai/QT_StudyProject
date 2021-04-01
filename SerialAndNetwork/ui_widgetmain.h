/********************************************************************************
** Form generated from reading UI file 'widgetmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMAIN_H
#define UI_WIDGETMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMain
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *WidgetMain)
    {
        if (WidgetMain->objectName().isEmpty())
            WidgetMain->setObjectName(QStringLiteral("WidgetMain"));
        WidgetMain->resize(190, 164);
        gridLayout = new QGridLayout(WidgetMain);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(WidgetMain);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(WidgetMain);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);


        retranslateUi(WidgetMain);

        QMetaObject::connectSlotsByName(WidgetMain);
    } // setupUi

    void retranslateUi(QWidget *WidgetMain)
    {
        WidgetMain->setWindowTitle(QApplication::translate("WidgetMain", "\350\260\203\350\257\225\345\212\251\346\211\213", Q_NULLPTR));
        pushButton->setText(QApplication::translate("WidgetMain", "\344\270\262\345\217\243\345\212\251\346\211\213", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("WidgetMain", "\347\275\221\347\273\234\345\212\251\346\211\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetMain: public Ui_WidgetMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMAIN_H
