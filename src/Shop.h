/*****************************************
 *  File_name : Shop.h
 *  상점 클래스 정의
 ******************************************/
#pragma once

#include "ItemDatabase.h"
#include "Equipment.h"
#include <vector>

class Shop
{
public :
    Shop();

    void list_items() const;
    const ItemData &get_item(int index) const;
    int slot_size;

private :
    std::vector<ItemData> items;
    ItemData no_item;
};