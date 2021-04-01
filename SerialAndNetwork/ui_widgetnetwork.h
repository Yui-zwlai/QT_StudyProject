/********************************************************************************
** Form generated from reading UI file 'widgetnetwork.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETNETWORK_H
#define UI_WIDGETNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetNetwork
{
public:
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_recive;
    QCheckBox *checkBox_ReciveHex;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_ReciveSave;
    QPushButton *pushButton_ReciveClean;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_Protocol;
    QComboBox *comboBox_Protocol;
    QLabel *label_IPAddr;
    QLineEdit *lineEdit_IPAddr;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QPushButton *pushButton_Connect;
    QLabel *label_ConnectObject;
    QComboBox *comboBox_ConnectObject;
    QGroupBox *groupBox_1;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_send;
    QCheckBox *checkBox_SendHex;
    QCheckBox *checkBox_Timer;
    QLineEdit *lineEdit_Timer;
    QLabel *label_Timer;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_SeendClean;
    QWidget *page_4;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_shortcut1;
    QPushButton *pushButton_shortcut1;
    QLineEdit *lineEdit_shortcut2;
    QPushButton *pushButton_shortcut2;
    QLineEdit *lineEdit_shortcut3;
    QPushButton *pushButton_shortcut3;
    QLineEdit *lineEdit_shortcut4;
    QPushButton *pushButton_shortcut4;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WidgetNetwork)
    {
        if (WidgetNetwork->objectName().isEmpty())
            WidgetNetwork->setObjectName(QStringLiteral("WidgetNetwork"));
        WidgetNetwork->resize(680, 421);
        WidgetNetwork->setMinimumSize(QSize(652, 387));
        WidgetNetwork->setStyleSheet(QStringLiteral(""));
        gridLayout_7 = new QGridLayout(WidgetNetwork);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_2 = new QGroupBox(WidgetNetwork);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(471, 231));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textEdit_recive = new QTextEdit(groupBox_2);
        textEdit_recive->setObjectName(QStringLiteral("textEdit_recive"));
        textEdit_recive->setReadOnly(true);

        gridLayout_4->addWidget(textEdit_recive, 0, 0, 4, 1);

        checkBox_ReciveHex = new QCheckBox(groupBox_2);
        checkBox_ReciveHex->setObjectName(QStringLiteral("checkBox_ReciveHex"));

        gridLayout_4->addWidget(checkBox_ReciveHex, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        pushButton_ReciveSave = new QPushButton(groupBox_2);
        pushButton_ReciveSave->setObjectName(QStringLiteral("pushButton_ReciveSave"));
        pushButton_ReciveSave->setMinimumSize(QSize(91, 23));
        pushButton_ReciveSave->setMaximumSize(QSize(91, 23));

        gridLayout_4->addWidget(pushButton_ReciveSave, 2, 1, 1, 1);

        pushButton_ReciveClean = new QPushButton(groupBox_2);
        pushButton_ReciveClean->setObjectName(QStringLiteral("pushButton_ReciveClean"));
        pushButton_ReciveClean->setMinimumSize(QSize(91, 23));
        pushButton_ReciveClean->setMaximumSize(QSize(91, 23));

        gridLayout_4->addWidget(pushButton_ReciveClean, 3, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(WidgetNetwork);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(150, 235));
        groupBox_3->setMaximumSize(QSize(150, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_Protocol = new QLabel(groupBox_3);
        label_Protocol->setObjectName(QStringLiteral("label_Protocol"));

        gridLayout_5->addWidget(label_Protocol, 0, 0, 1, 1);

        comboBox_Protocol = new QComboBox(groupBox_3);
        comboBox_Protocol->setObjectName(QStringLiteral("comboBox_Protocol"));
        comboBox_Protocol->setMinimumSize(QSize(120, 0));
        comboBox_Protocol->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(comboBox_Protocol, 1, 0, 1, 1);

        label_IPAddr = new QLabel(groupBox_3);
        label_IPAddr->setObjectName(QStringLiteral("label_IPAddr"));

        gridLayout_5->addWidget(label_IPAddr, 2, 0, 1, 1);

        lineEdit_IPAddr = new QLineEdit(groupBox_3);
        lineEdit_IPAddr->setObjectName(QStringLiteral("lineEdit_IPAddr"));
        lineEdit_IPAddr->setMinimumSize(QSize(120, 0));
        lineEdit_IPAddr->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(lineEdit_IPAddr, 3, 0, 1, 1);

        label_Port = new QLabel(groupBox_3);
        label_Port->setObjectName(QStringLiteral("label_Port"));

        gridLayout_5->addWidget(label_Port, 4, 0, 1, 1);

        lineEdit_Port = new QLineEdit(groupBox_3);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));
        lineEdit_Port->setMinimumSize(QSize(120, 0));
        lineEdit_Port->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(lineEdit_Port, 5, 0, 1, 1);

        pushButton_Connect = new QPushButton(groupBox_3);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setMinimumSize(QSize(120, 0));
        pushButton_Connect->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(pushButton_Connect, 6, 0, 1, 1);

        label_ConnectObject = new QLabel(groupBox_3);
        label_ConnectObject->setObjectName(QStringLiteral("label_ConnectObject"));

        gridLayout_5->addWidget(label_ConnectObject, 7, 0, 1, 1);

        comboBox_ConnectObject = new QComboBox(groupBox_3);
        comboBox_ConnectObject->setObjectName(QStringLiteral("comboBox_ConnectObject"));
        comboBox_ConnectObject->setMinimumSize(QSize(120, 0));
        comboBox_ConnectObject->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(comboBox_ConnectObject, 8, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_1 = new QGroupBox(WidgetNetwork);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setMinimumSize(QSize(601, 141));
        groupBox_1->setMaximumSize(QSize(16777215, 141));
        groupBox_1->setMouseTracking(false);
        gridLayout_3 = new QGridLayout(groupBox_1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        stackedWidget = new QStackedWidget(groupBox_1);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QLatin1String("#stackedWidget{\n"
"background-color: rgba(229, 229, 229, 0);\n"
"}"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit_send = new QTextEdit(page_3);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));
        textEdit_send->setMinimumSize(QSize(481, 87));
        textEdit_send->setMaximumSize(QSize(16777215, 81));

        gridLayout_2->addWidget(textEdit_send, 0, 0, 4, 1);

        checkBox_SendHex = new QCheckBox(page_3);
        checkBox_SendHex->setObjectName(QStringLiteral("checkBox_SendHex"));
        checkBox_SendHex->setMaximumSize(QSize(91, 16));

        gridLayout_2->addWidget(checkBox_SendHex, 0, 1, 1, 3);

        checkBox_Timer = new QCheckBox(page_3);
        checkBox_Timer->setObjectName(QStringLiteral("checkBox_Timer"));
        checkBox_Timer->setMaximumSize(QSize(42, 16));

        gridLayout_2->addWidget(checkBox_Timer, 1, 1, 1, 1);

        lineEdit_Timer = new QLineEdit(page_3);
        lineEdit_Timer->setObjectName(QStringLiteral("lineEdit_Timer"));
        lineEdit_Timer->setMaximumSize(QSize(31, 14));

        gridLayout_2->addWidget(lineEdit_Timer, 1, 2, 1, 1);

        label_Timer = new QLabel(page_3);
        label_Timer->setObjectName(QStringLiteral("label_Timer"));
        label_Timer->setMaximumSize(QSize(41, 20));

        gridLayout_2->addWidget(label_Timer, 1, 3, 1, 1);

        pushButton_Send = new QPushButton(page_3);
        pushButton_Send->setObjectName(QStringLiteral("pushButton_Send"));
        pushButton_Send->setMinimumSize(QSize(30, 23));
        pushButton_Send->setMaximumSize(QSize(91, 23));

        gridLayout_2->addWidget(pushButton_Send, 2, 1, 1, 2);

        pushButton_SeendClean = new QPushButton(page_3);
        pushButton_SeendClean->setObjectName(QStringLiteral("pushButton_SeendClean"));
        pushButton_SeendClean->setMinimumSize(QSize(31, 23));
        pushButton_SeendClean->setMaximumSize(QSize(91, 23));

        gridLayout_2->addWidget(pushButton_SeendClean, 3, 1, 1, 2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        gridLayout_6 = new QGridLayout(page_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_shortcut1 = new QLineEdit(page_4);
        lineEdit_shortcut1->setObjectName(QStringLiteral("lineEdit_shortcut1"));

        gridLayout->addWidget(lineEdit_shortcut1, 0, 0, 1, 1);

        pushButton_shortcut1 = new QPushButton(page_4);
        pushButton_shortcut1->setObjectName(QStringLiteral("pushButton_shortcut1"));
        pushButton_shortcut1->setMinimumSize(QSize(3, 22));

        gridLayout->addWidget(pushButton_shortcut1, 0, 1, 1, 1);

        lineEdit_shortcut2 = new QLineEdit(page_4);
        lineEdit_shortcut2->setObjectName(QStringLiteral("lineEdit_shortcut2"));

        gridLayout->addWidget(lineEdit_shortcut2, 1, 0, 1, 1);

        pushButton_shortcut2 = new QPushButton(page_4);
        pushButton_shortcut2->setObjectName(QStringLiteral("pushButton_shortcut2"));
        pushButton_shortcut2->setMinimumSize(QSize(0, 22));

        gridLayout->addWidget(pushButton_shortcut2, 1, 1, 1, 1);

        lineEdit_shortcut3 = new QLineEdit(page_4);
        lineEdit_shortcut3->setObjectName(QStringLiteral("lineEdit_shortcut3"));

        gridLayout->addWidget(lineEdit_shortcut3, 2, 0, 1, 1);

        pushButton_shortcut3 = new QPushButton(page_4);
        pushButton_shortcut3->setObjectName(QStringLiteral("pushButton_shortcut3"));
        pushButton_shortcut3->setMinimumSize(QSize(0, 22));

        gridLayout->addWidget(pushButton_shortcut3, 2, 1, 1, 1);

        lineEdit_shortcut4 = new QLineEdit(page_4);
        lineEdit_shortcut4->setObjectName(QStringLiteral("lineEdit_shortcut4"));

        gridLayout->addWidget(lineEdit_shortcut4, 3, 0, 1, 1);

        pushButton_shortcut4 = new QPushButton(page_4);
        pushButton_shortcut4->setObjectName(QStringLiteral("pushButton_shortcut4"));
        pushButton_shortcut4->setMinimumSize(QSize(0, 22));

        gridLayout->addWidget(pushButton_shortcut4, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 2, 1);

        toolButton = new QToolButton(groupBox_1);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(25, 18));
        toolButton->setMaximumSize(QSize(25, 18));

        gridLayout_3->addWidget(toolButton, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 82, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_1, 1, 0, 1, 2);


        retranslateUi(WidgetNetwork);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetNetwork);
    } // setupUi

    void retranslateUi(QWidget *WidgetNetwork)
    {
        WidgetNetwork->setWindowTitle(QApplication::translate("WidgetNetwork", "\347\275\221\347\273\234\350\260\203\350\257\225\345\212\251\346\211\213", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("WidgetNetwork", "\346\216\245\346\224\266\347\252\227\345\217\243", Q_NULLPTR));
        checkBox_ReciveHex->setText(QApplication::translate("WidgetNetwork", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", Q_NULLPTR));
        pushButton_ReciveSave->setText(QApplication::translate("WidgetNetwork", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_ReciveClean->setText(QApplication::translate("WidgetNetwork", "\346\270\205\351\231\244", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("WidgetNetwork", "\347\275\221\347\273\234\350\256\276\347\275\256", Q_NULLPTR));
        label_Protocol->setText(QApplication::translate("WidgetNetwork", "\345\215\217\350\256\256\351\200\211\346\213\251", Q_NULLPTR));
        comboBox_Protocol->clear();
        comboBox_Protocol->insertItems(0, QStringList()
         << QApplication::translate("WidgetNetwork", "tcp server", Q_NULLPTR)
         << QApplication::translate("WidgetNetwork", "tcp client", Q_NULLPTR)
         << QApplication::translate("WidgetNetwork", "udp", Q_NULLPTR)
        );
        label_IPAddr->setText(QApplication::translate("WidgetNetwork", "\346\234\254\345\234\260IP\345\234\260\345\235\200", Q_NULLPTR));
        label_Port->setText(QApplication::translate("WidgetNetwork", "\346\234\254\345\234\260\347\253\257\345\217\243", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("WidgetNetwork", "\350\277\236\346\216\245", Q_NULLPTR));
        label_ConnectObject->setText(QApplication::translate("WidgetNetwork", "\351\200\232\350\256\257\345\257\271\350\261\241", Q_NULLPTR));
        comboBox_ConnectObject->clear();
        comboBox_ConnectObject->insertItems(0, QStringList()
         << QApplication::translate("WidgetNetwork", "ALL", Q_NULLPTR)
        );
        groupBox_1->setTitle(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201\347\252\227\345\217\243", Q_NULLPTR));
        checkBox_SendHex->setText(QApplication::translate("WidgetNetwork", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_Timer->setText(QApplication::translate("WidgetNetwork", "\345\256\232\346\227\266", Q_NULLPTR));
        lineEdit_Timer->setText(QApplication::translate("WidgetNetwork", "1000", Q_NULLPTR));
        label_Timer->setText(QApplication::translate("WidgetNetwork", "ms", Q_NULLPTR));
        pushButton_Send->setText(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_SeendClean->setText(QApplication::translate("WidgetNetwork", "\346\270\205\351\231\244", Q_NULLPTR));
        pushButton_shortcut1->setText(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_shortcut2->setText(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_shortcut3->setText(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_shortcut4->setText(QApplication::translate("WidgetNetwork", "\345\217\221\351\200\201", Q_NULLPTR));
        toolButton->setText(QApplication::translate("WidgetNetwork", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetNetwork: public Ui_WidgetNetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETNETWORK_H
