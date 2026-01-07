/*****************************************
 *  File_name : Inventory.h
 *  인벤토리 클래스 정의
 ******************************************/
#pragma once
#include "Item.h"

#include <string>
#include <memory>
#include <vector>

class Inventory
{
public :
    Inventory();
    virtual ~Inventory();
    void add_item(std::unique_ptr<Item> item);
    void remove_item(const std::string &item_neme);
    std::unique_ptr<Item> take_item(const int index);
    int get_max_size() const;
    int show_gold() const;
    void set_max_size(int size);
    void earn_gold(int amount);
    void spend_gold(int amount);
    void list_inventory() const;
    std::vector<std::unique_ptr<Item>> &get_items();



private:
    std::vector<std::unique_ptr<Item>> items;
    int gold;
    int max_size;
};