/*****************************************
 *  File_name : Shop.h
 *  상점 클래스 정의
 ******************************************/
#pragma once

#include "ShopItem.h"
#include <vector>

class Shop
{
public :
    Shop();

    void list_items() const;
    const ShopItem &get_item(int index) const;
    int slot_size;

private :
    std::vector<ShopItem> items;
    ShopItem no_item;
};