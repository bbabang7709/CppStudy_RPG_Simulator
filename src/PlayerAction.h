/*****************************************
 *  File_name : PlayerAction.h
 *  플레이어가 할 수 있는 행동의 종류
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
    Shop,
    Save,
    Load,
    Exit
};