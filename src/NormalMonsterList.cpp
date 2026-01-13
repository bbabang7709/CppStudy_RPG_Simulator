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


Slime::Slime() : Monster("슬라임", 100, 10)
{
    base_stats.hp = 50;
    base_stats.power = 15;
    base_stats.defend = 0;
    base_stats.vigor = 3;
    base_stats.cri = 0;
    base_stats.speed = 0;
    
    recalc_final_stats();
    reset_condition();

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

Goblin::Goblin() : Monster("고블린", 300, 20)
{
    base_stats.hp = 90;
    base_stats.power = 25;
    base_stats.defend = 4;
    base_stats.vigor = 10;
    base_stats.cri = 0;
    base_stats.speed = 0;
    
    recalc_final_stats();
    reset_condition();

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

Orc::Orc() : Monster("오크", 500, 30)
{
    base_stats.hp = 120;
    base_stats.power = 40;
    base_stats.defend = 8;
    base_stats.vigor = 25;
    base_stats.cri = 0;
    base_stats.speed = 0;
    
    recalc_final_stats();
    reset_condition();

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
