/*****************************************
 *  File_name : MonsterPattern.h
 *  몬스터의 패턴 class 정의
 ******************************************/
#pragma once

#include "BattleSystem.h"

class MonsterPattern
{
public :
    virtual ~MonsterPattern() = default;
    virtual bool can_excute(const BattleContext ctx) const = 0;
    virtual void excute(BattleContext ctx) = 0;
};