/*****************************************
 *  File_name : Item.cpp
 *  모든 아이템의 기본 속성 정의
 ******************************************/
#include "Item.h"
#include "ItemFactory.h"
#include <iostream>

Item::Item(const ItemData &data) : id(data.id), name(data.name), type(data.type), price(data.price) {}
Item::~Item() = default;

ItemID Item::get_id() const { return id; }
void Item::set_id(ItemID _id)
{
    id = _id;
}
std::string Item::get_name() const { return name; }
std::string Item::get_name(ItemID id) const
{
    return ItemFactory::create(id)->get_name();
}
ItemType Item::get_type() const { return type; }
int Item::get_price() const { return price; }

bool Item::is_stackable() const { return stackable; }
void Item::set_stackable(bool _is) { stackable = _is; }