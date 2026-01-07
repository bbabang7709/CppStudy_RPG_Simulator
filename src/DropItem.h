/*****************************************
 *  File_name : DropItem.h
 *  드롭 아이템 구조체 정의
 ******************************************/
#pragma once
#include <functional>
#include <memory>
#include "Item.h"

struct DropItem
{
    int chance;
    std::function<std::unique_ptr<Item>()> create;
};
