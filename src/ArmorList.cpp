/*****************************************
 *  File_name : ArmorList.cpp
 *  다양한 종류의 Armor 구현
 ******************************************/
#include "ArmorList.h"
#include "ItemID.h"
#include <iostream>

NormalArmor::NormalArmor(const std::string name, ItemType type, int price) : Armor(name, type, price)
{
    set_id(ItemID::NormalArmor);
    set_armor_defend(4);
}
GoblinArmor::GoblinArmor(const std::string name, ItemType type, int price) : Armor(name, type, price)
{
    set_id(ItemID::GoblinArmor);
    set_armor_hp(10);
    set_armor_defend(7);
    set_armor_vigor(5);
}

DragonArmor::DragonArmor(const std::string name, ItemType type, int price) : Armor(name, type, price)
{
    set_id(ItemID::DragonArmor);
    set_armor_hp(50);
    set_armor_defend(15);
    set_armor_vigor(10);
}