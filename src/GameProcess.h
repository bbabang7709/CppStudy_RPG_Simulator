/*****************************************
 *  File_name : GameProcess.h
 *  게임의 진행 관리
 ******************************************/
#pragma once
#include "Sys.h"
#include "CommercialProcess.h"
#include "BattleSystem.h"
#include "GameUI.h"

class GameProcess : public Sys
{
public :
    void equip_process(Player &player);
    void inventory_expand_process(Player &player);
    void shop_process(Player &player);
    void forge_process(Player &player);
    void NormalMonsterBattle(Player &player, PlayerController &p_controller);
    void BossMonsterBattle(Player &player, PlayerController &p_controller);

    void run(Player &player, PlayerController &p_controller);

private :
    GameUI UI;
    CommercialProcess CP;
};