#include "widgetnetwork.h"
#include "ui_widgetnetwork.h"

#define TCP_SERVER (ui->comboBox_Protocol->currentText() == "tcp server")
#define TCP_CLIENT (ui->comboBox_Protocol->currentText() == "tcp client")
#define UDP (ui->comboBox_Protocol->currentText() == "udp")

static void InsertSpace(QString &Str)
{
    int n = Str.length();
    while(n > 0)
    {
        n = n - 2;
        Str.insert(n," ");//添加空格
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

WidgetNetwork::WidgetNetwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetNetwork)
{
    ui->setupUi(this);
    setStyleSheet("#WidgetNetwork{border-image: url(:/image/2.jpg);}");
    ui->lineEdit_IPAddr->setText(QNetworkInterface().allAddresses().at(3).toString());
    ui->lineEdit_IPAddr->setEnabled(false);
    ui->lineEdit_Port->setText("8080");
    ui->pushButton_Send->setEnabled(false);
    ui->textEdit_recive->document()->setMaximumBlockCount(300);//设置textEdit最大显示行数
    ui->comboBox_ConnectObject->setEnabled(false);
    ui->checkBox_Timer->setEnabled(false);
    ui->lineEdit_Port->setValidator(new QIntValidator(1, 65535, this));//限制lineEdit输入数字
    ui->lineEdit_Timer->setValidator(new QIntValidator(1, 65535, this));//限制lineEdit输入数字

    QRegExp regx("(([0-9.]))+$");//0-9 .
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit_IPAddr );
    ui->lineEdit_IPAddr->setValidator(validator);//限制lineEdit输入IP地址

    m_tcpServer = new TcpServer;
    connect(m_tcpServer,SIGNAL(ReadDataReady()),this,SLOT(ReadData()));//客户端有数据时触发
    connect(m_tcpServer,SIGNAL(NewConnectionReady(QString)),this,SLOT(ConnectionAdd(QString)));
    connect(m_tcpServer,SIGNAL(ConnectionBreakReady(QString)),this,SLOT(ConnectionRemove(QString)));

    m_tcpClient = new TcpClient;
    connect(m_tcpClient,SIGNAL(ReadDataReady()),this,SLOT(ReadData()));//服务端有数据时触发
    connect(m_tcpClient,SIGNAL(ConnectErrorReady(QString)),this,SLOT(ConnectError(QString)));

    m_udp = new Udp;
    connect(m_udp,SIGNAL(ReadDataReady()),this,SLOT(ReadData()));//有数据时触发

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));//定时器触发信号槽

    connect(ui->pushButton_shortcut1,SIGNAL(clicked(bool)),this,SLOT(ShortCutButton()));
    connect(ui->pushButton_shortcut2,SIGNAL(clicked(bool)),this,SLOT(ShortCutButton()));
    connect(ui->pushButton_shortcut3,SIGNAL(clicked(bool)),this,SLOT(ShortCutButton()));
    connect(ui->pushButton_shortcut4,SIGNAL(clicked(bool)),this,SLOT(ShortCutButton()));

}

WidgetNetwork::~WidgetNetwork()
{
    delete ui;
}

