/*****************************************
 *  File_name : ItemDatabase.h
 *  아이템들의 정보 데이터베이스
 ******************************************/
#pragma once

#include "ItemID.h"
#include "ItemType.h"
#include <string>
#include <unordered_map>

struct ItemData
{
    ItemID id;
    std::string name;
    ItemType type;
    int price;
};

class ItemDatabase
{
public :
    static const ItemData &get(ItemID id);

private :
    static const std::unordered_map<ItemID, ItemData> data;
};