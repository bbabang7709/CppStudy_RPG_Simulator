/*****************************************
 *  File_name : ItemFactory.cpp
 *  아이템 생성 관리
 ******************************************/
#include "ItemFactory.h"
#include "ItemDatabase.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "MeterialList.h"

std::unordered_map<ItemID, ItemCreator> ItemFactory::creators = {
    { ItemID::None, []() { return nullptr; }},
    { ItemID::NormalWeapon, []() { return std::make_unique<NormalWeapon>(); } },
    { ItemID::SlimeSword, []() { return std::make_unique<SlimeSword>(); } },
    { ItemID::PowerGauntlet, []() { return std::make_unique<PowerGauntlet>(); } },
    { ItemID::DragonSpear, []() { return std::make_unique<DragonSpear>(); } },
    { ItemID::NormalArmor, []() { return std::make_unique<NormalArmor>(); } },
    { ItemID::GoblinArmor, []() { return std::make_unique<GoblinArmor>(); } },
    { ItemID::DragonArmor, []() { return std::make_unique<DragonArmor>(); } },
    { ItemID::ReinforceStone, []() { return std::make_unique<ReinforceStone>(); } },
    { ItemID::DragonScale, []() { return std::make_unique<DragonScale>(); } },
    { ItemID::SoulStone_Dragon, []() { return std::make_unique<SoulStone_Dragon>(); } }
};

std::unique_ptr<Item> ItemFactory::create(ItemID id)
{
    auto it = creators.find(id);
    if (it == creators.end()) {
        return nullptr;
    }
    return it->second();
}