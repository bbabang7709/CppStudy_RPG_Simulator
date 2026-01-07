/*****************************************
 *  File_name : Item.h
 *  모든 아이템의 기본 속성 정의
 ******************************************/
#pragma once
#include "ItemType.h"
#include "ItemId.h"
#include <string>

class Item
{
public :
    Item(std::string name, ItemType type, int price);
    virtual ~Item();

    ItemId get_id() const;
    void set_id(ItemId _id);
    std::string get_name() const;
    ItemType get_type() const;
    int get_price() const;

    //virtual void use() = 0;

protected :
    ItemId id;
    std::string name;
    ItemType type;
    int price;
};