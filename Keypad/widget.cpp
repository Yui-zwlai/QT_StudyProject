#include "widget.h"

#include "ui_widget.h"
#include <QCoreApplication>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(QPixmap(":/img/bitbug_favicon.ico")));
    setMaximumSize(QSize(400,200));
    setMinimumSize(QSize(400,200));


    path = QCoreApplication::applicationDirPath()+"/data";
    ui->textEdit->append("路径："+path);

    ConnectSQL();

    m_timer = new QTimer;//定时器对象
    m_timer->setSingleShot(false);//设置定时器是否为单次触发。默认为 false 多次触发
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));//定时器触发信号槽
    m_timer->start(5000);


}

void Widget::ConnectSQL()
{
    QString config_server="PYSQL00";
    QString config_database = "QCInspectionReport";
    QString config_usernsame = "EBUser";
    QString config_password  = "ebuser2018";

    //连接数据库
    if(QSqlDatabase::contains("QC"))
      db = QSqlDatabase::database("QC");
    else
      db = QSqlDatabase::addDatabase("QODBC","QC");

    QString dsn=QString::fromLocal8Bit("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2").arg(config_server).arg(config_database);
    db.setDatabaseName(dsn);
    //即使dsn中已经设置了UID和PASSWD，仍然需要执行setUserName和setPassword的步骤
    db.setUserName(config_usernsame);
    db.setPassword(config_password);

    query = new QSqlQuery(db);

    if(db.open())
    {
        ui->textEdit->append("数据库连接成功");
    }
    else
    {
        ui->textEdit->append("数据库连接失败");
    }
}

void Widget::WriteSQL(QByteArray str)
{
    QString data = QString(str);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");

    QString cmd = QString("INSERT INTO ProductionBarCodeInfo(BarcodeNo,LastDate)VALUES('%1','%2')")
            .arg(data).arg(current_date);

    if (query->exec(cmd))
    {
        ui->textEdit->append("写入成功 " +data + "    " + current_date);
    }
    else
    {
        ui->textEdit->append("写入失败 ");
    }
}

void Widget::TimerTimeOut()
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.txt";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    cout << files;

    foreach(QString s, files)
    {
        QString Path;
        Path = path + "/" +s;
        cout << Path;
        QFile file(Path);
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QByteArray array;
            if(!file.atEnd())
            {
                array = file.readLine();
                WriteSQL(array);
            }
        }
        file.remove();
        file.close();
    }
}

Widget::~Widget()
{
    delete ui;
}
