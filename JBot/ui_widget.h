/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_open;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_play;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_recording;
    QPushButton *pushButton_2;
    QPushButton *pushButton_auto;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_move1;
    QPushButton *pushButton_move2;
    QPushButton *pushButton_move3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(280, 153);
        gridLayout_5 = new QGridLayout(Widget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        pushButton_open = new QPushButton(Widget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        gridLayout->addWidget(pushButton_open, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100);

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        pushButton_play = new QPushButton(Widget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));

        gridLayout_2->addWidget(pushButton_play, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_recording = new QPushButton(Widget);
        pushButton_recording->setObjectName(QStringLiteral("pushButton_recording"));

        gridLayout_3->addWidget(pushButton_recording, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_auto = new QPushButton(Widget);
        pushButton_auto->setObjectName(QStringLiteral("pushButton_auto"));

        gridLayout_3->addWidget(pushButton_auto, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_move1 = new QPushButton(Widget);
        pushButton_move1->setObjectName(QStringLiteral("pushButton_move1"));

        gridLayout_4->addWidget(pushButton_move1, 0, 0, 1, 1);

        pushButton_move2 = new QPushButton(Widget);
        pushButton_move2->setObjectName(QStringLiteral("pushButton_move2"));

        gridLayout_4->addWidget(pushButton_move2, 0, 1, 1, 1);

        pushButton_move3 = new QPushButton(Widget);
        pushButton_move3->setObjectName(QStringLiteral("pushButton_move3"));

        gridLayout_4->addWidget(pushButton_move3, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        pushButton_open->setText(QApplication::translate("Widget", "\346\211\223\345\274\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\270\247\346\225\260\357\274\232", Q_NULLPTR));
        pushButton_play->setText(QApplication::translate("Widget", "\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_recording->setText(QApplication::translate("Widget", "\345\275\225\345\210\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\345\270\247", Q_NULLPTR));
        pushButton_auto->setText(QApplication::translate("Widget", "\350\207\252\345\212\250", Q_NULLPTR));
        pushButton_move1->setText(QApplication::translate("Widget", "\344\275\215\347\275\2561", Q_NULLPTR));
        pushButton_move2->setText(QApplication::translate("Widget", "\344\275\215\347\275\2562", Q_NULLPTR));
        pushButton_move3->setText(QApplication::translate("Widget", "\344\275\215\347\275\2563", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
