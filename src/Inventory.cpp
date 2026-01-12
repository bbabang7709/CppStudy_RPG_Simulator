/*****************************************
 *  File_name : Inventory.cpp
 *  인벤토리 클래스 정의
 ******************************************/
#include "Inventory.h"
#include <iostream>

Inventory::Inventory() : gold(0), max_size(10) {}
Inventory::~Inventory() = default;

bool Inventory::add_item(std::unique_ptr<Item> item)
{
    if (!item) return false;

    if (item->is_stackable()) {
        for (auto &slot : slots) {
            if (!slot.item) continue;
            if (slot.item->get_id() == item->get_id()) {
                slot.count++;
                return true;
            }
        }
    }

    if ((int)slots.size() >= max_size) {
        std::cout << "인벤토리가 가득 찼습니다." << std::endl;
        return false;
    }

    slots.push_back( { std::move(item), 1 });
    return true;
}
bool Inventory::add_item(std::unique_ptr<Item> item, int count)
{
    if (!item) return false;

    if (item->is_stackable()) {
        for (auto &slot : slots) {
            if (!slot.item) continue;
            if (slot.item->get_id() == item->get_id()) {
                slot.count += count;
                return true;
            }
        }
    }

    if ((int)slots.size() >= max_size) {
        std::cout << "인벤토리가 가득 찼습니다." << std::endl;
        return false;
    }

    slots.push_back( { std::move(item), count });
    return true;
}

void Inventory::remove_item(const std::string &item_name)
{
    int index = 0;
    for (auto &slot : slots) {
        if (!slot.item) continue;
        if (slot.item->get_name() == item_name) {
            slots.erase(slots.begin() + index);
            break;
        }
        index++;
    }
}

std::unique_ptr<Item> Inventory::take_item(const int index)
{
    if (index < 0 || index >= (int)slots.size()) {
        return nullptr;
    }
    auto item = std::move(slots[index].item);
    slots.erase(slots.begin() + index);
    return item;
}
void Inventory::add_slot(ItemSlot slot)
{
    if (!slot.item)
        return;
    for (auto &s : slots) {
        if (s.item && slot.item && (s.item->get_id() == slot.item->get_id()) && s.item->is_stackable()) {
            s.count += slot.count;
            return;
        }
    }
    slots.push_back(std::move(slot));
}

ItemSlot Inventory::take_slot(const int index, int count)
{
    ItemSlot clone_slot = { nullptr, 0 };
    int slot_index = index - 1;
    if (slot_index < 0 || slot_index >= (int)slots.size()) {
        return clone_slot;
    }
    auto &slot = slots[slot_index];
    if (slot.count == count) {
        clone_slot = std::move(slot);
        slots.erase(slots.begin() + slot_index);
    } else {
        clone_slot.item = item_factory.create(slot.item->get_id());
        clone_slot.count = count;
        slot.count -= count;
    }
    return clone_slot;   
}
std::vector<ItemSlot> &Inventory::get_slots()
{
    return slots;
}

bool Inventory::sell_slot(int index, int count, int &earned)
{
    if (index < 0 || index > (int)slots.size())
        return false;

    auto &slot = slots[index];
    if (!slot.item || slot.count < count)
        return false;
    
    earned = slot.item->get_price() * count;
    slot.count -= count;
    if (slot.count == 0)
        slots.erase(slots.begin() + index);
    
    return true;
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

int Inventory::get_max_size() const
{
    return max_size;
}

bool Inventory::expand_inventory(int slot_count)
{
    // if (expansion_count >= max_expansion_count)
    //     return false;
    if (slot_count >= 0) {
        max_size += slot_count;
        return true;
    }
    return false;
}

int Inventory::get_expansion_count() const { return expansion_count; }

int Inventory::get_max_expansion_count() const { return max_expansion_count; }

int Inventory::show_gold() const
{
    return gold;
}

void Inventory::increase_expansion_count(int _count)
{
    expansion_count += _count;
}
void Inventory::set_max_size(int size)
{
    max_size = size;
}

void Inventory::list_inventory() const
{
    int index = 1;
    std::cout << "인벤토리" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (const auto &slot : slots) {
        std::cout << index++ << ". " << slot.item->get_name() << " x " << slot.count <<  std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout<< "슬롯 수 : " << slots.size() << " / " << max_size << std::endl;
    std::cout << "보유 골드 : " << gold << " Gold" << std::endl << std::endl;
}

void Inventory::reset_inventory()
{
    gold = 0;
    slots.clear();
}

