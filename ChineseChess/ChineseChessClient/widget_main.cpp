#include "widget_main.h"
#include "ui_widget_main.h"

#define Window_WIDTH    512
#define Window_HEIGHT   650

#define RECT_WIDTH		55
#define RECT_HEIGHT		56

#define START_X	(35-RECT_WIDTH/2)           //棋盘左上定点像素值（35，45），棋盘的格子大小（96，96）
#define START_Y	(46-RECT_HEIGHT/2)



Widget_main::Widget_main(TcpClient *tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_main)
{
    ui->setupUi(this);
    m_tcpClient = tcp;
    connect(m_tcpClient,SIGNAL(ReadDataReady()),this,SLOT(ReadData()));

    PushButtonStart = new QPushButton(this);
    PushButtonStart->setText("准备");
    PushButtonStart->setGeometry(Window_WIDTH/2-35,600,70,30);
    PushButtonStart->show();
//    PushButtonStart->setStyleSheet("border-image: url(:/img/img/background.png);");
    PushButtonStart->setFocusPolicy(Qt::NoFocus);
    connect(PushButtonStart,SIGNAL(clicked()),this,SLOT(PushButtonStart_Clicked()));

    PushButtonUndo = new QPushButton(this);
    PushButtonUndo->setText("悔棋");
    PushButtonUndo->setGeometry((Window_WIDTH/2)+(Window_WIDTH/2/2)-35,600,70,30);
    PushButtonUndo->show();
    PushButtonUndo->setFocusPolicy(Qt::NoFocus);
    connect(PushButtonUndo,SIGNAL(clicked()),this,SLOT(PushButtonUndo_Clicked()));

    this->setWindowTitle("中国象棋");
    this->setFixedSize(QSize(Window_WIDTH,Window_HEIGHT));

    m_pixChessBoard = QPixmap(":/img/img/ChessBoard.png");
    m_pixItem = QPixmap(":/img/img/items.png");

    ItemH = m_pixItem.height()/7;
    ItemW = m_pixItem.width()/2;

    m_timer = new QTimer;//定时器对象
    m_timer->setSingleShot(false);//设置定时器是否为单次触发。默认为 false 多次触发
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));//定时器触发信号槽
}


void Widget_main::paintEvent(QPaintEvent *e)
{
    //画背景、画棋盘、画棋子、画可移动路径
    p.begin(this);
    p.drawPixmap(0,0,Window_WIDTH,Window_HEIGHT,QPixmap(":/img/img/background.png"));
    p.drawPixmap(0,0,512,600,m_pixChessBoard);
    p.end();

    for(int i = 0; i < m_items.size(); i++)
        if(m_items[i].m_show)
            DrawItem(m_items[i]);

    DrawMovePath();
}
void Widget_main::mousePressEvent(QMouseEvent * e)
{
    if(!m_IsOwnTurn)
        return;
    if(m_GameOver)
        return;
    if(e->x() < 7 || e->x() > 503 ||e->y() < 17 || e->y() > 579 )
        return;

    cout << e->pos();

    //获取点击的棋子对应坐标
    QPoint pt;
    pt.setX((e->x()- START_X) / RECT_WIDTH);
    pt.setY((e->y()- START_Y) / RECT_HEIGHT);

    //当前是否有选中的棋子
    if(m_bExistSelectedItem)
    {
        Item clickItem;
        QVector<QPoint> moveArea;
        GetMoveArea(m_SelectedItem,moveArea);

        //点击处是否有棋子
        if(FindItemAtPoint(pt,clickItem))
        {
            if(clickItem.m_point == m_SelectedItem.m_point)//相同的棋子
            {
                m_MobilePath.clear();
                SetItemShow(m_SelectedItem,true);
                m_bExistSelectedItem = false;
                m_SelectedItem.m_point=QPoint(-1,-1);
                m_timer->stop();
            }
            else if (clickItem.m_color == m_SelectedItem.m_color)//同颜色的棋子
            {
                GetMoveArea(clickItem,m_MobilePath);
                SetItemShow(m_SelectedItem,true);
                SetItemShow(clickItem,false);
                m_SelectedItem = clickItem;
                m_timer->start(500);
            }
            else
            {
                for(int i =0; i < moveArea.size(); i++)
                    if(moveArea[i] == clickItem.m_point)
                    {
                        m_MobilePath.clear();

                        //吃棋子操作
                        DeleteItemAtPoint(clickItem);
                        //记录
                        RecordItemPath(true,pt,clickItem);
                        //移动棋子
                        MoveItemAtPoint(pt);
                        m_timer->stop();
                    }
            }
        }
        else
            for(int i =0; i < moveArea.size(); i++)
                if(moveArea[i] == pt)
                {
                    m_MobilePath.clear();
                    //记录
                    RecordItemPath(false,pt,clickItem);
                    //移动棋子
                    MoveItemAtPoint(pt);
                    m_timer->stop();
                }


    }
    else
    {
        Item clickItem;
        //点击处有棋子
        if(FindItemAtPoint(pt,clickItem))
        {
            //点击的棋子是否为当前方
            if(clickItem.m_color == m_OwnColor)
            {
                GetMoveArea(clickItem,m_MobilePath);
                m_bExistSelectedItem = true;
                m_SelectedItem = clickItem;
                SetItemShow(m_SelectedItem,false);
                m_timer->start(500);//启动或重启定时器, 并设置定时器时间：毫秒
            }
        }
    }

    update();
}

