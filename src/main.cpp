/*****************************************
 *  File_name : main.cpp
 ******************************************/
#include <iostream>

#include "Sys.h"
#include "BattleSystem.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterList.h"
#include "Inventory.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "PlayerController.h"
#include "MonsterAI.h"
#include "MainMenu.h"
#include "SaveSystem.h"

int main()
{    
    Player player;
    PlayerController p_controller;

    MainMenu mainMenu;
    mainMenu.game_process(player, p_controller);

    return 0;
}