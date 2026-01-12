/*****************************************
 *  File_name : EnhanceSystem.cpp
 *  강화 시스템 정의
 ******************************************/
#pragma once

#include "Sys.h"
#include "ItemType.h"
#include <vector>

struct EnhanceRule
{
    int gold_cost;
    int meterial_cost;
    int success_rate;
};

enum class EnhanceResult
{
    Success,
    Failed,
    Destroyed,
    MaxLevel,
    noMeterial,
    Disable,
    Error
};

class EnhanceSystem : public Sys
{
public :
    static EnhanceRule get_rule(int level);

private :
    static const std::vector<EnhanceRule> enhance_table;
};