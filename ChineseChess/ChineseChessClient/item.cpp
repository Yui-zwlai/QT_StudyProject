#include "item.h"

Item::Item()
{

}

Item::Item(ITEM_TYPE t,ITEM_COLOR c,QPoint pt)
{
    m_type = t;
    m_color = c;
    m_point = pt;
    m_show = true;
}

Item::~Item(void)
{

}
