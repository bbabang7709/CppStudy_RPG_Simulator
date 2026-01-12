/*****************************************
 *  File_name : Armor.cpp
 *  방어구들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#include "Armor.h"

#include <Algorithm>

Armor::Armor(const ItemData &data) : Equipment(data), armor_power(0), armor_defend(0), armor_hp(0),
                               armor_mp(0), armor_vigor(0)
{
    set_stackable(false);
};

Armor::~Armor() = default;
int Armor::get_armor_power() const { return armor_power; }
int Armor::get_armor_defend() const { return armor_defend; }
int Armor::get_armor_hp() const { return armor_hp; }
int Armor::get_armor_mp() const { return armor_mp; }
int Armor::get_armor_vigor() const { return armor_vigor; }

void Armor::set_armor_power(int _power)
{
    armor_power = std::max(0, _power);
}
void Armor::set_armor_defend(int _defend)
{
    armor_defend = std::max(0, _defend);
}
void Armor::set_armor_hp(int _hp)
{
    armor_hp = std::max(0, _hp);
}
void Armor::set_armor_mp(int _mp)
{
    armor_mp = std::max(0, _mp);
}
void Armor::set_armor_vigor(int _vigor)
{
    armor_vigor = std::max(0, _vigor);
}