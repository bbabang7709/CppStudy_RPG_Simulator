/*****************************************
 *  File_name : main.cpp
 ******************************************/
#include "Sys.h"
#include "GameProcess.h"
#include "CommercialProcess.h"
#include "SaveSystem.h"
#include "GameUI.h"
#include "BattleSystem.h"
#include "Player.h"
#include "PlayerController.h"
#include "NormalMonsterList.h"
#include "BossMonsterList.h"
#include "MonsterAI.h"
#include "Inventory.h"
#include "ItemDatabase.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "MeterialList.h"
#include "Shop.h"

int main()
{    
    Player player;
    PlayerController p_controller;

    GameProcess process;
    process.run(player, p_controller);

    return 0;
}