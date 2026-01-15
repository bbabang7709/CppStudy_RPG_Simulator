/*****************************************
 *  File_name : ArmorList.cpp
 *  다양한 종류의 Armor 구현
 ******************************************/
#include "ArmorList.h"
#include "ItemID.h"
#include <iostream>

NormalArmor::NormalArmor() : Armor(ItemDatabase::get(ItemID::NormalArmor))
{
    flat_stats.hp = 10;
    flat_stats.defend = 4;
}

GoblinArmor::GoblinArmor() : Armor(ItemDatabase::get(ItemID::GoblinArmor))
{
    flat_stats.hp = 30;
    flat_stats.defend = 10;
    flat_stats.vigor = 5;
}

DragonArmor::DragonArmor() : Armor(ItemDatabase::get(ItemID::DragonArmor))
{
    flat_stats.hp = 50;
    flat_stats.defend = 15;
    flat_stats.vigor = 10;
    flat_stats.cri = 5;
}