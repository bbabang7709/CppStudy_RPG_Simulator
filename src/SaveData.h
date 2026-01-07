/*****************************************
 *  File_name : SaveData.h
 *  세이브 데이터 구조체 정의
 ******************************************/
#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"

#include <string>
#include <vector>

struct ItemSaveData
{
    std::string name;
    ItemType type;
    int price;
    int stat_bonus;
};

struct PlayerSaveData
{
    int base_hp;
    int base_mp;
    int base_power;
    int base_defend;
    int base_vigor;

    int gold;

    bool has_weapon;
    ItemSaveData weapon;
    bool has_armor;
    ItemSaveData armor;

    std::vector<ItemSaveData> inventory;
};
