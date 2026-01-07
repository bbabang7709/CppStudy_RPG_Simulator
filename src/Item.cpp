/*****************************************
 *  File_name : Item.cpp
 *  모든 아이템의 기본 속성 정의
 ******************************************/
#include "Item.h"

Item::Item(std::string name, ItemType type, int price) : name(name), type(type), price(price) {}
Item::~Item() = default;

ItemId Item::get_id() const { return id; }
void Item::set_id(ItemId _id)
{
    id = _id;
}
std::string Item::get_name() const { return name; }
ItemType Item::get_type() const { return type; }
int Item::get_price() const { return price; }