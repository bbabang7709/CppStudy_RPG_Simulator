/*****************************************
 *  File_name : ItemFactory.cpp
 *  아이템 생성 관리
 ******************************************/
#include "ItemFactory.h"
#include "WeaponList.h"
#include "ArmorList.h"

std::unordered_map<ItemId, std::function<std::unique_ptr<Item>()>> ItemFactory::table = {
    { ItemId::NormalWeapon, []() {
        return std::make_unique<NormalWeapon>("녹슨 단검", ItemType::Weapon, 5);
    }},
    { ItemId::SlimeSword, []() {
        return std::make_unique<SlimeSword>("슬라임 검", ItemType::Weapon, 30);
    }},
    { ItemId::PowerGauntlet, []() {
        return std::make_unique<PowerGauntlet>("오크의 파워건틀릿", ItemType::Weapon, 100);
    }},
    { ItemId::NormalArmor, []() {
        return std::make_unique<NormalArmor>("낡은 가죽 갑옷", ItemType::Armor, 5);
    }},
    {ItemId::GoblinArmor, []() {
        return std::make_unique<GoblinArmor>("고블린 가죽 갑옷", ItemType::Armor, 40);
    }}
};

std::unique_ptr<Item> ItemFactory::create(ItemId id)
{
    auto it = table.find(id);
    if (it == table.end())
        return nullptr;
    return it->second();
}