/*****************************************
 *  File_name : Weapon.cpp
 *  무기들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#include "Weapon.h"

#include <Algorithm>

Weapon::Weapon(const std::string name, ItemType type, int price) : Item(name, type, price), weapon_power(0), weapon_defend(0), weapon_hp(0),
                                                                                            weapon_mp(0), weapon_vigor(0), cost(0) 
{
    set_stackable(false);
}

Weapon::~Weapon() = default;

int Weapon::get_weapon_power() const { return weapon_power; }
int Weapon::get_weapon_defend() const { return weapon_defend; }
int Weapon::get_weapon_hp() const { return weapon_hp; }
int Weapon::get_weapon_mp() const { return weapon_mp; }
int Weapon::get_weapon_vigor() const { return weapon_vigor; }
int Weapon::get_cost() const { return cost; }

void Weapon::set_weapon_power(int _power)
{
    weapon_power = std::max(0, _power);
}
void Weapon::set_weapon_defend(int _defend)
{
    weapon_defend = std::max(0, _defend);
}
void Weapon::set_weapon_hp(int _hp)
{
    weapon_hp = std::max(0, _hp);
}
void Weapon::set_weapon_mp(int _mp)
{
    weapon_mp = std::max(0, _mp);
}
void Weapon::set_weapon_vigor(int _vigor)
{
    weapon_vigor = std::max(0, _vigor);
}
void Weapon::set_cost(int _cost)
{
    cost = std::max(0, _cost);
}