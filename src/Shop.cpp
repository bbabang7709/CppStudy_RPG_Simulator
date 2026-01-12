/*****************************************
 *  File_name : Shop.cpp
 *  상점 클래스 정의
 ******************************************/
#include "Shop.h"
#include "Item.h"
#include "ItemID.h"
#include "ItemDatabase.h"
#include "ItemFactory.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include <iostream>
#include <vector>

Shop::Shop()
{
    items = {
        ItemDatabase::get(ItemID::NormalArmor),
        ItemDatabase::get(ItemID::NormalWeapon),
        ItemDatabase::get(ItemID::ReinforceStone)
    };

    no_item = ItemDatabase::get(ItemID::None);
    slot_size = items.size();
}

void Shop::list_items() const
{
    std::cout << "-----------[ 상점 ]-----------" << std::endl;
    int index = 1;
    for (auto &item : items) {
        std::cout << index++ << ". " << item.name << ": " << item.price << " 골드" << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

const ItemData &Shop::get_item(int index) const
{
    if (index < 0 || index > (int)items.size())
        return no_item;
    return items[index - 1];
}