void Widget_main::SendData(QPoint currentItemPt, QPoint nextItemPt)
{
    QString str = QString("MV=%1,%2,%3,%4").arg(currentItemPt.x()).arg(currentItemPt.y()).arg(nextItemPt.x()).arg(nextItemPt.y());
    QByteArray data=  str.toLocal8Bit();
    m_tcpClient->SendData(data);
}

void Widget_main::ReadData()
{
    QString data = QString(m_tcpClient->GetReadBuf());
    cout << data;

    if(data.contains("PC"))
    {
        data = data.remove("PC=");
        if(data == "RED")
        {
            m_IsOwnTurn = true;
            m_OwnColor = COLOR_RED;
            m_OpponentColor = COLOR_BLACK;
        }
        else if (data == "BLACK")
        {
            m_IsOwnTurn = false;
            m_OwnColor = COLOR_BLACK;
            m_OpponentColor = COLOR_RED;
        }
    }
    else if(data.contains("Start"))
    {
        GameInit();
        update();
    }
    else if (data.contains("MV"))
    {
        data = data.remove("MV=");
        if(data.count(QRegExp(","))!=3)
        {
            return;
        }
        QStringList dataList = data.split(",");
        QString currentItemPtX = dataList[0];
        QString currentItemPtY = dataList[1];
        QString nextItemPtX = dataList[2];
        QString nextItemPtY = dataList[3];
        cout << dataList[0];
        cout << dataList[1];
        cout << dataList[2];
        cout << dataList[3];
        QPoint currentItemPt;
        QPoint nextItemPt;
        bool ok;
        currentItemPt.setX(8-currentItemPtX.toInt(&ok,10));
        currentItemPt.setY(9-currentItemPtY.toInt(&ok,10));
        nextItemPt.setX(8-nextItemPtX.toInt(&ok,10));
        nextItemPt.setY(9-nextItemPtY.toInt(&ok,10));

        Item clickItem;
        if(FindItemAtPoint(nextItemPt,clickItem))
        {
            DeleteItemAtPoint(clickItem);

            m_SelectedItem.m_point = currentItemPt;
            RecordItemPath(true,nextItemPt,clickItem);

            for(int i = 0; i < m_items.size(); i++)
            {
                if(m_items[i].m_point == currentItemPt)
                {
                    m_items[i].m_point.setX(nextItemPt.x());
                    m_items[i].m_point.setY(nextItemPt.y());
                    m_items[i].m_show = true;
                    m_bExistSelectedItem = false;

                    //交换下棋者

                    m_IsOwnTurn = true;
                }
            }
        }
        else
        {
            m_SelectedItem.m_point = currentItemPt;
            RecordItemPath(false,nextItemPt,clickItem);
            for(int i = 0; i < m_items.size(); i++)
            {
                if(m_items[i].m_point == currentItemPt)
                {
                    m_items[i].m_point.setX(nextItemPt.x());
                    m_items[i].m_point.setY(nextItemPt.y());
                    m_items[i].m_show = true;
                    m_bExistSelectedItem = false;

                    //交换下棋者

                    m_IsOwnTurn = true;
                }
            }
        }
    }
}

