/*****************************************
 *  File_name : WeaponList.h
 *  다양한 종류의 무기 구현
 ******************************************/
#pragma once

#include "Weapon.h"
#include "Player.h"

class NormalWeapon : public Weapon
{
public :
    NormalWeapon();
    void special_attack(Player &user, Character &target) override;
    //void use() override;
};

class SlimeSword : public Weapon
{
public :
    SlimeSword();
    void special_attack(Player &user, Character &target) override;
};

class PowerGauntlet : public Weapon
{
public :
    PowerGauntlet();
    void special_attack(Player &user, Character &target) override;
};

class DragonSpear : public Weapon
{
public :
    DragonSpear();
    void special_attack(Player &user, Character &target) override;
};