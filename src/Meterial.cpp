/*****************************************
 *  File_name : Meterial.cpp
 *  재료 Meterial 클래스 정의
 ******************************************/
#include "Meterial.h"

Meterial::Meterial(const std::string name, ItemType type, int price) : Item(name, type, price)
{
    set_stackable(true);
}