void Widget_main::PushButtonStart_Clicked()
{
    m_tcpClient->SendData("Ready");
    PushButtonStart->setEnabled(false);
}

void Widget_main::PushButtonUndo_Clicked()
{

}

void Widget_main::TimerTimeOut()
{
    //用于选中棋子的闪烁
    for(int i = 0; i < m_items.size(); i++)
    {
        if(m_items[i].m_point == m_SelectedItem.m_point)
        {
            m_items[i].m_show = !m_items[i].m_show;
            break;
        }
    }
    update();
}

void Widget_main::GameInit()
{
    ItemInit();
    m_SelectedItem.m_point = QPoint(0,0);
    m_bExistSelectedItem = false;
    m_GameOver = false;
}

void Widget_main::ItemInit()
{
    m_items.clear();

    //红
    Item item1(ITEM_SHUAI,m_OwnColor,QPoint(4,9));
    Item item2(ITEM_SHI,m_OwnColor,QPoint(3,9));
    Item item3(ITEM_SHI,m_OwnColor,QPoint(5,9));
    Item item4(ITEM_XIANG,m_OwnColor,QPoint(2,9));
    Item item5(ITEM_XIANG,m_OwnColor,QPoint(6,9));
    Item item6(ITEM_MA,m_OwnColor,QPoint(1,9));
    Item item7(ITEM_MA,m_OwnColor,QPoint(7,9));
    Item item8(ITEM_JU,m_OwnColor,QPoint(0,9));
    Item item9(ITEM_JU,m_OwnColor,QPoint(8,9));
    Item item10(ITEM_PAO,m_OwnColor,QPoint(1,7));
    Item item11(ITEM_PAO,m_OwnColor,QPoint(7,7));
    Item item12(ITEM_BING,m_OwnColor,QPoint(0,6));
    Item item13(ITEM_BING,m_OwnColor,QPoint(2,6));
    Item item14(ITEM_BING,m_OwnColor,QPoint(4,6));
    Item item15(ITEM_BING,m_OwnColor,QPoint(6,6));
    Item item16(ITEM_BING,m_OwnColor,QPoint(8,6));

    //黑
    Item item_1(ITEM_SHUAI,m_OpponentColor,QPoint(4,0));
    Item item_2(ITEM_SHI,m_OpponentColor,QPoint(3,0));
    Item item_3(ITEM_SHI,m_OpponentColor,QPoint(5,0));
    Item item_4(ITEM_XIANG,m_OpponentColor,QPoint(2,0));
    Item item_5(ITEM_XIANG,m_OpponentColor,QPoint(6,0));
    Item item_6(ITEM_MA,m_OpponentColor,QPoint(1,0));
    Item item_7(ITEM_MA,m_OpponentColor,QPoint(7,0));
    Item item_8(ITEM_JU,m_OpponentColor,QPoint(0,0));
    Item item_9(ITEM_JU,m_OpponentColor,QPoint(8,0));
    Item item_10(ITEM_PAO,m_OpponentColor,QPoint(1,2));
    Item item_11(ITEM_PAO,m_OpponentColor,QPoint(7,2));
    Item item_12(ITEM_BING,m_OpponentColor,QPoint(0,3));
    Item item_13(ITEM_BING,m_OpponentColor,QPoint(2,3));
    Item item_14(ITEM_BING,m_OpponentColor,QPoint(4,3));
    Item item_15(ITEM_BING,m_OpponentColor,QPoint(6,3));
    Item item_16(ITEM_BING,m_OpponentColor,QPoint(8,3));

    m_items.push_back(item1);
    m_items.push_back(item2);
    m_items.push_back(item3);
    m_items.push_back(item4);
    m_items.push_back(item5);
    m_items.push_back(item6);
    m_items.push_back(item7);
    m_items.push_back(item8);
    m_items.push_back(item9);
    m_items.push_back(item10);
    m_items.push_back(item11);
    m_items.push_back(item12);
    m_items.push_back(item13);
    m_items.push_back(item14);
    m_items.push_back(item15);
    m_items.push_back(item16);

    m_items.push_back(item_1);
    m_items.push_back(item_2);
    m_items.push_back(item_3);
    m_items.push_back(item_4);
    m_items.push_back(item_5);
    m_items.push_back(item_6);
    m_items.push_back(item_7);
    m_items.push_back(item_8);
    m_items.push_back(item_9);
    m_items.push_back(item_10);
    m_items.push_back(item_11);
    m_items.push_back(item_12);
    m_items.push_back(item_13);
    m_items.push_back(item_14);
    m_items.push_back(item_15);
    m_items.push_back(item_16);
}

