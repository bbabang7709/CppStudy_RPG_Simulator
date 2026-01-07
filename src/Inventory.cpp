/*****************************************
 *  File_name : Inventory.cpp
 *  인벤토리 클래스 정의
 ******************************************/
#include "Inventory.h"

#include <iostream>

Inventory::Inventory() : gold(0),max_size(10) {}
Inventory::~Inventory() = default;

void Inventory::add_item(std::unique_ptr<Item> item)
{
    if ((int)items.size() >= max_size) {
        std::cout << "인벤토리가 가득 찼습니다!!" << std::endl;
    } else {
        items.push_back(std::move(item));
    }
}

void Inventory::remove_item(const std::string &item_name)
{
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->get_name() == item_name) {
            items.erase(it);
            break;
        }
    }
}

std::unique_ptr<Item> Inventory::take_item(const int index)
{
    if (index < 0 || index >= (int)items.size()) {
        return nullptr;
    } else {
        auto item = std::move(items[index]);
        items.erase(items.begin() + index);
        return item;
    }
}

int Inventory::get_max_size() const
{
    return max_size;
}

int Inventory::show_gold() const
{
    return gold;
}

void Inventory::set_max_size(int size)
{
    max_size = size;
}

void Inventory::earn_gold(int amount)
{
    gold += amount;
}

void Inventory::spend_gold(int amount)
{
    if (gold >= amount) {
        gold -= amount;
    } else {
        std::cout << "골드가 부족합니다!!" << std::endl;
    }
}

void Inventory::list_inventory() const
{
    int index = 1;
    std::cout << "인벤토리" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (const auto &item : items) {
        std::cout << index++ << ". " << (*item).get_name() << " (가격 : " << (*item).get_price() << " 골드)" << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout<< "총 아이템 수 : " << items.size() << " / " << max_size << std::endl;
    std::cout << "보유 골드 : " << gold << " Gold" << std::endl << std::endl;
}

std::vector<std::unique_ptr<Item>> &Inventory::get_items()
{
    return items;
}

