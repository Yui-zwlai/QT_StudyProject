#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("中国象棋服务端");
    setMaximumSize(QSize(400,200));
    setMinimumSize(QSize(400,200));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./user.db");//设置数据库名
    db.setUserName("laizewei");//设置数据库用户名
    db.setPassword("123456");//设置数据库密码
    if (!db.open())//打开数据库
    {
        cout << "无法建立数据库连接";
    }
    QSqlQuery query;
    bool success = query.exec("create table user(id int primary key,UserName varchar,"
                                      "Password varchar)");
    if(success)
        cout << "创建成功";
    else
        cout << "创建失败";
    query.prepare("insert into user values(?, ?, ?)");
    query.bindValue(0, 1);
    query.bindValue(1, "zwlai");
    query.bindValue(2, "123");

    m_tcpServer = new TcpServer;
    if(m_tcpServer->Listen(8080))
    {
        ui->textEdit->append("开始监听，端口：8080");
    }
    else
    {
        ui->textEdit->append("监听失败");
    }

    connect(m_tcpServer,SIGNAL(ReadDataReady()),this,SLOT(ReadData()));
    connect(m_tcpServer,SIGNAL(NewConnectionReady(QString)),this,SLOT(NewConnection(QString)));
    connect(m_tcpServer,SIGNAL(ConnectionBreakReady(QString)),this,SLOT(ConnectionBreak(QString)));

    m_connectionNumber = 0;
    m_confrontationNumber = 0;
    m_player1 = false;
    m_player2 = false;
    m_player1Ready = false;
    m_player2Ready = false;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::ReadData()
{
    QByteArray Data = m_tcpServer->GetReadBuf();
    QString ID = m_tcpServer->GetClientIP();
    cout << ID;
    cout << Data;

    if(Data == "Ready")
    {
        if(ID == m_player1ID)
        {
            m_player1Ready = true;

        }
        else if(ID == m_player2ID)
        {
            m_player2Ready = true;
        }
        if(m_player1Ready && m_player2Ready)
        {
            if(m_confrontationNumber % 2 == 0)
            {
                m_tcpServer->SendData("PC=RED",m_player1ID);
                m_tcpServer->SendData("PC=BLACK",m_player2ID);
            }
            else
            {
                m_tcpServer->SendData("PC=BLACK",m_player1ID);
                m_tcpServer->SendData("PC=RED",m_player2ID);
            }
            Delay();
            m_confrontationNumber++;
            m_tcpServer->SendData("Start",m_player1ID);
            m_tcpServer->SendData("Start",m_player2ID);
            m_player1Ready = false;
            m_player1Ready = false;
            Delay();
        }
    }


    if(ID == m_player1ID)
    {
        ui->textEdit->append("玩家1：" + Data);
        if(m_player2)
            m_tcpServer->SendData(Data,m_player2ID);
    }
    else if (ID == m_player2ID)
    {
        ui->textEdit->append("玩家2：" + Data);
        if(m_player1)
        {
            m_tcpServer->SendData(Data,m_player1ID);
        }
    }
}

void Widget::NewConnection(QString IP)
{
    if(m_player1 == false)
    {
        m_player1 = true;
        m_player1ID = IP;
        m_connectionNumber++;
        ui->textEdit->append("玩家1已连接");
    }
    else if (m_player2 == false)
    {
        m_player2 = true;
        m_player2ID = IP;
        m_connectionNumber++;
        ui->textEdit->append("玩家2已连接");
    }
    else
    {
        m_tcpServer->SendData("PC=MAX",IP);
        m_tcpServer->m_threadList[m_tcpServer->m_threadList.length()-1]->m_tcpSocket->disconnectFromHost();
        m_tcpServer->m_threadList[m_tcpServer->m_threadList.length()-1]->quit();
        m_tcpServer->m_threadList.removeAt(m_tcpServer->m_threadList.length()-1);
    }
}

void Widget::ConnectionBreak(QString IP)
{
    if(IP == m_player1ID)
    {
        m_player1 = false;
        m_player1Ready = false;
        m_player1ID.clear();
        ui->textEdit->append("玩家1已断开");
        m_connectionNumber--;
    }
    else if (IP == m_player2ID)
    {
        m_player2 = false;
        m_player2Ready = false;
        m_player2ID.clear();
        ui->textEdit->append("玩家2已断开");
        m_connectionNumber--;
    }


    if(m_connectionNumber == 0)
    {
        m_tcpServer->Break();
        m_tcpServer->Listen(8080);
    }
}

void Widget::Delay()
{
    QTime dieTime = QTime::currentTime().addMSecs(200);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
