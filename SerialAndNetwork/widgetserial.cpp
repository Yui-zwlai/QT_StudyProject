#include "widgetserial.h"
#include "ui_widgetserial.h"

WidgetSerial::WidgetSerial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSerial)
{
    ui->setupUi(this);

    m_serial = new Serial;//创建对象
    receiveCount = 0;
    sendCount = 0;

    setStyleSheet("#WidgetSerial {border-image: url(:/image/2.jpg);}");
    m_timer = new QTimer;//定时器对象
    m_timer->setSingleShot(false);//设置定时器是否为单次触发。默认为 false 多次触发
    m_timer->start(50);//启动或重启定时器, 并设置定时器时间：毫秒

    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));//定时器触发信号槽
    connect(m_serial, SIGNAL(readSignal()), this, SLOT(ReadSerialData()));// 当下位机中有数据发送过来时就会响应这个槽函数


    ui->BaudcomboBox->setCurrentIndex(0);
    ui->ParitycomboBox->setCurrentIndex(0);
    ui->DatacomboBox->setCurrentIndex(3);
    ui->StopcomboBox->setCurrentIndex(0);
    ui->controlflowcomboBox->setCurrentIndex(0);
    ui->ReciveTextEdit->document()->setMaximumBlockCount(300);

}

WidgetSerial::~WidgetSerial()
{
    delete ui;
}

void WidgetSerial::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}



void WidgetSerial::on_SwitchButton_clicked()
{
    if(ui->SerialcomboBoxl->currentText().isEmpty())
    {
        QString dlgTitle="警告";
        QString strInfo="请选择串口";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
        return ;
    }

    if(ui->SwitchButton->text() == tr("打开串口"))
    {
        if(m_serial->Open(ui->SerialcomboBoxl->currentText(),
                       ui->BaudcomboBox->currentText(),
                       ui->ParitycomboBox->currentIndex(),
                       ui->DatacomboBox->currentIndex(),
                       ui->StopcomboBox->currentIndex(),
                       ui->controlflowcomboBox->currentIndex()))
        {
            ui->SwitchButton->setText(tr("关闭串口"));
            ui->SerialcomboBoxl->setEnabled(false);
            ui->BaudcomboBox->setEnabled(false);
            ui->ParitycomboBox->setEnabled(false);
            ui->DatacomboBox->setEnabled(false);
            ui->StopcomboBox->setEnabled(false);
            ui->controlflowcomboBox->setEnabled(false);
        }
        else
        {
            QString dlgTitle="错误";
            QString strInfo="串口被占用";
            QMessageBox::critical(this, dlgTitle, strInfo);
            return ;
        }
    }
    else
    {
        m_serial->Close();
        ui->SwitchButton->setText(tr("打开串口"));
        ui->SerialcomboBoxl->setEnabled(true);
        ui->BaudcomboBox->setEnabled(true);
        ui->ParitycomboBox->setEnabled(true);
        ui->DatacomboBox->setEnabled(true);
        ui->StopcomboBox->setEnabled(true);
        ui->controlflowcomboBox->setEnabled(true);
    }
}

//将16进制字符串转为ASCLL码字符串
static QString HexStrToASCLL(QString str)
{
    str.remove(" ",Qt::CaseInsensitive);
    qDebug()<<str;
    QString temp;
    QString ASCLLString;
    int sum = 0;

    for(int i = 0;i<str.size();i=i+2)
    {
        temp = str.mid(i,2);

        if(temp[0] >= 'a' && temp[0] <= 'z')
            sum = (temp[0].toLatin1() - 87) * 16;
        else if(temp[0] >= '0' && temp[0] <= '9')
            sum = (temp[0].toLatin1() - 48) * 16;

        if(temp[1] >= 'a' && temp[1] <= 'z')
            sum = sum + (temp[1].toLatin1() - 87);
        else if(temp[1] >= '0' && temp[1] <= '9')
            sum = sum + temp[1].toLatin1() - 48;

        ASCLLString.append(sum);
    }
    return ASCLLString;
}

void WidgetSerial::on_SendButton_clicked()
{
    if(ui->SwitchButton->text() == tr("打开串口"))
    {
        QString dlgTitle="错误";
        QString strInfo="串口未打开";
        QMessageBox::critical(this, dlgTitle, strInfo);
        return;
    }
    QString data =ui->SendtextEdit->toPlainText();

    if(ui->checkBox_SendHex->isChecked())
    {
        QRegExp rx("((\\s)|([0-9a-f]))+$");
        QRegExpValidator v(rx,0);
        int pos;
        if(v.validate(data,pos) == QValidator::Acceptable)
            data = HexStrToASCLL(data);
        else
        {
            QString dlgTitle="警告";
            QString strInfo="只能输入0-9，空格，a-z";
            QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
            return ;
        }

    }

    if(ui->checkBox_SendLindFeed->isChecked())
    {
        data.append("\n");
    }

    QByteArray sendData = data.toLocal8Bit();
    qDebug()<<sendData;

    sendCount += sendData.size();
    ui->label_SendCount->setText("发送："+QString::number(sendCount));

    m_serial->SendData(sendData);
    sendData.clear();
}

