/*****************************************
 *  File_name : MonsterList.cpp
 *  몬스터 리스트 관리
 ******************************************/
#include "MonsterList.h"
#include "Random.h"
#include "Item.h"
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
        { 40, []() { return std::make_unique<NormalWeapon>("녹슨 단검", ItemType::Weapon, 5); } },
        { 39, []() { return std::make_unique<NormalArmor>("낡은 가죽 갑옷", ItemType::Armor, 5); } },
        { 20, []() { return std::make_unique<SlimeSword>("슬라임 검", ItemType::Weapon, 30);  } }
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
        { 50, []() { return std::make_unique<NormalWeapon>("녹슨 단검", ItemType::Weapon, 5); } },
        { 45, []() { return std::make_unique<NormalArmor>("낡은 가죽 갑옷", ItemType::Armor, 5); } },
        { 20, []() { return std::make_unique<NormalArmor>("고블린 가죽 갑옷", ItemType::Armor, 40);}  }
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
    set_vigor(15);

    drop_table = {
        { 60, []() { return std::make_unique<NormalWeapon>("녹슨 단검", ItemType::Weapon, 5); } },
        { 55, []() { return std::make_unique<NormalArmor>("낡은 가죽 갑옷", ItemType::Armor, 5); } },
        { 5, []() { return std::make_unique<PowerGauntlet>("오크의 파워건틀릿", ItemType::Weapon, 100); } }
    };
}

const std::vector<DropItem> &Orc::get_drop_table() const
{
    return drop_table;
}