void WidgetNetwork::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//连接按钮
void WidgetNetwork::on_pushButton_Connect_clicked()
{
    QString IPAddr = ui->lineEdit_IPAddr->text();
    QString port = ui->lineEdit_Port->text();

    QHostAddress test;
    if (!test.setAddress(IPAddr) || !IPAddr.contains("."))
    {
        QMessageBox::critical(this, "错误", "地址无效");
        return;
    }

    if(port.isEmpty())
        QMessageBox::critical(this, "错误", "端口无效");

    if(TCP_SERVER)
    {
        if(ui->pushButton_Connect->text() == "连接")
        {
            bool ok = m_tcpServer->Listen(port.toInt());
            if(ok)
            {
                ui->pushButton_Connect->setText("断开");
                ui->pushButton_Send->setEnabled(true);
                ui->checkBox_Timer->setEnabled(true);
                ui->lineEdit_Port->setEnabled(false);
                ui->comboBox_Protocol->setEnabled(false);
                ui->comboBox_ConnectObject->setEnabled(true);
            }
            else
                QMessageBox::critical(this, "错误", "连接失败");
        }
        else
        {
            m_tcpServer->Break();
            ui->pushButton_Connect->setText("连接");
            ui->pushButton_Send->setEnabled(false);
            ui->checkBox_Timer->setEnabled(false);
            ui->checkBox_Timer->setChecked(false);
            emit on_checkBox_Timer_clicked(false);
            ui->lineEdit_Port->setEnabled(true);
            ui->comboBox_Protocol->setEnabled(true);
            ui->comboBox_ConnectObject->setEnabled(false);
        }
    }
    else if (TCP_CLIENT)
    {
        if(ui->pushButton_Connect->text() == "连接")
        {
            if(m_tcpClient->ConnectToHost(IPAddr,port.toInt()))
            {
                ui->pushButton_Connect->setText("断开");
                ui->pushButton_Send->setEnabled(true);
                ui->checkBox_Timer->setEnabled(true);
                ui->lineEdit_Port->setEnabled(false);
                ui->lineEdit_IPAddr->setEnabled(false);
                ui->comboBox_Protocol->setEnabled(false);
            }
            else
                QMessageBox::critical(this, "错误", "找不到主机");
        }
        else
        {
            m_tcpClient->DisconnectFromHost();
            ui->pushButton_Connect->setText("连接");
            ui->pushButton_Send->setEnabled(false);
            ui->checkBox_Timer->setEnabled(false);
            ui->checkBox_Timer->setChecked(false);
            emit on_checkBox_Timer_clicked(false);
            ui->lineEdit_Port->setEnabled(true);
            ui->lineEdit_IPAddr->setEnabled(true);
            ui->comboBox_Protocol->setEnabled(true);
        }
    }
    else if (UDP)
    {
        if (ui->pushButton_Connect->text() == "连接")
        {
            m_udp->Bind(port.toInt());
            ui->pushButton_Connect->setText("断开");
            ui->pushButton_Send->setEnabled(true);
            ui->checkBox_Timer->setEnabled(true);
            ui->lineEdit_Port->setEnabled(false);
            ui->lineEdit_IPAddr->setEnabled(false);
            ui->comboBox_Protocol->setEnabled(false);
        }
        else
        {
            m_udp->Close();
            ui->pushButton_Connect->setText("连接");
            ui->pushButton_Send->setEnabled(false);
            ui->checkBox_Timer->setEnabled(false);
            ui->checkBox_Timer->setChecked(false);
            emit on_checkBox_Timer_clicked(false);
            ui->lineEdit_Port->setEnabled(true);
            ui->lineEdit_IPAddr->setEnabled(true);
            ui->comboBox_Protocol->setEnabled(true);
        }
    }
    ui->lineEdit_Timer->setEnabled(true);
}

//发送按钮
void WidgetNetwork::on_pushButton_Send_clicked()
{  
    if(ui->textEdit_send->toPlainText().isEmpty())
        return;

    QString data =ui->textEdit_send->toPlainText();

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

    QByteArray sendData = data.toLocal8Bit();

    if (TCP_SERVER)
        m_tcpServer->SendData(sendData,ui->comboBox_ConnectObject->currentText());
    else if (TCP_CLIENT)
        m_tcpClient->SendData(sendData);
    else if (UDP)
        m_udp->SendData(sendData,ui->comboBox_ConnectObject->currentText(),8081);

    static QString currentIP;

    currentIP = "[本地]:";

    qDebug()<< data;
    qDebug()<< sendData;

    if(currentIP != IP)
        ui->textEdit_recive->append(currentIP);

    ui->textEdit_recive->append(sendData);
    ui->textEdit_recive->moveCursor(QTextCursor::End);//鼠标移至末尾

    IP = currentIP;
}


