/*****************************************
 *  File_name : Weapon.h
 *  무기들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#pragma once
#include "Equipment.h"
#include "ItemDatabase.h"
#include "Sys.h"

class Character;
class Player;

class Weapon : public Equipment
{
public :
    Weapon(const ItemData &data);
    virtual ~Weapon();
    int get_weapon_power() const;
    int get_weapon_defend() const;
    int get_weapon_hp() const;
    int get_weapon_mp() const;
    int get_weapon_vigor() const;
    int get_cost() const;

    void set_weapon_power(int _power);
    void set_weapon_defend(int _defend);
    void set_weapon_hp(int _hp);
    void set_weapon_mp(int _mp);
    void set_weapon_vigor(int _vigor);
    void set_cost(int _cost);

    const StatBlock get_flat_stats() const override;

    virtual void special_attack(Player &user, Character &target) = 0;

protected :
    int cost;
    Sys system;
};