/*****************************************
 *  File_name : InventoryExpand.h
 *  인벤토리 확장에 필요한 데이터
 ******************************************/
#pragma once

#include <vector>

struct InventoryExpandCost
{
    int cost;
    int add_slots;
};

static const std::vector<InventoryExpandCost> cost_table = {
    {  100, 5 },
    {  300, 5 },
    {  700, 5 },
    { 1500, 5 }
};