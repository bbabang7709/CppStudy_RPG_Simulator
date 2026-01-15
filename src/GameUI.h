/*****************************************
 *  File_name : GameUI.h
 *  UI 출력 시스템 구현
 ******************************************/
#pragma once

#include "Sys.h"
#include "Player.h"
#include <string>

class Monster;

class GameUI : public Sys
{
public :
    void print_message(std::string msg);
    void print_line();
    void print_mainMenu();
    void print_status(Monster &mon, Player &player);
    void print_equipment(Player &player);
    void print_menu();
    void print_playerInfo(const Player &player);
    void print_monster_type_selection_menu();
    void print_normal_monster_selection_menu();
    void print_boss_monster_selection_menu();
    void print_inventory_selection_menu();
    void print_equip_selection_menu();
    void print_equip_result(bool TF);
    void print_unequip_selection_menu();
    void print_unequip_result(bool TF);
    void print_expand_result(bool TF);
    void print_get_exp(int exp);
    void print_get_gold(int drop_gold, int after_gold);
    void print_get_item(std::string item_name);
    void print_save_menu();
    void print_save_success();
    void print_load_menu();
    void print_load_success();
    void print_exit_menu();
    void print_error_screen();

    void print_commercialArea_menu();
    void print_shop_menu();
    void print_shop_buy_menu();
    void print_shop_buy_result(bool TF);
    void print_shop_sell_menu();
    void print_ask_sell_count();
    void print_shop_sell_result(bool TF);
    void print_forge_menu();
    void print_enhance_selection();
    void print_required_meterial_for_enhance(const int &level);
    void print_forge_result(EnhanceResult result);
};