void Widget_main::GameOver(Item item)
{
    m_GameOver = true;
    if(item.m_color == COLOR_RED)
        QMessageBox::information(this,"游戏结束","黑方胜利");
    else
        QMessageBox::information(this,"游戏结束","红方胜利");
    PushButtonStart->setEnabled(true);
    PushButtonUndo->setEnabled(false);
}

void Widget_main::DrawItem(Item item)
{
    p.begin(this);
    QRect rcSrc(item.m_color*ItemW,item.m_type*ItemH,ItemW,ItemH);

    QRect rcTarget(	START_X + item.m_point.x()*RECT_WIDTH,
                    START_Y + item.m_point.y()*RECT_HEIGHT,
                    RECT_WIDTH,RECT_HEIGHT);

    p.drawPixmap(rcTarget,m_pixItem,rcSrc);
    p.end();
}

void Widget_main::DrawMovePath(void)
{
    p.begin(this);
    for(int i = 0; i < m_MobilePath.size(); i++)
    {
        QBrush Brush;
        Brush.setColor(Qt::red);
        Brush.setStyle(Qt::SolidPattern);
        p.setPen(Qt::red);

        p.setBrush(Brush);
        p.drawEllipse(m_MobilePath[i].x()*55 + 30,m_MobilePath[i].y()*56 + 43,10,10);
    }
    p.end();
}

void Widget_main::RecordItemPath(bool isBeEated, QPoint pt, Item clickItem)
{
    //记录当前选中棋子坐标，要移动的坐标，棋子被吃标志位，被吃掉的棋子
    ItemPath itemPath;
    itemPath.currentItemPt = m_SelectedItem.m_point;
    itemPath.nextItemPt = pt;
    itemPath.isBeEated = isBeEated;
    itemPath.BeEatedItem = clickItem;
    m_itemPath.push_back(itemPath);
}

bool Widget_main::FindItemAtPoint(QPoint pt,Item &item)
{
    for(int i = 0; i < m_items.size(); i++)
    {
        if(m_items[i].m_point == pt)
        {
            item = m_items[i];
            return true;
        }
    }
    return false;
}

bool Widget_main::DeleteItemAtPoint(Item &item)
{
    for(int i = 0; i < m_items.size(); i++)
    {
        if(m_items[i].m_point == item.m_point)
        {
            m_items.erase(m_items.begin()+i);
            if(item.m_type == ITEM_SHUAI)
            {
                update();
                GameOver(item);
            }
            return true;
        }
    }
    return false;
}

bool Widget_main::MoveItemAtPoint(QPoint & pt)
{
    for(int i = 0; i < m_items.size(); i++)
    {
        if(m_items[i].m_point == m_SelectedItem.m_point)
        {
            m_items[i].m_point.setX(pt.x());
            m_items[i].m_point.setY(pt.y());
            m_items[i].m_show = true;
            m_bExistSelectedItem = false;

            SendData(m_SelectedItem.m_point,pt);
            //交换下棋者

            m_IsOwnTurn = false;


            return true;
        }
    }
    return false;
}

void Widget_main::SetItemShow(Item &item,bool show)
{
    for(int i = 0; i < m_items.size(); i++)
        if(item.m_point == m_items[i].m_point)
            m_items[i].m_show = show;
}

