/*****************************************
 *  File_name : ShopItem.h
 *  상점에서 판매되는 아이템 구조체
 ******************************************/
#pragma once

#include "ItemID.h"
#include <string>

struct ShopItem
{
    ItemID id;
    std::string name;
    int price;
};