void WidgetSerial::on_CleanReciveButton_clicked()
{
    intTextback.clear();
    ui->ReciveTextEdit->clear();
}

void WidgetSerial::on_CleanSendButton_clicked()
{
    ui->SendtextEdit->clear();
}

static void InsertSpace(QString &Str)
{
    int n = Str.length();
    while(n > 0)
    {
        n = n - 2;
        Str.insert(n," ");//添加空格
    }
}

void WidgetSerial::on_checkBox_ReciveHex_clicked(bool checked)
{
    if(checked)
    {
        QString originStr = ui->ReciveTextEdit->toPlainText(); // 保存接收文本框原本的数据
        originStr.remove(" ",Qt::CaseInsensitive);//去掉空格
        QString hexStr = originStr.toUtf8().toHex();
        InsertSpace(hexStr);
        ui->ReciveTextEdit->clear();
        ui->ReciveTextEdit->setText(hexStr);
    }
    else
    {
        ui->ReciveTextEdit->clear();
        ui->ReciveTextEdit->setText(intTextback);
    }
    ui->ReciveTextEdit->moveCursor(QTextCursor::End);//光标移至末尾
}

void WidgetSerial::on_checkBox_SendHex_clicked(bool checked)
{
    if(checked)
    {
        ui->checkBox_SendLindFeed->setChecked(false);
        ui->checkBox_SendLindFeed->setEnabled(false);
        ui->SendtextEdit->clear();
    }
    else
    {
        ui->checkBox_SendLindFeed->setEnabled(true);
        ui->SendtextEdit->clear();
    }
}

void WidgetSerial::on_pushButton_emptyCount_clicked()
{
    receiveCount = 0;
    sendCount = 0;
    ui->label_SendCount->setText("发送："+QString::number(sendCount));
    ui->label_ReceiveCount->setText("接收："+QString::number(receiveCount));

}

void WidgetSerial::ReadSerialData()
{
    QString readbuf;
    QString data = QString::fromLocal8Bit(m_serial->GetReadBuf());

    intTextback.append(data);

    receiveCount += data.size();
    ui->label_ReceiveCount->setText("接收："+QString::number(receiveCount));

    if(ui->checkBox_ReciveHex->isChecked())
    {
        QString temp =data.toUtf8().toHex();
        InsertSpace(temp);
        readbuf.append(temp);
    }
    else
        readbuf.append(data);

    if(ui->checkBox_ShowReciveTime->isChecked())
    {
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy-MM-dd hh:mm:ss.zzz");
        readbuf.append("["+current_date+"]\n");
    }

    ui->ReciveTextEdit->insertPlainText(readbuf);
    ui->ReciveTextEdit->moveCursor(QTextCursor::End);//光标移至末尾

    m_serial->ClearReadBuf(); // 读取完后，清空数据缓冲区
}

void WidgetSerial::TimerTimeOut()
{
    if(m_timer->isActive())//判断定时器是否运行
        m_timer->stop();   //停止定时器

    QStringList currentSerialList = m_serial->scanSerial();//获取串口列表

    if (serialStrList != currentSerialList)
    {
        for(QString str:serialStrList)
        {
            if(!currentSerialList.contains(str))//查找消失的串口
            {
                if(ui->SwitchButton->text() == tr("关闭串口") && str == ui->SerialcomboBoxl->currentText())//消失的串口正在被打开
                    emit on_SwitchButton_clicked();
                break;
            }
        }
        serialStrList = currentSerialList;

        ui->SerialcomboBoxl->clear();//清除串口列表
        for(int i = 0; i < serialStrList.size(); i++)//将串口列表进行显示
        {
            ui->SerialcomboBoxl->addItem(serialStrList[i]);
        }

    }
    m_timer->start(2000);
}


void WidgetSerial::on_pushButton_openFile_clicked()
{
    if(ui->SwitchButton->text() == tr("打开串口"))
    {
        QString dlgTitle="错误";
        QString strInfo="串口未打开";
        QMessageBox::critical(this, dlgTitle, strInfo);
        return;
    }
    m_fileName = QFileDialog::getOpenFileName(this,
                                            tr("文件对话框！"),
                                            "./",
                                            tr("本本文件(*bin)"));
    int sum = 0;
    QString String;
    QFile f(m_fileName);
    if(f.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while(!f.atEnd())
        {
            m_fileArray = f.read(256);
            String = QString::fromLocal8Bit(m_fileArray.toHex());
            ui->ReciveTextEdit->append(String);
            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            m_serial->SendData(m_fileArray);
            sum += m_fileArray.length();
            qDebug() << m_fileArray.length();
        }
        f.close();
    }
    if(f.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        while(!f.atEnd())
        {
            QByteArray fileArray;
            fileArray = f.readAll();
            qDebug() << fileArray.length();

            qDebug() << f.size();
        }
        f.close();
    }

}
