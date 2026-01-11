/*****************************************
 *  File_name : ItemFactory.h
 *  아이템 생성 관리
 ******************************************/
#pragma once

#include <unordered_map>
#include <memory>
#include <functional>

#include "Item.h"
#include "ItemID.h"

class ItemFactory
{
public :
    static std::unique_ptr<Item> create(ItemID id);

private :
    static std::unordered_map<ItemID, std::function<std::unique_ptr<Item>()>> table;
};