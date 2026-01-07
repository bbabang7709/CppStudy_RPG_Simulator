/*****************************************
 *  File_name : MainMenu.h
 *  메인 메뉴(홈) 관리
 ******************************************/
#pragma once
#include "Sys.h"
#include "BattleSystem.h"

class MainMenu : public Sys
{
public :
    MainMenu() {};
    void print_mainMenu();
    void print_playerInfo(Player &player);
    void print_monster_selection_menu();
    void equip_menu(Player &player);
    void game_process(Player &player, PlayerController &p_controller);
};