void Widget_main::GetMoveArea(Item &item,QVector<QPoint> &moveArea)
{
    moveArea.clear();
    switch(item.m_type)
    {
        case ITEM_SHUAI: GetMoveArea_SHUAI(item,moveArea);break;
        case ITEM_SHI: GetMoveArea_SHI(item,moveArea);break;
        case ITEM_XIANG: GetMoveArea_XIANG(item,moveArea);break;
        case ITEM_JU: GetMoveArea_JU(item,moveArea);break;
        case ITEM_MA: GetMoveArea_MA(item,moveArea);break;
        case ITEM_PAO: GetMoveArea_PAO(item,moveArea);break;
        case ITEM_BING: GetMoveArea_BING(item,moveArea);break;
        default:break;
    }
}

void Widget_main::GetMoveArea_SHUAI(Item &item,QVector<QPoint> &moveArea)
{
    //思路：先把帅四个可移动点列出来，再根据当前位置进行剔除，
    //     剔除条件为 1.移动点在指定范围外
    //              2.移动点有己方棋子
    //     若帅为红方，帅上方第一个棋子为敌帅，则加入可移动点
    //     若帅为黑方，帅下方第一个棋子为敌帅，则加入可移动点
    QVector<QPoint> directions;
    directions.push_back(QPoint(1,0));
    directions.push_back(QPoint(-1,0));
    directions.push_back(QPoint(0,-1));
    directions.push_back(QPoint(0,1));

    //己方
    if(item.m_color == m_OwnColor)
    {
        QPoint newPt;
        Item itemTemp;
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 3 || newPt.x() > 5 || newPt.y() < 7 || newPt.y() > 9)
                continue;
            if(!FindItemAtPoint(newPt,itemTemp))
                moveArea.push_back(newPt);
            else
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(newPt);
        }
        for(int i = item.m_point.y()-1; i >= 0; i--)
        {
            newPt = QPoint(item.m_point.x(),i);
            if(FindItemAtPoint(newPt,itemTemp))
            {
                if(itemTemp.m_type == ITEM_SHUAI)
                   moveArea.push_back(itemTemp.m_point);
                return;
            }
        }
    }
    else
    {
        QPoint newPt;
        Item itemTemp;
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 3 || newPt.x() > 5 || newPt.y() > 2 || newPt.y() < 0)
                continue;
            if(!FindItemAtPoint(newPt,itemTemp))
                moveArea.push_back(newPt);
            else
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(newPt);
        }
        for(int i = item.m_point.y()+1; i <= 9; i++)
        {
            newPt = QPoint(item.m_point.x(),i);
            if(FindItemAtPoint(newPt,itemTemp))
            {
                if(itemTemp.m_type == ITEM_SHUAI)
                   moveArea.push_back(itemTemp.m_point);
                return;
            }
        }
    }

}

void Widget_main::GetMoveArea_SHI(Item &item,QVector<QPoint> &moveArea)
{
    //思路：先把士四个可移动点列出来，再根据当前位置进行剔除，
    //     剔除条件为 1.移动点在指定范围外
    //              2.移动点有己方棋子
    QVector<QPoint> directions;
    directions.push_back(QPoint(-1,-1));
    directions.push_back(QPoint(1,-1));
    directions.push_back(QPoint(1,1));
    directions.push_back(QPoint(-1,1));

    QPoint newPt;
    Item itemTemp;

    //己方
    if(item.m_color == m_OwnColor)
    {
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 3 || newPt.x() > 5 || newPt.y() < 7 || newPt.y() > 9)
                continue;
            if(!FindItemAtPoint(newPt,itemTemp))
            {
                moveArea.push_back(newPt);
            }
            else
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(newPt);
            }
        }
    }
    else
    {
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 3 || newPt.x() > 5 || newPt.y() < 0 || newPt.y() > 2)
                continue;
            if(!FindItemAtPoint(newPt,itemTemp))
            {
                moveArea.push_back(newPt);
            }
            else
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(newPt);
            }
        }
    }
}

