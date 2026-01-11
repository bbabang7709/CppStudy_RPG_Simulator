/*****************************************
 *  File_name : NormalMonsterList.cpp
 *  일반 몬스터 리스트 관리
 ******************************************/
#include "NormalMonsterList.h"
#include "Random.h"
#include "Item.h"
#include "ItemID.h"
#include "WeaponList.h"
#include "ArmorList.h"

#include <iostream>
#include <memory>


Slime::Slime() : Monster("슬라임", 5)
{
    set_max_hp(50);
    set_hp(50);
    set_power(15);
    set_defend(0);
    set_vigor(3);

    drop_table = {
        { 20, ItemID::ReinforceStone },
        { 10, ItemID::NormalWeapon },
        { 15, ItemID::NormalArmor },
        { 7, ItemID::SlimeSword } 
    };
}

const std::vector<DropItem> &Slime::get_drop_table() const
{
    return drop_table;
}

Goblin::Goblin() : Monster("고블린", 10)
{
    set_max_hp(90);
    set_hp(90);
    set_power(20);
    set_defend(4);
    set_vigor(10);

    drop_table = {
        { 30, ItemID::ReinforceStone },
        { 10, ItemID::NormalWeapon },
        { 20, ItemID::NormalArmor },
        { 5, ItemID::GoblinArmor }
    };
}

const std::vector<DropItem> &Goblin::get_drop_table() const
{
    return drop_table;
}

Orc::Orc() : Monster("오크", 20)
{
    set_max_hp(120);
    set_hp(120);
    set_power(30);
    set_defend(6);
    set_vigor(20);

    drop_table = {
        { 35, ItemID::ReinforceStone },
        { 20, ItemID::NormalWeapon },
        { 20, ItemID::NormalArmor },
        { 3, ItemID::PowerGauntlet }
    };
}

const std::vector<DropItem> &Orc::get_drop_table() const
{
    return drop_table;
}
