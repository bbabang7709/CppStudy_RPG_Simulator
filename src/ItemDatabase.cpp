/*****************************************
 *  File_name : ItemDatabase.cpp
 *  아이템들의 정보 데이터베이스
 ******************************************/
#include "ItemDatabase.h"

const ItemData &ItemDatabase::get(ItemID id) {
    auto it = data.find(id);
    if (it == data.end()) {
        it = data.find(ItemID::None);
    }
    return it->second;
}

const std::unordered_map<ItemID, ItemData> ItemDatabase::data = {
    {ItemID::None, {ItemID::None, "Default", ItemType::None, 0}},
    {ItemID::NormalWeapon, {ItemID::NormalWeapon, "녹슨 단검", ItemType::Weapon, 500}},
    {ItemID::SlimeSword, {ItemID::SlimeSword, "슬라임 검", ItemType::Weapon, 1800}},
    {ItemID::PowerGauntlet, {ItemID::PowerGauntlet, "오크의 파워건틀릿", ItemType::Weapon, 2000}},
    {ItemID::DragonSpear, {ItemID::DragonSpear, "용살창", ItemType::Weapon, 3500}},
    {ItemID::NormalArmor, {ItemID::NormalArmor, "가죽 갑옷", ItemType::Armor, 300}},
    {ItemID::GoblinArmor, {ItemID::GoblinArmor, "고블린 가죽 갑옷", ItemType::Armor, 2000}},
    {ItemID::DragonArmor, {ItemID::DragonArmor, "드래곤 아머", ItemType::Armor, 3200}},
    {ItemID::ReinforceStone, {ItemID::ReinforceStone, "장비 강화석", ItemType::Meterial, 200}},
    {ItemID::DragonScale, {ItemID::DragonScale, "드래곤 비늘", ItemType::Meterial, 600}},
    {ItemID::SoulStone_Dragon, {ItemID::SoulStone_Dragon, "드래곤의 영혼석", ItemType::Meterial, 1300}} 
};