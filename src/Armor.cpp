/*****************************************
 *  File_name : Armor.cpp
 *  방어구들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#include "Armor.h"

#include <Algorithm>

Armor::Armor(const ItemData &data) : Equipment(data)
{
    set_stackable(false);
};

Armor::~Armor() = default;

const StatBlock Armor::get_flat_stats() const
{
    StatBlock result = flat_stats;
    result.defend += enhance_level + (flat_stats.defend * enhance_level * 0.02);

    return result;
}