#include "widget_login.h"
#include "ui_widget_login.h"



Widget_Login::Widget_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Login)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
//    setWindowOpacity(0.8);
//    setStyleSheet("zWidget_Login{background-color: rgba(255, 0, 0, 0.5);}");
//    setAttribute(Qt::WA_TranslucentBackground);
    QPalette palette = this->palette();
    QImage ImgAllbackground(":/img/img/login.jpg");
    QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, QBrush(fitimgpic));
    setPalette(palette);

    m_tcpClient = new TcpClient;
}



Widget_Login::~Widget_Login()
{
    delete ui;
}

void Widget_Login::mouseMoveEvent(QMouseEvent  *e)
{
    QPoint pt = e->globalPos()- m_pt;
    move(pt);
}
void Widget_Login::mousePressEvent(QMouseEvent *e)
{
   if(e->button() == Qt::LeftButton)
   {
       m_pt = e->globalPos() - this->frameGeometry().topLeft();
   }
}

void Widget_Login::on_pushButton_Exit_clicked()
{
    close();
}

void Widget_Login::on_pushButton_Login_clicked()
{
   QString IP;
   QString PORT;
   bool * ok;

   ui->pushButton_Login->setEnabled(false);

   QFile f(QCoreApplication::applicationDirPath() + "/config.ini");
   cout << QCoreApplication::applicationDirPath();
   if (!f.open(QIODevice::ReadOnly|QIODevice::Text))
   {
       QMessageBox::about(NULL, "文件", "配置文件出错");
       ui->pushButton_Login->setEnabled(true);
       return;
   }
   else
   {
       QTextStream txtInput(&f);
       IP = txtInput.readLine();
       PORT = txtInput.readLine();

       IP = IP.remove("IP=");
       PORT = PORT.remove("PORT=");
   }
    cout << IP;
    cout << PORT;
   if(m_tcpClient->ConnectToHost(IP,PORT.toInt(ok,10)))
   {
       QTime dieTime = QTime::currentTime().addMSecs(1000);
       while( QTime::currentTime() < dieTime )
           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

       if("PC=MAX" == m_tcpClient->GetReadBuf())
       {
           m_tcpClient->DisconnectFromHost();
           m_tcpClient->CleanReadBuf();
           m_tcpClient->CleanIP();
           QMessageBox::critical(this,"错误","登录失败,位置已满",QMessageBox::Ok);
           ui->pushButton_Login->setEnabled(true);
           return;
       }



       W_main = new Widget_main(m_tcpClient);
       W_main->show();
       hide();

   }
   else
   {
       QMessageBox::critical(this,"错误","连接失败,请检查网络设置",QMessageBox::Ok);
   }
   ui->pushButton_Login->setEnabled(true);

}
