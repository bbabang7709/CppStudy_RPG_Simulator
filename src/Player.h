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

    void set_base_hp(int _hp);
    void set_base_mp(int _mp);
    void set_base_power(int _power);
    void set_base_defend(int _defend);
    void set_base_vigor(int _vigor); 

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
    int base_hp;
    int base_mp;
    int base_power;
    int base_defend;
    int base_vigor;
};