void Widget_main::GetMoveArea_XIANG(Item &item,QVector<QPoint> &moveArea)
{
    //思路：把象四个可移动点列出来，把挡住象移动的四个点列出来
    //     剔除条件为 1.移动点在指定范围外
    //              2.移动点有己方棋子
    //              3.挡住象移动的点存在棋子
    QVector<QPoint> directions;
    directions.push_back(QPoint(2,2));
    directions.push_back(QPoint(-2,-2));
    directions.push_back(QPoint(2,-2));
    directions.push_back(QPoint(-2,2));
    QVector<QPoint> impede;
    impede.push_back(item.m_point + QPoint(1,1));
    impede.push_back(item.m_point + QPoint(-1,-1));
    impede.push_back(item.m_point + QPoint(1,-1));
    impede.push_back(item.m_point + QPoint(-1,1));

    QPoint newPt;
    Item itemTemp;

    //己方
    if(item.m_color == m_OwnColor)
    {
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 0 || newPt.x() > 8 || newPt.y() < 5 || newPt.y() > 9)
                continue;
            if(!FindItemAtPoint(impede[i],itemTemp))
            {
                if(!FindItemAtPoint(newPt,itemTemp))
                    moveArea.push_back(newPt);
                else
                {
                    if(itemTemp.m_color != item.m_color)
                        moveArea.push_back(newPt);
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < directions.size(); i++)
        {
            newPt = item.m_point + directions[i];
            if(newPt.x() < 0 || newPt.x() > 8 || newPt.y() < 0 || newPt.y() > 4)
                continue;
            if(!FindItemAtPoint(impede[i],itemTemp))
            {
                if(!FindItemAtPoint(newPt,itemTemp))
                    moveArea.push_back(newPt);
                else
                {
                    if(itemTemp.m_color != item.m_color)
                        moveArea.push_back(newPt);
                }
            }
        }
    }
}

void Widget_main::GetMoveArea_JU(Item &item,QVector<QPoint> &moveArea)
{
    //思路：把车按上下左右的顺序依次从棋子到棋盘外的点进行判断
    //添加：可移动点没旗子、有棋子且为敌方

    QPoint pt;
    Item itemTemp;

    //上
    pt.setX(item.m_point.x());
    for(int i = item.m_point.y()-1; i >= 0; i--)
    {
        pt.setY(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(itemTemp.m_color != item.m_color)
                moveArea.push_back(pt);
            break;
        }
        else
        {
            moveArea.push_back(pt);
        }
    }

    //下
    for(int i = item.m_point.y()+1; i <= 9; i++)
    {
        pt.setY(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(itemTemp.m_color != item.m_color)
                moveArea.push_back(pt);
            break;
        }
        else
        {
            moveArea.push_back(pt);
        }
    }

    //左
    pt.setY(item.m_point.y());
    for(int i = item.m_point.x()-1; i >= 0; i--)
    {
        pt.setX(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(itemTemp.m_color != item.m_color)
                moveArea.push_back(pt);
            break;
        }
        else
        {
            moveArea.push_back(pt);
        }
    }

    //右
    for(int i = item.m_point.x()+1; i <= 8; i++)
    {
        pt.setX(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(itemTemp.m_color != item.m_color)
                moveArea.push_back(pt);
            break;
        }
        else
        {
            moveArea.push_back(pt);
        }
    }
}

void Widget_main::GetMoveArea_MA(Item &item,QVector<QPoint> &moveArea)
{
    //思路：列出八个可移动点及阻挡马移动的四个点，先判断阻碍点是否有棋子，在判断可以点是否符合条件
    //添加：可移动点无棋子、有棋子且为敌方
    QVector<QPoint> directions;
    directions.push_back(QPoint(-1,-2));
    directions.push_back(QPoint(1,-2));
    directions.push_back(QPoint(2,-1));
    directions.push_back(QPoint(2,1));
    directions.push_back(QPoint(1,2));
    directions.push_back(QPoint(-1,2));
    directions.push_back(QPoint(-2,1));
    directions.push_back(QPoint(-2,-1));
    QVector<QPoint> impede;
    impede.push_back(item.m_point + QPoint(0,-1));
    impede.push_back(item.m_point + QPoint(1,0));
    impede.push_back(item.m_point + QPoint(0,1));
    impede.push_back(item.m_point + QPoint(-1,0));

    QPoint newPt1,newPt2;
    Item itemTemp;
    for(int i = 0; i < impede.size(); i++)
    {
        if(impede[i].x() < 0 ||impede[i].x() > 8 || impede[i].y() < 0 ||impede[i].y() > 9)
            continue;
        newPt1 = item.m_point + directions[2*i];
        newPt2 = item.m_point + directions[i*2+1];
        if(!FindItemAtPoint(impede[i],itemTemp))
        {
            if(!(newPt1.x() < 0 ||newPt1.x() > 8 || newPt1.y() < 0 ||newPt1.y() > 9))
            {
                if(!FindItemAtPoint(newPt1,itemTemp))
                    moveArea.push_back(newPt1);
                else
                {
                    if(itemTemp.m_color != item.m_color)
                        moveArea.push_back(newPt1);
                }
            }
            if(!(newPt2.x() < 0 ||newPt2.x() > 8 || newPt2.y() < 0 ||newPt2.y() > 9))
            {
                if(!FindItemAtPoint(newPt2,itemTemp))
                    moveArea.push_back(newPt2);
                else
                {
                    if(itemTemp.m_color != item.m_color)
                        moveArea.push_back(newPt2);
                }
            }
        }
    }
}