//协议选择
void WidgetNetwork::on_comboBox_Protocol_currentIndexChanged(const QString &arg1)
{
    qDebug() << arg1;
    if(arg1 == "tcp server")
    {
        ui->label_IPAddr->setText("本地IP地址");
        ui->label_Port->setText("本地端口");
        ui->lineEdit_IPAddr->setText(QNetworkInterface().allAddresses().at(3).toString());
        ui->lineEdit_IPAddr->setEnabled(false);
    }
    else if (arg1 == "tcp client")
    {
        ui->label_IPAddr->setText("主机IP地址");
        ui->label_Port->setText("主机端口");
        ui->lineEdit_IPAddr->setEnabled(true);
    }
    else if (arg1 == "udp")
    {
        ui->label_IPAddr->setText("本地IP地址");
        ui->label_Port->setText("本地端口");
        ui->lineEdit_IPAddr->setText(QNetworkInterface().allAddresses().at(3).toString());
        ui->lineEdit_IPAddr->setEnabled(false);
    }
}

void WidgetNetwork::on_pushButton_SeendClean_clicked()
{
    ui->textEdit_send->clear();
}

void WidgetNetwork::on_pushButton_ReciveClean_clicked()
{
    ui->textEdit_recive->clear();
}

void WidgetNetwork::on_checkBox_Timer_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_Timer->setEnabled(false);
        m_timer->setSingleShot(false);
        m_timer->start(ui->lineEdit_Timer->text().toInt());
    }
    else
    {
        ui->lineEdit_Timer->setEnabled(true);
        m_timer->stop();
    }
}

void WidgetNetwork::on_pushButton_ReciveSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "另存文件",
                                                    ".\\",
                                                    "文本文件(*.txt)");

    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","打开失败");
        return;
    }

    QString str = ui->textEdit_recive->toPlainText();
    QByteArray  strBytes=str.toUtf8();
    if(file.write(strBytes,strBytes.length()) == -1)
        QMessageBox::critical(this,"错误","写入失败");
    else
        QMessageBox::information(this,"提示","保存成功");
    file.close();
}

void WidgetNetwork::on_checkBox_SendHex_clicked(bool checked)
{
    static QString originStr;

    if(ui->textEdit_send->toPlainText().isEmpty())
        return;

    if(checked)
    {
        originStr = ui->textEdit_send->toPlainText(); // 保存接收文本框原本的数据
        originStr.remove(" ",Qt::CaseInsensitive);//去掉空格
        QString hexStr = originStr.toUtf8().toHex();
        InsertSpace(hexStr);
        ui->textEdit_send->clear();
        ui->textEdit_send->setText(hexStr);
    }
    else
    {
        ui->textEdit_send->clear();
        ui->textEdit_send->setText(originStr);
    }
    ui->textEdit_send->moveCursor(QTextCursor::End);//光标移至末尾
}



void WidgetNetwork::on_toolButton_clicked()
{
    static int i = 1;
    ui->stackedWidget->setCurrentIndex(i);
    i++;
    if(i==2)
        i=0;
}


