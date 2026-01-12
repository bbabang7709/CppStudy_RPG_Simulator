/*****************************************
 *  File_name : MeterialList.cpp
 *  다양한 재료 아이템 구현
 ******************************************/
#include "MeterialList.h"

ReinforceStone::ReinforceStone() : Meterial(ItemDatabase::get(ItemID::ReinforceStone)) {}

DragonScale::DragonScale() : Meterial(ItemDatabase::get(ItemID::DragonScale)) {}

SoulStone_Dragon::SoulStone_Dragon() : Meterial(ItemDatabase::get(ItemID::SoulStone_Dragon)) {}
