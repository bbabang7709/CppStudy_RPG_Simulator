/*****************************************
 *  File_name : Inventory.h
 *  인벤토리 클래스 정의
 ******************************************/
#pragma once
#include "Item.h"
#include "ItemSlot.h"
#include "ItemFactory.h"

#include <string>
#include <memory>
#include <vector>

enum class InventoryMenu
{
    Exit = 0,
    ItemInfo,
    Equip,
    Unequip,
    Expand
};

class Inventory
{
public :
    Inventory();
    virtual ~Inventory();
    bool add_item(std::unique_ptr<Item> item);
    bool add_item(std::unique_ptr<Item> item, int count);
    void remove_item(const std::string &item_name);
    std::unique_ptr<Item> take_item(const int index);

    void add_slot(ItemSlot slot);
    ItemSlot take_slot(const int index, int count);
    std::vector<ItemSlot> &get_slots();

    bool sell_slot(int index, int count, int &earned);
    void earn_gold(int amount);
    void spend_gold(int amount);
    
    int get_max_size() const;
    bool expand_inventory(int slot_count);
    int get_expansion_count() const;
    int get_max_expansion_count() const;
    int show_gold() const;
    void increase_expansion_count(int _count);
    void set_max_size(int size);
    
    void list_inventory() const;
    void reset_inventory();

    bool print_item_info(int inventory_index);

private:
    std::vector<std::unique_ptr<Item>> items;
    std::vector<ItemSlot> slots;
    ItemFactory item_factory;
    int gold;
    int max_size;
    int expansion_count = 0;
    int max_expansion_count = 4;
};