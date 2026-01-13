/*****************************************
 *  File_name : ArmorList.cpp
 *  다양한 종류의 Armor 구현
 ******************************************/
#include "ArmorList.h"
#include "ItemID.h"
#include <iostream>

NormalArmor::NormalArmor() : Armor(ItemDatabase::get(ItemID::NormalArmor))
{
    base_bonus.hp = 10;
    base_bonus.defend = 4;
}
GoblinArmor::GoblinArmor() : Armor(ItemDatabase::get(ItemID::GoblinArmor))
{
    base_bonus.hp = 25;
    base_bonus.defend = 7;
    base_bonus.vigor = 5;
}

DragonArmor::DragonArmor() : Armor(ItemDatabase::get(ItemID::DragonArmor))
{
    base_bonus.hp = 50;
    base_bonus.defend = 15;
    base_bonus.vigor = 10;
    base_bonus.cri = 5;
}