/*****************************************
 *  File_name : MeterialList.cpp
 *  다양한 재료 아이템 구현
 ******************************************/
#include "MeterialList.h"

ReinforceStone::ReinforceStone(std::string name, ItemType type, int price) : Meterial(name, type, price)
{
    set_id(ItemID::ReinforceStone);
}

DragonScale::DragonScale(std::string name, ItemType type, int price) : Meterial(name, type, price) 
{
    set_id(ItemID::DragonScale);
}

SoulStone_Dragon::SoulStone_Dragon(std::string name, ItemType type, int price) : Meterial(name, type, price) 
{
    set_id(ItemID::SoulStone_Dragon);
}
