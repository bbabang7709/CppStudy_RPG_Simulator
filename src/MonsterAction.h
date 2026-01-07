/*****************************************
 *  File_name : MonsterAction.h
 *  몬스터가 할 수 있는 행동의 종류
 ******************************************/
#pragma once

enum class MonsterAction
{
    Attack,
    StrongAttack,
    Defend,
    Heal,
    Idle
};