void Widget_main::GetMoveArea_PAO(Item &item,QVector<QPoint> &moveArea)
{
    //思路：把炮按上下左右的顺序依次从棋子到棋盘外的点进行判断，遇到第一个棋子跳过，遇到第二个棋子进行判断
    //添加：遇到第一个棋子前可移动点没旗子、第二个棋子且为敌方
    Item itemTemp;
    QPoint pt;
    bool hasPAOJIA;

    //上
    hasPAOJIA = false;
    pt.setX(item.m_point.x());
    for(int i = item.m_point.y()-1; i >= 0; i--)
    {
        pt.setY(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(hasPAOJIA)
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(pt);
                break;
            }
            else
                hasPAOJIA = true;
        }
        else
        {
            if(hasPAOJIA == false)
                moveArea.push_back(pt);
        }
    }

    //下
    hasPAOJIA = false;
    for(int i = item.m_point.y()+1; i <= 9; i++)
    {
        pt.setY(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(hasPAOJIA)
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(pt);
                break;
            }
            else
                hasPAOJIA = true;
        }
        else
        {
            if(hasPAOJIA == false)
                moveArea.push_back(pt);
        }
    }

    //左
    hasPAOJIA = false;
    pt.setY(item.m_point.y());
    for(int i = item.m_point.x()-1; i >= 0; i--)
    {
        pt.setX(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(hasPAOJIA)
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(pt);
                break;
            }
            else
                hasPAOJIA = true;
        }
        else
        {
            if(hasPAOJIA == false)
                moveArea.push_back(pt);
        }
    }

    //右
    hasPAOJIA = false;
    for(int i = item.m_point.x()+1; i <= 8; i++)
    {
        pt.setX(i);
        if(FindItemAtPoint(pt,itemTemp))
        {
            if(hasPAOJIA)
            {
                if(itemTemp.m_color != item.m_color)
                    moveArea.push_back(pt);
                break;
            }
            else
                hasPAOJIA = true;
        }
        else
        {
            if(hasPAOJIA == false)
                moveArea.push_back(pt);
        }
    }

}

void Widget_main::GetMoveArea_BING(Item &item,QVector<QPoint> &moveArea)
{
    //思路：兵过河前可移动点为一个，过河后可移动点为三个，根据棋子当前位置进行添加即可
    QVector<QPoint> directions;

    //己方
    if(item.m_color == m_OwnColor)
    {
        directions.push_back(QPoint(0,-1));
        if(item.m_point.y() <= 4)
        {
            directions.push_back(QPoint(-1,0));
            directions.push_back(QPoint(1,0));
        }
    }
    else
    {
        directions.push_back(QPoint(0,1));
        if(item.m_point.y() >= 5)
        {
            directions.push_back(QPoint(-1,0));
            directions.push_back(QPoint(1,0));
        }
    }

    QPoint newPt;
    for(int i = 0; i < directions.size(); i++)
    {
        newPt = item.m_point + directions[i];

        if((newPt.x() < 0) || (newPt.x() > 8) || (newPt.y() < 0) ||(newPt.y() > 9))
            continue;
        moveArea.push_back(newPt);
    }
}

Widget_main::~Widget_main()
{
    delete ui;
}