//读取数据并显示
void WidgetNetwork::ReadData()
{ 
    if(TCP_SERVER)
    {
        QString data = QString::fromLocal8Bit(m_tcpServer->GetReadBuf());
        QString readbuf;
        static QString currentIP;

        currentIP = m_tcpServer->GetClientIP();

        if(currentIP != IP)     
            readbuf.append(currentIP + "\n");

        if(ui->checkBox_ReciveHex->isChecked())
        {
            QString temp =data.toUtf8().toHex();
            InsertSpace(temp);
            readbuf.append(temp);
        }
        else
            readbuf.append(data);
        ui->textEdit_recive->append(readbuf);
        ui->textEdit_recive->moveCursor(QTextCursor::End);//鼠标移至末尾

        m_tcpServer->CleanReadBuf();
        m_tcpServer->CleanIP();
        IP = currentIP;
    }
    else if (TCP_CLIENT)
    {
        QString data = QString::fromLocal8Bit(m_tcpClient->GetReadBuf());
        QString readbuf;
        static QString currentIP;

        currentIP = m_tcpClient->GetServerIP();

        if(currentIP != IP)
            readbuf.append(currentIP + "\n");

        if(ui->checkBox_ReciveHex->isChecked())
        {
            QString temp =data.toUtf8().toHex();
            InsertSpace(temp);
            readbuf.append(temp);
        }
        else
            readbuf.append(data);

        ui->textEdit_recive->append(readbuf);
        ui->textEdit_recive->moveCursor(QTextCursor::End);//鼠标移至末尾

        m_tcpClient->CleanReadBuf();
        m_tcpServer->CleanIP();
        IP = currentIP;
    }
    else if (UDP)
    {
        QString data = QString::fromLocal8Bit(m_udp->GetReadBuf());
        QString readbuf;
        static QString currentIP;

        currentIP = m_udp->GetIP();

        if(currentIP != IP)
            readbuf.append(currentIP + "\n");

        if(ui->checkBox_ReciveHex->isChecked())
        {
            QString temp =data.toUtf8().toHex();
            InsertSpace(temp);
            readbuf.append(temp);
        }
        else
            readbuf.append(data);

        ui->textEdit_recive->append(readbuf);
        ui->textEdit_recive->moveCursor(QTextCursor::End);//鼠标移至末尾

        m_udp->CleanReadBuf();
        m_udp->CleanIP();
        IP = currentIP;
    }
}

//作为客户端时服务端断开连接
void WidgetNetwork::ConnectError(QString errorQString)
{
    emit on_pushButton_Connect_clicked();
    QMessageBox::critical(this, "错误", tr("failed to connect server because %1").arg(errorQString));
}

//当有客户端连接时添加
void WidgetNetwork::ConnectionAdd(QString str)
{
    ui->comboBox_ConnectObject->addItem(str);
}

//当有客户端断开时移除
void WidgetNetwork::ConnectionRemove(QString str)
{
    for(int i = 0; i < ui->comboBox_ConnectObject->maxCount();i++)
        if(ui->comboBox_ConnectObject->itemText(i) == str)
        {
            ui->comboBox_ConnectObject->removeItem(i);
            return;
        }
}

//定时器超时
void WidgetNetwork::TimerTimeOut()
{
    emit on_pushButton_Send_clicked();
    m_timer->start(ui->lineEdit_Timer->text().toInt());
}

void WidgetNetwork::ShortCutButton()
{
    QObject* sender = QObject::sender();
    QByteArray sendData;
    if(sender == ui->pushButton_shortcut1)
        sendData = ui->lineEdit_shortcut1->text().toLocal8Bit();
    else if(sender == ui->pushButton_shortcut2)
        sendData =ui->lineEdit_shortcut2->text().toLocal8Bit();
    else if(sender == ui->pushButton_shortcut3)
        sendData =ui->lineEdit_shortcut3->text().toLocal8Bit();
    else if(sender == ui->pushButton_shortcut4)
        sendData =ui->lineEdit_shortcut4->text().toLocal8Bit();

    if (TCP_SERVER)
        m_tcpServer->SendData(sendData,ui->comboBox_ConnectObject->currentText());
    else if (TCP_CLIENT)
        m_tcpClient->SendData(sendData);
    else if (UDP)
        m_udp->SendData(sendData,ui->comboBox_ConnectObject->currentText(),8081);

    ui->textEdit_recive->append(sendData);
    ui->textEdit_recive->moveCursor(QTextCursor::End);//鼠标移至末尾
}
