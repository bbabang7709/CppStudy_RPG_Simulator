/*****************************************
 *  File_name : PlayerAction.h
 *  플레이어의 모든 선택지 관리
 ******************************************/
#pragma once

 enum class PlayerAction
{
    Attack = 1,
    Special,
    Heal,
    Escape
};

enum class MenuSelection
{
    BattleStart = 1,
    PlayerInfo,
    Inventory,
    Commerse,
    Save,
    Load,
    Exit
};

enum class MonsterType
{
    Exit = 0,
    NormalMonster,
    BossMonster
};