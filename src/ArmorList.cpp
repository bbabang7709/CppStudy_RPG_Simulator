/*****************************************
 *  File_name : ArmorList.cpp
 *  다양한 종류의 Armor 구현
 ******************************************/
#include "ArmorList.h"
#include "ItemID.h"
#include <iostream>

NormalArmor::NormalArmor(const std::string name, ItemType type, int price) : Armor(name, type, price)
{
    set_id(ItemId::NormalArmor);
    set_armor_defend(4);
}
GoblinArmor::GoblinArmor(const std::string name, ItemType type, int price) : Armor(name, type, price)
{
    set_id(ItemId::GoblinArmor);
    set_armor_hp(10);
    set_armor_defend(7);
    set_armor_vigor(5);
}