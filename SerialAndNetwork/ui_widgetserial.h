/********************************************************************************
** Form generated from reading UI file 'widgetserial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSERIAL_H
#define UI_WIDGETSERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSerial
{
public:
    QPushButton *CleanSendButton;
    QPushButton *SendButton;
    QLabel *label_SendCount;
    QCheckBox *checkBox_ReciveHex;
    QPushButton *CleanReciveButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *Seriallabel;
    QComboBox *SerialcomboBoxl;
    QLabel *Baudlabel;
    QComboBox *BaudcomboBox;
    QLabel *Paritylabel;
    QComboBox *ParitycomboBox;
    QLabel *Datalabel;
    QComboBox *DatacomboBox;
    QLabel *Stoplabel;
    QComboBox *StopcomboBox;
    QLabel *controlflowlabel;
    QComboBox *controlflowcomboBox;
    QTextEdit *ReciveTextEdit;
    QCheckBox *checkBox_ShowReciveTime;
    QCheckBox *checkBox_SendLindFeed;
    QPushButton *pushButton_emptyCount;
    QCheckBox *checkBox_SendHex;
    QPushButton *SwitchButton;
    QTextEdit *SendtextEdit;
    QLabel *label_ReceiveCount;
    QPushButton *pushButton_openFile;
    QPushButton *pushButton_sendfile;

    void setupUi(QWidget *WidgetSerial)
    {
        if (WidgetSerial->objectName().isEmpty())
            WidgetSerial->setObjectName(QStringLiteral("WidgetSerial"));
        WidgetSerial->resize(738, 412);
        WidgetSerial->setMinimumSize(QSize(641, 351));
        WidgetSerial->setMaximumSize(QSize(738, 412));
        WidgetSerial->setAutoFillBackground(false);
        WidgetSerial->setStyleSheet(QStringLiteral(""));
        CleanSendButton = new QPushButton(WidgetSerial);
        CleanSendButton->setObjectName(QStringLiteral("CleanSendButton"));
        CleanSendButton->setGeometry(QRect(47, 340, 130, 23));
        SendButton = new QPushButton(WidgetSerial);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(47, 310, 130, 23));
        label_SendCount = new QLabel(WidgetSerial);
        label_SendCount->setObjectName(QStringLiteral("label_SendCount"));
        label_SendCount->setGeometry(QRect(483, 370, 54, 12));
        checkBox_ReciveHex = new QCheckBox(WidgetSerial);
        checkBox_ReciveHex->setObjectName(QStringLiteral("checkBox_ReciveHex"));
        checkBox_ReciveHex->setGeometry(QRect(651, 44, 71, 16));
        CleanReciveButton = new QPushButton(WidgetSerial);
        CleanReciveButton->setObjectName(QStringLiteral("CleanReciveButton"));
        CleanReciveButton->setGeometry(QRect(48, 254, 130, 23));
        layoutWidget = new QWidget(WidgetSerial);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(46, 40, 131, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Seriallabel = new QLabel(layoutWidget);
        Seriallabel->setObjectName(QStringLiteral("Seriallabel"));

        gridLayout->addWidget(Seriallabel, 0, 0, 1, 1);

        SerialcomboBoxl = new QComboBox(layoutWidget);
        SerialcomboBoxl->setObjectName(QStringLiteral("SerialcomboBoxl"));

        gridLayout->addWidget(SerialcomboBoxl, 0, 1, 1, 1);

        Baudlabel = new QLabel(layoutWidget);
        Baudlabel->setObjectName(QStringLiteral("Baudlabel"));

        gridLayout->addWidget(Baudlabel, 1, 0, 1, 1);

        BaudcomboBox = new QComboBox(layoutWidget);
        BaudcomboBox->setObjectName(QStringLiteral("BaudcomboBox"));

        gridLayout->addWidget(BaudcomboBox, 1, 1, 1, 1);

        Paritylabel = new QLabel(layoutWidget);
        Paritylabel->setObjectName(QStringLiteral("Paritylabel"));

        gridLayout->addWidget(Paritylabel, 2, 0, 1, 1);

        ParitycomboBox = new QComboBox(layoutWidget);
        ParitycomboBox->setObjectName(QStringLiteral("ParitycomboBox"));

        gridLayout->addWidget(ParitycomboBox, 2, 1, 1, 1);

        Datalabel = new QLabel(layoutWidget);
        Datalabel->setObjectName(QStringLiteral("Datalabel"));

        gridLayout->addWidget(Datalabel, 3, 0, 1, 1);

        DatacomboBox = new QComboBox(layoutWidget);
        DatacomboBox->setObjectName(QStringLiteral("DatacomboBox"));

        gridLayout->addWidget(DatacomboBox, 3, 1, 1, 1);

        Stoplabel = new QLabel(layoutWidget);
        Stoplabel->setObjectName(QStringLiteral("Stoplabel"));

        gridLayout->addWidget(Stoplabel, 4, 0, 1, 1);

        StopcomboBox = new QComboBox(layoutWidget);
        StopcomboBox->setObjectName(QStringLiteral("StopcomboBox"));

        gridLayout->addWidget(StopcomboBox, 4, 1, 1, 1);

        controlflowlabel = new QLabel(layoutWidget);
        controlflowlabel->setObjectName(QStringLiteral("controlflowlabel"));

        gridLayout->addWidget(controlflowlabel, 5, 0, 1, 1);

        controlflowcomboBox = new QComboBox(layoutWidget);
        controlflowcomboBox->setObjectName(QStringLiteral("controlflowcomboBox"));

        gridLayout->addWidget(controlflowcomboBox, 5, 1, 1, 1);

        ReciveTextEdit = new QTextEdit(WidgetSerial);
        ReciveTextEdit->setObjectName(QStringLiteral("ReciveTextEdit"));
        ReciveTextEdit->setGeometry(QRect(181, 44, 461, 231));
        ReciveTextEdit->setStyleSheet(QStringLiteral("background-color: rgba(229, 229, 229, 100);"));
        ReciveTextEdit->setReadOnly(true);
        checkBox_ShowReciveTime = new QCheckBox(WidgetSerial);
        checkBox_ShowReciveTime->setObjectName(QStringLiteral("checkBox_ShowReciveTime"));
        checkBox_ShowReciveTime->setGeometry(QRect(651, 64, 71, 16));
        checkBox_SendLindFeed = new QCheckBox(WidgetSerial);
        checkBox_SendLindFeed->setObjectName(QStringLiteral("checkBox_SendLindFeed"));
        checkBox_SendLindFeed->setGeometry(QRect(650, 328, 71, 16));
        pushButton_emptyCount = new QPushButton(WidgetSerial);
        pushButton_emptyCount->setObjectName(QStringLiteral("pushButton_emptyCount"));
        pushButton_emptyCount->setGeometry(QRect(568, 364, 75, 23));
        checkBox_SendHex = new QCheckBox(WidgetSerial);
        checkBox_SendHex->setObjectName(QStringLiteral("checkBox_SendHex"));
        checkBox_SendHex->setGeometry(QRect(650, 310, 71, 16));
        SwitchButton = new QPushButton(WidgetSerial);
        SwitchButton->setObjectName(QStringLiteral("SwitchButton"));
        SwitchButton->setGeometry(QRect(49, 224, 130, 23));
        SendtextEdit = new QTextEdit(WidgetSerial);
        SendtextEdit->setObjectName(QStringLiteral("SendtextEdit"));
        SendtextEdit->setGeometry(QRect(180, 310, 461, 51));
        label_ReceiveCount = new QLabel(WidgetSerial);
        label_ReceiveCount->setObjectName(QStringLiteral("label_ReceiveCount"));
        label_ReceiveCount->setGeometry(QRect(391, 370, 54, 12));
        pushButton_openFile = new QPushButton(WidgetSerial);
        pushButton_openFile->setObjectName(QStringLiteral("pushButton_openFile"));
        pushButton_openFile->setGeometry(QRect(650, 220, 75, 23));
        pushButton_sendfile = new QPushButton(WidgetSerial);
        pushButton_sendfile->setObjectName(QStringLiteral("pushButton_sendfile"));
        pushButton_sendfile->setGeometry(QRect(650, 250, 75, 23));
#ifndef QT_NO_SHORTCUT
        Seriallabel->setBuddy(SerialcomboBoxl);
        Baudlabel->setBuddy(BaudcomboBox);
        Paritylabel->setBuddy(ParitycomboBox);
        Datalabel->setBuddy(DatacomboBox);
        Stoplabel->setBuddy(StopcomboBox);
        controlflowlabel->setBuddy(controlflowcomboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(WidgetSerial);

        QMetaObject::connectSlotsByName(WidgetSerial);
    } // setupUi

    void retranslateUi(QWidget *WidgetSerial)
    {
        WidgetSerial->setWindowTitle(QApplication::translate("WidgetSerial", "\344\270\262\345\217\243\345\212\251\346\211\213 1.0", Q_NULLPTR));
        CleanSendButton->setText(QApplication::translate("WidgetSerial", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272\345\237\237", Q_NULLPTR));
        SendButton->setText(QApplication::translate("WidgetSerial", "\345\217\221\351\200\201", Q_NULLPTR));
        label_SendCount->setText(QApplication::translate("WidgetSerial", "\345\217\221\351\200\201\357\274\2320", Q_NULLPTR));
        checkBox_ReciveHex->setText(QApplication::translate("WidgetSerial", "Hex\346\230\276\347\244\272", Q_NULLPTR));
        CleanReciveButton->setText(QApplication::translate("WidgetSerial", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272\345\237\237", Q_NULLPTR));
        Seriallabel->setText(QApplication::translate("WidgetSerial", "\344\270\262  \345\217\243\357\274\232", Q_NULLPTR));
        Baudlabel->setText(QApplication::translate("WidgetSerial", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        BaudcomboBox->clear();
        BaudcomboBox->insertItems(0, QStringList()
         << QApplication::translate("WidgetSerial", "115200", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "9600", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "4800", Q_NULLPTR)
        );
        Paritylabel->setText(QApplication::translate("WidgetSerial", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        ParitycomboBox->clear();
        ParitycomboBox->insertItems(0, QStringList()
         << QApplication::translate("WidgetSerial", "None", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Even", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Odd", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Space", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Mark", Q_NULLPTR)
        );
        Datalabel->setText(QApplication::translate("WidgetSerial", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        DatacomboBox->clear();
        DatacomboBox->insertItems(0, QStringList()
         << QApplication::translate("WidgetSerial", "5", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "6", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "7", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "8", Q_NULLPTR)
        );
        Stoplabel->setText(QApplication::translate("WidgetSerial", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        StopcomboBox->clear();
        StopcomboBox->insertItems(0, QStringList()
         << QApplication::translate("WidgetSerial", "1", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "1.5", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "2", Q_NULLPTR)
        );
        controlflowlabel->setText(QApplication::translate("WidgetSerial", "\346\216\247\345\210\266\346\265\201\357\274\232", Q_NULLPTR));
        controlflowcomboBox->clear();
        controlflowcomboBox->insertItems(0, QStringList()
         << QApplication::translate("WidgetSerial", "NoFlow", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Hardward", Q_NULLPTR)
         << QApplication::translate("WidgetSerial", "Softward", Q_NULLPTR)
        );
        ReciveTextEdit->setHtml(QApplication::translate("WidgetSerial", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        checkBox_ShowReciveTime->setText(QApplication::translate("WidgetSerial", "\346\227\266\351\227\264\346\210\263", Q_NULLPTR));
        checkBox_SendLindFeed->setText(QApplication::translate("WidgetSerial", "\350\207\252\345\212\250\346\215\242\350\241\214", Q_NULLPTR));
        pushButton_emptyCount->setText(QApplication::translate("WidgetSerial", "\346\270\205\347\251\272\350\256\241\346\225\260", Q_NULLPTR));
        checkBox_SendHex->setText(QApplication::translate("WidgetSerial", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        SwitchButton->setText(QApplication::translate("WidgetSerial", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label_ReceiveCount->setText(QApplication::translate("WidgetSerial", "\346\216\245\346\224\266\357\274\2320", Q_NULLPTR));
        pushButton_openFile->setText(QApplication::translate("WidgetSerial", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_sendfile->setText(QApplication::translate("WidgetSerial", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetSerial: public Ui_WidgetSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSERIAL_H
