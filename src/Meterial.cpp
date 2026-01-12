/*****************************************
 *  File_name : Meterial.cpp
 *  재료 Meterial 클래스 정의
 ******************************************/
#include "Meterial.h"

Meterial::Meterial(const ItemData &data) : Item(data)
{
    set_stackable(true);
}
