#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("JBot v1.3");


    m_saveFile = new QFile();

    m_serial = new Serial();
    m_serialList = m_serial->scanSerial();

    ui->comboBox->addItems(m_serialList);

    connect(m_serial,SIGNAL(readSignal()),this,SLOT(readData()));

     m_filePath = QCoreApplication::applicationDirPath() + "/1.txt";

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_recording->setEnabled(false);
    ui->pushButton_play->setEnabled(false);
    ui->pushButton_auto->setEnabled(false);

    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/1.mp3"));
    player->setVolume(30);
    player->play();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readData()
{
    QByteArray array_bak = m_serial->GetReadBuf();
    static QByteArray array;
    unsigned char Sum;
    unsigned char LPOS = 0,HPOS = 0;
    int pos = 0;


    array.append(array_bak);

    while(array.size() >= 8)
    {
        if((unsigned char)array[0] == 0xff)
        {
            if((unsigned char)array[1] == 0xff)
            {
                Sum = 0;
                for(int i = 2; i < 7; i++)
                {
                    Sum += array[i];
                }
                Sum = (unsigned char)~Sum;
                if((unsigned char)array[7] == Sum)
                {
                    LPOS = array[5];
                    HPOS = array[6];
                    pos = (((int)HPOS*256) | (int)LPOS);

                    intList.append(pos);
                    //cout << intList;
                    cout << intList.size();
                    array.remove(0,8);
                }
            }
            else
            {
                array.remove(0,2);
            }
        }
        else
        {
            array.remove(0,1);
        }
    }
}

void Widget::on_pushButton_open_clicked()
{
    if(ui->pushButton_open->text() == "打开")
    {
        if(m_serial->Open(ui->comboBox->currentText(),"250000") == true)
        {
            ui->pushButton_open->setText("关闭");
            ui->comboBox->setEnabled(false);
            ui->pushButton_recording->setEnabled(true);
            ui->pushButton_play->setEnabled(true);

        }
        else
            QMessageBox::information(this,"提示","串口打开失败");
    }
    else
    {
        m_serial->Close();
        ui->pushButton_open->setText("打开");
        ui->comboBox->setEnabled(true);
        ui->pushButton_recording->setEnabled(false);
        ui->pushButton_play->setEnabled(false);
    }
}

