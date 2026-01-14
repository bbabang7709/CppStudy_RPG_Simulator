/*****************************************
 *  File_name : Armor.h
 *  방어구들의 공통 스탯 & 특수 기술 관리
 ******************************************/
#pragma once
#include "Equipment.h"

class Character;
class Player;

class Armor : public Equipment
{
public :
    Armor(const ItemData &data);
    virtual ~Armor();
    int get_armor_power() const;
    int get_armor_defend() const;
    int get_armor_hp() const;
    int get_armor_mp() const;
    int get_armor_vigor() const;

    void set_armor_power(int _power);
    void set_armor_defend(int _defend);
    void set_armor_hp(int _hp);
    void set_armor_mp(int _mp);
    void set_armor_vigor(int _vigor);

    const StatBlock get_flat_stats() const override;

protected :
    int armor_power;
    int armor_defend;
    int armor_hp;
    int armor_mp;
    int armor_vigor;
};