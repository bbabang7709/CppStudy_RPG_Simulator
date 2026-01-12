/*****************************************
 *  File_name : Meterial.h
 *  재료 Meterial 클래스 정의
 ******************************************/
#pragma once

#include "Item.h"
#include <string>

class Meterial : public Item
{
public :
    Meterial(const ItemData &data);
};