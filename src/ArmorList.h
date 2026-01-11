/*****************************************
 *  File_name : ArmorList.h
 *  댜양한 종류의 Armor 구현
 ******************************************/
#pragma once

#include "Armor.h"
#include "Player.h"

class NormalArmor : public Armor
{
public :
    NormalArmor(const std::string name, ItemType type, int price);
};

class GoblinArmor : public Armor
{
public :    
    GoblinArmor(const std::string name, ItemType type, int price);
};

class DragonArmor : public Armor
{
public :    
   DragonArmor(const std::string name, ItemType type, int price);
};