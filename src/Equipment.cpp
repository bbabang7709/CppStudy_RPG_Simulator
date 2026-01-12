/*****************************************
 *  File_name : Equipment.cpp
 *  착용 가능한 아이템 클래스 정의
 ******************************************/
#include "Equipment.h"


Equipment::Equipment(const ItemData &data) : Item(data) {}
int Equipment::get_enhance_level() const { return enhance_level; }
bool Equipment::can_enhance() const
{
    if (enhance_level < MAX_ENHANCE) 
        return true;
    return false;
}
void Equipment::enhance()
{
    if (can_enhance())
        enhance_level++;
}

bool Equipment::is_enhanceable() const { return true; }
void Equipment::set_enhance_level(int e_level)
{
    enhance_level = e_level;
}