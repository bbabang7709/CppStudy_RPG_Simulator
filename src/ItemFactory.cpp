/*****************************************
 *  File_name : ItemFactory.cpp
 *  아이템 생성 관리
 ******************************************/
#include "ItemFactory.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "MeterialList.h"

std::unordered_map<ItemID, std::function<std::unique_ptr<Item>()>> ItemFactory::table = {
    { ItemID::None, []() {
        return nullptr;
    }},
    { ItemID::NormalWeapon, []() {
        return std::make_unique<NormalWeapon>("녹슨 단검", ItemType::Weapon, 5);
    }},
    { ItemID::SlimeSword, []() {
        return std::make_unique<SlimeSword>("슬라임 검", ItemType::Weapon, 30);
    }},
    { ItemID::PowerGauntlet, []() {
        return std::make_unique<PowerGauntlet>("오크의 파워건틀릿", ItemType::Weapon, 100);
    }},
    { ItemID::DragonSpear, []() {
        return std::make_unique<DragonSpear>("용살창", ItemType::Weapon, 350);
    }},
    { ItemID::NormalArmor, []() {
        return std::make_unique<NormalArmor>("낡은 가죽 갑옷", ItemType::Armor, 5);
    }},
    {ItemID::GoblinArmor, []() {
        return std::make_unique<GoblinArmor>("고블린 가죽 갑옷", ItemType::Armor, 40);
    }},
    { ItemID::DragonArmor, []() {
        return std::make_unique<DragonArmor>("드래곤 아머", ItemType::Armor, 170);
    }},
    { ItemID::ReinforceStone, []() {
        return std::make_unique<ReinforceStone>("장비 강화석", ItemType::Meterial, 30);
    }},
    { ItemID::DragonScale, []() {
        return std::make_unique<DragonScale>("드래곤 비늘", ItemType::Meterial, 60);
    }},
    { ItemID::SoulStone_Dragon, []() {
        return std::make_unique<SoulStone_Dragon>("드래곤의 영혼석", ItemType::Meterial, 130);
    }}
};

std::unique_ptr<Item> ItemFactory::create(ItemID id)
{
    auto it = table.find(id);
    if (it == table.end())
        return nullptr;
    return it->second();
}