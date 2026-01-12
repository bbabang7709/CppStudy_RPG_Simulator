/*****************************************
 *  File_name : EnhanceSystem.cpp
 *  강화 시스템 정의
 ******************************************/
#include "EnhanceSystem.h"

const std::vector<EnhanceRule> EnhanceSystem::enhance_table = {
    {100,   1, 95}, // +0 -> +1
    {200,   2, 90}, // +1 -> +2
    {400,   4, 80}, // +2 -> +3
    {700,   7, 75}, // +3 -> +4
    {1100, 11, 60}, // +4 -> +5
    {1600, 16, 50}, // +5 -> +6
    {2200, 22, 40}, // +6 -> +7
    {2900, 29, 35}, // +7 -> +8
    {3700, 37, 20}, // +8 -> +9
    {4600, 46, 20}  // +9 -> +10
};

EnhanceRule EnhanceSystem::get_rule(int level)
{
    return enhance_table[level];
}
