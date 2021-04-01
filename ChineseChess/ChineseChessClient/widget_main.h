#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include <QWidget>
#include <QDebug>
#include <tcpclient.h>
#include <QPainter>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>


#include "item.h"

#define cout qDebug() << "[" <<__FILE__ <<":"<<__LINE__ <<"]"

typedef struct
{
    QPoint currentItemPt;
    QPoint nextItemPt;
    bool isBeEated;
    Item BeEatedItem;
}ItemPath;


namespace Ui {
class Widget_main;
}

class Widget_main : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

public:
    explicit Widget_main(TcpClient * tcp,QWidget *parent = 0);
    ~Widget_main();
public:
    void SendData(QPoint currentItemPt, QPoint nextItemPt);

private slots:
    void ReadData();
    void PushButtonStart_Clicked();
    void PushButtonUndo_Clicked();
    void TimerTimeOut();//定时器

public:
    void GameInit();
    void ItemInit();
    void GameOver(Item item);//游戏结束处理
    void DrawItem(Item item);
    void DrawMovePath(void);//画可移动路径
    void RecordItemPath(bool,QPoint,Item);//记录一局棋子的移动路径
    bool FindItemAtPoint(QPoint pt,Item &item);//寻找点击位置有没有棋子
    bool DeleteItemAtPoint(Item &item);//吃掉棋子
    bool MoveItemAtPoint(QPoint & pt);//移动棋子
    void SetItemShow(Item &item,bool show);//设置棋子显示
    void GetMoveArea(Item &item,QVector<QPoint> &moveArea);//获得选中棋子的可移动路径

    void GetMoveArea_SHUAI(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_SHI(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_XIANG(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_JU(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_MA(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_PAO(Item &item,QVector<QPoint> &moveArea);
    void GetMoveArea_BING(Item &item,QVector<QPoint> &moveArea);

private:
    Ui::Widget_main *ui;
    QPushButton *PushButtonStart;
    QPushButton *PushButtonUndo;

    ITEM_COLOR m_OwnColor;//我方颜色
    ITEM_COLOR m_OpponentColor;//敌方颜色

    QVector<Item> m_items; //所有棋子
    QVector<QPoint> m_MobilePath;//可移动路径
    QVector<ItemPath> m_itemPath;//记录下棋过程
    Item m_SelectedItem;//当前选择的棋子
    bool m_bExistSelectedItem;	//是否已存在选中的棋子
    bool m_IsOwnTurn;//是否轮到我方下
    bool m_GameOver;//游戏结束标志


    QPainter p;

    QPixmap m_pixChessBoard;
    QPixmap m_pixItem;
    int ItemH;
    int ItemW;

    TcpClient *m_tcpClient;

    QTimer * m_timer;
};

#endif // WIDGET_MAIN_H
