/*****************************************
 *  File_name : ItemSlot.h
 *  아이템 슬롯 --> 다중 적재 기능 추가
 ******************************************/
#pragma once

#include "Item.h"
#include <memory>

struct ItemSlot
{
    std::unique_ptr<Item> item;
    int count;
};