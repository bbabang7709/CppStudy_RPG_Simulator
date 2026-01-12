/*****************************************
 *  File_name : Item.h
 *  모든 아이템의 기본 속성 정의
 ******************************************/
#pragma once
#include "ItemType.h"
#include "ItemID.h"
#include "ItemDatabase.h"
#include <string>

class Item
{
public :
    Item(const ItemData &data);
    virtual ~Item();

    ItemID get_id() const;
    void set_id(ItemID _id);
    std::string get_name() const;
    std::string get_name(ItemID id) const;
    ItemType get_type() const;
    int get_price() const;

    bool is_stackable() const;
    void set_stackable(bool _is);

    virtual bool is_enhanceable() const { return false; };
    virtual int get_enhance_level() const { return 0; };
    virtual void set_enhance_level(int) {};

    //virtual void use() = 0;

protected :
    ItemID id;
    std::string name;
    ItemType type;
    int price;
    bool stackable = true;
};