/*****************************************
 *  File_name : MeterialList.h
 *  다양한 재료 아이템 구현
 ******************************************/
#pragma once

#include "Meterial.h"
#include <string>

class ReinforceStone : public Meterial
{
public :
    ReinforceStone(std::string name, ItemType type, int price);
};

class DragonScale : public Meterial
{
public : 
    DragonScale(std::string name, ItemType type, int price);
};

class SoulStone_Dragon : public Meterial
{
public :
    SoulStone_Dragon(std::string name, ItemType type, int price);
};