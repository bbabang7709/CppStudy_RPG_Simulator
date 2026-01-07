/*****************************************
 *  File_name : MonsterAI.h
 *  몬스터의 모든 행동 관리
 ******************************************/
#pragma once
#include "MonsterAction.h"

class Monster;

class MonsterAI
{
public :
    MonsterAI();
    MonsterAction decide_action(Monster &m);
};