void Widget::on_pushButton_play_clicked()
{
    if(ui->pushButton_open->text() == "打开")
        return;


    QFile file(m_filePath);
    bool isok = file.open(QIODevice::ReadOnly);
    bool ok;
    unsigned char ID,Sum;
    unsigned char LPOS,HPOS;

    if(isok)
    {

        QList<QByteArray> arrayList;
        while(!file.atEnd())
        {
            ID = 1;
            Sum = 0;

            arrayList = file.readLine().trimmed().split('\t');
            cout << arrayList.size();
            if(arrayList.size() != 16)
                break;

            if(1)
            {
                QByteArray array;
                array.resize(88);
                array[0] = 0xff;
                array[1] = 0xff;
                array[2] = 0xfe;
                array[3] = 0x54;
                array[4] = 0x83;
                array[5] = 0x1e;
                array[6] = 0x04;

                for(int i = 0; i <= 15; i++)
                {
                    LPOS = (unsigned char)(arrayList[i].toInt(&ok,10)&0xff);
                    HPOS = (unsigned char)((arrayList[i].toInt(&ok,10)&0xff00) / 256);
                    array[6+(i*5+1)] = ID;
                    array[6+(i*5+2)] = LPOS;
                    array[6+(i*5+3)] = HPOS;
                    array[6+(i*5+4)] = 0xFF;
                    array[6+(i*5+5)] = 0x02 ;
                    ID++;
                }

                for(int i = 2; i < 87; i++)
                {
                    Sum += array[i];
                }
                Sum = (unsigned char)~Sum;
                array[87] = Sum;
                cout << array;
                m_serial->SendData(array);
            }
            else
            {
                QByteArray array;
                array.resize(56);
                array[0] = 0xff;
                array[1] = 0xff;
                array[2] = 0xFE;
                array[3] = 0x34;
                array[4] = 0x83;
                array[5] = 0x1E;
                array[6] = 0x02;

                for(int i = 0; i <= 15; i++)
                {
                    LPOS = (unsigned char)(arrayList[i].toInt(&ok,10)&0xff);
                    HPOS = (unsigned char)((arrayList[i].toInt(&ok,10)&0xff00) / 256);
                    array[6+(i*3+1)] = ID;
                    array[6+(i*3+2)] = LPOS;
                    array[6+(i*3+3)] = HPOS;
                    ID++;
                }

                for(int i = 2; i < 55; i++)
                {
                    Sum += array[i];
                }
                Sum = (unsigned char)~Sum;
                array[55] = Sum;
                cout << array;
                m_serial->SendData(array);
            }




            QTime dieTime = QTime::currentTime().addMSecs(1000/ui->spinBox->value());
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        file.close();

    }
    else
    {
        QMessageBox::information(this,"提示","文件打开失败");
    }

}



void Widget::on_pushButton_2_clicked()
{
    unsigned char Sum = 0;

    unsigned char R_pos_buff[] = {0xff,0xff,0x00,0x04,0x02,0x24,0x02,0x00};

    for(int ID = 1; ID <= 16; ID++)
    {
        Sum = 0;
        R_pos_buff[2] = (unsigned char)ID;

        for(int i = 2; i < 7; i++)
        {
            Sum += R_pos_buff[i];
        }
        Sum = (unsigned char)~Sum;
        R_pos_buff[7] = Sum;

        QByteArray array;
        array.resize(8);
        for(int i = 0; i < 8; i++)
        {
            array[i] = R_pos_buff[i];
        }
        m_serial->SendData(array);
        QTime dieTime = QTime::currentTime().addMSecs(ui->spinBox->value());
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Widget::on_pushButton_recording_clicked()
{
    if(ui->pushButton_recording->text() == "录制")
    {
        m_saveFile->setFileName(QCoreApplication::applicationDirPath()+"/2.txt");
        m_saveFile->open(QIODevice::WriteOnly);


        unsigned char SUM;
        unsigned char CMD[] = {0xff,0xff,0x00,0x04,0x03,0x18,0x00,0x00};
        for( unsigned char ID = 1; ID <= 1; ID++)
        {
            SUM = 0;
            CMD[2] = ID;
            for(int j = 2; j < 7; j++)
            {
                SUM +=  CMD[j];
            }
            SUM = (unsigned char)~SUM;
            CMD[7] = SUM;
            QByteArray array;
            array.resize(8);
            for(int i = 0; i < 8; i++)
            {
                array[i] = CMD[i];
            }
            m_serial->SendData(array);
            QTime dieTime = QTime::currentTime().addMSecs(ui->spinBox->value());
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        ui->pushButton_recording->setText("停止");
        ui->pushButton_play->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_auto->setEnabled(true);

    }
    else
    {
        QString String;
        int n1[16],n2[16];
        int n3 = 0;

        if(intList.size() % 16 !=0)
        {
            QMessageBox::information(this,"提示","数据出错");
            intList.clear();
        }
        else
        {

            while(intList.size() != 0)
            {
                for(int i = 0; i < 16; i++)
                {
                    n1[i] = intList[i];
                    if(intList.size() > 16)
                        n2[i] = intList[i+16];
                    String = QString::number(n1[i], 10);//以10进制
                    m_saveFile->write(String.toUtf8());
                    if(i == 15 )
                    {
                        m_saveFile->write("\n");
                    }
                    else
                    {
                        m_saveFile->write("\t");
                    }
                }
                for(int i = 0; i < 16; i++)
                {
                    intList.removeFirst();
                }
                if(intList.size() != 0)
                    for(int i = 1; i <= 10; i++)
                    {
                        for(int j = 0; j < 16; j++)
                        {
                            if(n1[j] < n2[j])
                            {
                                n3 = n1[j]+(((n2[j] - n1[j])/10)*i);
                            }
                            else
                            {
                                n3 = n1[j] - (((n1[j] - n2[j])/10)*i);
                            }
                            String = QString::number(n3, 10);//以10进制
                            m_saveFile->write(String.toUtf8());

                            if(j == 15 )
                            {
                                m_saveFile->write("\n");
                            }
                            else
                            {
                                m_saveFile->write("\t");
                            }
                        }
                    }
            }
        }
        m_saveFile->close();
        ui->pushButton_recording->setText("录制");
        ui->pushButton_play->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_auto->setEnabled(false);
    }
}

void Widget::on_pushButton_auto_clicked()
{
    if(ui->pushButton_auto->text() == "自动")
        {
    //        m_timer = new QTimer;//定时器对象
    //        m_timer->setSingleShot(false);//设置定时器是否为单次触发。默认为 false 多次触发
    //        connect(m_timer,SIGNAL(timeout()),this,SLOT(TimerTimeOut()));
    //        m_timer->start(500);
            ui->pushButton_2->setEnabled(false);
            ui->pushButton_recording->setEnabled(false);
            ui->pushButton_auto->setText("停止");

            while(1)
            {
                unsigned char Sum = 0;

                unsigned char R_pos_buff[] = {0xff,0xff,0x00,0x04,0x02,0x24,0x02,0x00};

                for(int ID = 1; ID <= 1; ID++)
                {
                    Sum = 0;
                    R_pos_buff[2] = (unsigned char)ID;

                    for(int i = 2; i < 7; i++)
                    {
                        Sum += R_pos_buff[i];
                    }
                    Sum = (unsigned char)~Sum;
                    R_pos_buff[7] = Sum;

                    QByteArray array;
                    array.resize(8);
                    for(int i = 0; i < 8; i++)
                    {
                        array[i] = R_pos_buff[i];
                    }
                    m_serial->SendData(array);
                    QTime dieTime = QTime::currentTime().addMSecs(ui->spinBox->value());
                    while( QTime::currentTime() < dieTime )
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                }
                if(ui->pushButton_auto->text() == "自动")
                    break;
            }
        }
        else
        {
    //        m_timer->stop();
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_recording->setEnabled(true);
            ui->pushButton_auto->setText("自动");
    //        delete m_timer;
        }
}

void Widget::TimerTimeOut()
{
    emit on_pushButton_2_clicked();
    m_timer->start(1000);
}
