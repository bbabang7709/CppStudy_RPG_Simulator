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
    ReinforceStone();
};

class DragonScale : public Meterial
{
public : 
    DragonScale();
};

class SoulStone_Dragon : public Meterial
{
public :
    SoulStone_Dragon();
};