/*****************************************
 *  File_name : Player.h
 *  모험을 진행하는 플레이어 클래스
 ******************************************/
#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Inventory.h"
#include "EnhanceSystem.h"
#include "GameUI.h"

enum class StatType
{
    HP,
    MP,
    POWER,
    DEFEND,
    VIGOR
};

class Player : public Character
{
public :
    Player();
    virtual ~Player();

    int get_base_hp() const;
    int get_base_mp() const;
    int get_base_power() const;
    int get_base_defend() const;
    int get_base_vigor() const;

    StatBlock get_base_stats() const;
    StatBlock get_final_stats() const;

    void set_base_hp(int _hp);
    void set_base_mp(int _mp);
    void set_base_power(int _power);
    void set_base_defend(int _defend);
    void set_base_vigor(int _vigor);

    int get_level() const;
    int get_exp() const;
    int get_next_exp() const;
    void gain_exp(int _exp);
    void set_level(int _level);

    int get_stat_point() const;
    bool invest_stat_point(StatType type, int amount);
    void reset_stat_point();

    void attack(Character &target);

    void reset_player();

    Weapon *get_my_weapon() const;
    Armor *get_my_armor() const;
    std::string get_weapon_name() const;
    std::string get_armor_name() const;
    bool equip_item(std::unique_ptr<Item> item);
    bool try_equip_inventory_item(int index);
    std::unique_ptr<Weapon> unequip_Weapon();
    std::unique_ptr<Armor> unequip_Armor();
    bool try_unequip(int index);

    EnhanceResult enhance_item(int inventory_index);

    int calc_expand_cost();
    bool expand_inventory();
    Inventory &get_inventory();

    bool buy_item(const ItemData &item); // 1개만 구입
    bool buy_item(const ItemData &item, int count); // (count)개 구입
    bool sell_item(int inventory_index, int count); // (count)개 판매

protected :
    Inventory inventory;
    std::unique_ptr<Weapon> my_weapon;
    std::unique_ptr<Armor> my_armor;

private :
    // Level
    int level = 1;
    int exp = 0;
    
    // Stat Point
    int stat_point = 0;

    void level_up();
    void recalc_final_stats() override;
};