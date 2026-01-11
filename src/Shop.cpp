/*****************************************
 *  File_name : Shop.cpp
 *  상점 클래스 정의
 ******************************************/
#include "Shop.h"
#include "Item.h"
#include "ItemID.h"
#include "ItemFactory.h"
#include <iostream>
#include <vector>

Shop::Shop()
{
    items = {
        {ItemID::NormalArmor, "낡은 가죽 갑옷", 30},
        {ItemID::NormalWeapon, "녹슨 단검", 70}
    };

    no_item = {ItemID::None, "", 0};
    slot_size = items.size();
}

void Shop::list_items() const
{
    std::cout << "-----------[ 상점 ]-----------" << std::endl;
    int index = 1;
    for (auto &item : items) {
        std::cout << index++ << ". " << item.name << ": " << item.price << "골드" << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

const ShopItem &Shop::get_item(int index) const
{
    if (index < 0 || index > (int)items.size())
        return no_item;
    return items[index - 1];
}
