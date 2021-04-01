#ifndef ITEM_H
#define ITEM_H



#include <QPoint>

enum ITEM_TYPE{
    ITEM_SHUAI = 0,	//帅
    ITEM_SHI,		//士
    ITEM_XIANG,		//象
    ITEM_JU,		//车
    ITEM_MA,		//马
    ITEM_PAO,		//炮
    ITEM_BING		//兵
};

enum ITEM_COLOR{
    COLOR_RED = 0,	//红方
    COLOR_BLACK     //黑方
};


class Item
{
public:
    Item();
    Item(ITEM_TYPE t,ITEM_COLOR c,QPoint pt);
    ~Item(void);


    ITEM_TYPE m_type;
    ITEM_COLOR m_color;
    QPoint m_point;
    bool m_show;

};

#endif // ITEM_H
