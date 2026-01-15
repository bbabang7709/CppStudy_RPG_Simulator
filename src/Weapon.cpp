/*****************************************
 *  File_name : Weapon.cpp
 *  무기들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#include "Weapon.h"

#include <Algorithm>

Weapon::Weapon(const ItemData &data) : Equipment(data), cost(0) 
{
    set_stackable(false);
}

Weapon::~Weapon() = default;

int Weapon::get_cost() const { return cost; }

void Weapon::set_cost(int _cost)
{
    cost = std::max(0, _cost);
}

const StatBlock Weapon::get_flat_stats() const
{
    StatBlock result = flat_stats;
    result.power += enhance_level * 3 + (flat_stats.power * enhance_level * 0.05);

    return result;
}