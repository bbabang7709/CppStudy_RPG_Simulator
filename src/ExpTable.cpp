/*****************************************
 *  File_name : ExpTable.cpp
 *  레벨업에 필요한 경험치 테이블 정의
 ******************************************/
#include "ExpTable.h"

int ExpTable::get_required_exp(int level)
{
    if (level == 1) return 100;
    if (level <= 10) return 100 + (level - 1) * 50;
    if (level <= 20) return 600 + (level - 10) * 120;
    return 1800 + (level - 20) * 300;
}
