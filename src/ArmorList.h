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
    NormalArmor();
};

class GoblinArmor : public Armor
{
public :    
    GoblinArmor();
};

class DragonArmor : public Armor
{
public :    
   DragonArmor();
};