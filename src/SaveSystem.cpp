/*****************************************
 *  File_name : SaveSystem.cpp
 *  저장 및 불러오기 시스템
 ******************************************/
#include "SaveSystem.h"
#include "ItemFactory.h"
#include <fstream>
#include <string>


void SaveManager::Save(Player &player)
{
    std::ofstream file("save.txt");

    file << "HP " << player.get_base_hp() << "\n";
    file << "MP " << player.get_base_mp() << "\n"; 
    file << "POWER " << player.get_base_power() << "\n";
    file << "DEFEND " << player.get_base_defend() << "\n";
    file << "VIGOR " << player.get_base_vigor() << "\n";
    file << "GOLD " << player.get_inventory().show_gold() << "\n";

    const auto &slots = player.get_inventory().get_slots();
    file << "INVENTORY_EXPAND_LEVEL " << player.get_inventory().get_expansion_count() << "\n";
    file << "INVENTORY_MAX_SLOTS " << player.get_inventory().get_max_size() << "\n";
    for (const auto &slot : slots) {
        file << "ITEM " << static_cast<int>(slot.item->get_id()) << "\n";
        file << "COUNT " << slot.count << "\n";
    } 

    file << "WEAPON "
         << (player.get_my_weapon() ? static_cast<int>(player.get_my_weapon()->get_id()) : -1) << "\n";
    file << "ARMOR "
         << (player.get_my_armor() ? static_cast<int>(player.get_my_armor()->get_id()) : -1) << "\n";
}

void LoadManager::Load(Player &player, std::string file_name)
{
    player.get_inventory().reset_inventory();
    player.reset_player();
    
    ItemFactory item_factory;
    std::ifstream file(file_name);
    std::string key;
    int value;

    int weapon_id = -1;
    int armor_id = -1;

    while (file >> key >> value) 
    {
        if (key == "HP") player.set_max_hp(value);
        else if (key == "MP") player.set_max_mp(value);
        else if (key == "POWER") player.set_power(value);
        else if (key == "DEFEND") player.set_defend(value);
        else if (key == "VIGOR") player.set_vigor(value);
        else if (key == "GOLD") player.get_inventory().earn_gold(value);
        else if (key == "INVENTORY_EXPAND_LEVEL") player.get_inventory().increase_expansion_count(value);
        else if (key == "INVENTORY_MAX_SLOTS") player.get_inventory().set_max_size(value);
        else if (key == "ITEM") {
            auto item = item_factory.create(static_cast<ItemID>(value));
            file >> key >> value;
            if (key == "COUNT") {
                player.get_inventory().add_item(std::move(item), value);
            }
        } 
        else if (key == "WEAPON") weapon_id = value;
        else if (key == "ARMOR") armor_id = value;
    }
    if (weapon_id != -1) {
        if (player.get_my_weapon() == nullptr)
            player.equip_item(item_factory.create(static_cast<ItemID>(weapon_id)));
    }
    if (armor_id != -1) {
        if (player.get_my_armor() == nullptr)
            player.equip_item(item_factory.create(static_cast<ItemID>(armor_id)));
    }
}