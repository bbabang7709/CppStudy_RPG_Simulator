/*****************************************
 *  File_name : ItemFactory.h
 *  아이템 생성 관리
 ******************************************/
#include <unordered_map>
#include <memory>
#include <functional>

#include "Item.h"
#include "ItemId.h"

class ItemFactory
{
public :
    static std::unique_ptr<Item> create(ItemId id);

private :
    static std::unordered_map<ItemId, std::function<std::unique_ptr<Item>()>> table;
};