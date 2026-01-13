/*****************************************
 *  File_name : GameProcess.cpp
 *  메인 메뉴(홈) 관리
 ******************************************/
#include "GameProcess.h"
#include "PlayerAction.h"
#include "NormalMonsterList.h"
#include "BossMonsterList.h"
#include "SaveSystem.h"
#include "Inventory.h"
#include "InventoryExpand.h"
#include "Shop.h"
#include <iostream>
#include <thread>
#include <chrono>


GameProcess::GameProcess(CommercialProcess &CP) : CP(CP) {}

void GameProcess::equip_process(Player &player)
{
    int choice;
    while (true)
    {
        clear_screen();
        player.get_inventory().list_inventory();
        UI.print_equip_selection_menu();
        choice = safe_int_input();
        if (choice == 0)
            break;
        bool is_success = player.try_equip_inventory_item(choice);
        UI.print_equip_result(is_success);
    }
}
void GameProcess::unequip_process(Player &player)
{
    int choice;
    while (true)
    {
        clear_screen();
        UI.print_equipment(player);
        UI.print_unequip_selection_menu();
        choice = safe_int_input();
        if (choice == 0)
            break;
        bool is_success = player.try_unequip(choice);
        UI.print_unequip_result(is_success);
    }
}

void GameProcess::inventory_expand_process(Player &player)
{
    clear_screen();
    Inventory &inventory = player.get_inventory();
    int level = inventory.get_expansion_count();
    int max_level = inventory.get_max_expansion_count();
    inventory.list_inventory();
    if (level >= max_level) {
        std::cout << "이미 최대로 확장했습니다." << std::endl;
        delay(1000);
        return;
    }
    std::cout << "인벤토리 슬롯을 확장하겠습니까??" << std::endl;
    std::cout << "비용 : " << cost_table[level].cost << std::endl;
    std::cout << "(0 : 돌아가기 1 : 확장한다)" << std::endl;
    std::cout << "입력 >>> ";
    int reply = safe_int_input();
    if (reply == 0) {
        return;
    } else if (reply == 1) {
        bool is_success = player.expand_inventory();
        UI.print_expand_result(is_success);
    }
}

void GameProcess::shop_process(Player &player)
{
    Shop shop;
    int c1 = 0, index = 0;
    bool is_success;

    while (true)
    {
        UI.print_shop_menu();
        c1 = safe_int_input();
        if (c1 == 0) 
            break;
        else if (c1 == 1) {
            while (true) {
                clear_screen();
                shop.list_items();
                player.get_inventory().list_inventory();
                UI.print_shop_buy_menu();
                index = safe_int_input();
                if (index == 0)
                    break;
                if (index < 0 || index > shop.slot_size) {
                    UI.print_error_screen();
                    continue;
                }
                is_success = player.buy_item(shop.get_item(index));
                UI.print_shop_buy_result(is_success);
            }
        } else if (c1 == 2) {
            while (true) {
                clear_screen();
                player.get_inventory().list_inventory();
                UI.print_shop_sell_menu();
                index = safe_int_input();
                if (index == 0)
                    break;
                if (index < 0 || index > (int)player.get_inventory().get_slots().size()) {
                    UI.print_error_screen();
                    continue;
                }
                UI.print_ask_sell_count();
                int sell_count = safe_int_input();
                if (sell_count == 0)
                    continue;
                is_success = player.sell_item(index, sell_count);
                UI.print_shop_sell_result(is_success);
            }
        } else {
            UI.print_error_screen();
        }
    }
}
void GameProcess::forge_process(Player &player)
{
    int c = 0, index = 0;
    while (true)
    {
        clear_screen();
        UI.print_forge_menu();
        c = safe_int_input();
        if (c == 0)
            break;
        else if (c == 1) {
            while (true)
            {
                clear_screen();
                player.get_inventory().list_inventory();
                UI.print_enhance_selection();
                index = safe_int_input();
                if (index == 0) 
                    break;
                EnhanceResult result = player.enhance_item(index);
                UI.print_forge_result(result);
            }
        }
    }
}
void GameProcess::NormalMonsterBattle(Player &player, PlayerController &p_controller)
{
    clear_screen();
    int select;
    MonsterAI ai;
    NormalMonsterType mon_type;
    UI.print_normal_monster_selection_menu();
    select = safe_int_input();
    mon_type = static_cast<NormalMonsterType>(select);
    switch (mon_type)
    {
    case NormalMonsterType::Slime :
    {
        Slime monster;
        BattleSystem battleSystem(player, p_controller, monster, ai);
        battleSystem.start_battle();
        break;
    }
    case NormalMonsterType::Goblin :
    {
        Goblin monster;
        BattleSystem battleSystem(player, p_controller, monster, ai);
        battleSystem.start_battle();
        break;
    }
    case NormalMonsterType::Orc :
    {
        Orc monster;
        BattleSystem battleSystem(player, p_controller, monster, ai);
        battleSystem.start_battle();
        break;
    }
    case NormalMonsterType::Exit :
        break;
    default :
        UI.print_error_screen();
        break;   
    }
}

void GameProcess::BossMonsterBattle(Player &player, PlayerController &p_controller)
{
    clear_screen();
    int select;
    MonsterAI ai;
    BossMonsterType mon_type;
    UI.print_boss_monster_selection_menu();
    select = safe_int_input();
    if (select == -1) {
        UI.print_error_screen();
    }
    mon_type = static_cast<BossMonsterType>(select);
    switch (mon_type)
    {
    case BossMonsterType::Dragon :
    {
        Dragon monster;
        BattleSystem battleSystem(player, p_controller, monster, ai);
        battleSystem.start_battle();
        break;
    }
    case BossMonsterType::Exit :
        break;
    default :
        UI.print_error_screen();
        break;   
    }
}

void GameProcess::run(Player &player, PlayerController &p_controller)
{
    int reply; 
    
    while (true)
    {
        player.reset_condition();
        clear_screen();
        UI.print_mainMenu();
        reply = safe_int_input();
        if (reply == -1) {
            UI.print_error_screen();
            continue;
        }
        MenuSelection index = static_cast<MenuSelection>(reply);
        switch (index)
        {
        case MenuSelection::BattleStart :
        {
            clear_screen();
            int mon_type_select;
            UI.print_monster_type_selection_menu();
            mon_type_select = safe_int_input();
            MonsterType result = static_cast<MonsterType>(mon_type_select);
            switch (result)
            {
            case MonsterType::Exit :
                break;
            case MonsterType::NormalMonster :
                NormalMonsterBattle(player, p_controller);
                break;
            case MonsterType::BossMonster :
                BossMonsterBattle(player, p_controller);
                break;    
            default :
                UI.print_error_screen();
                break;
            }
            break;
        }
        case MenuSelection::PlayerInfo :
            UI.print_playerInfo(player);
            break;
        case MenuSelection::Inventory :
        {
            while (true)
            {
                clear_screen();
                player.get_inventory().list_inventory();
                UI.print_inventory_selection_menu();
                InventoryMenu e_select = static_cast<InventoryMenu>(safe_int_input());
                switch (e_select) {
                case InventoryMenu::Equip :
                    equip_process(player);
                    break;
                case InventoryMenu::Unequip :
                    unequip_process(player);
                    break;
                case InventoryMenu::Expand :
                    inventory_expand_process(player);
                    break;
                default :
                    break;
                }
                if (e_select == InventoryMenu::Exit) break;
            }
            break;
        }
        case MenuSelection::Commerse :
            CP.run(player);
            break;
        case MenuSelection::Save :
        {
            int save_choice;
            SaveManager save_manager;
            UI.print_save_menu();
            save_choice = safe_int_input();
            if (save_choice == 1) {
                save_manager.Save(player);
                UI.print_save_success();
            }
            break;
        }
        case MenuSelection::Load :
        {
            int load_choice;
            LoadManager load_manager;
            UI.print_load_menu();
            load_choice = safe_int_input();
            if (load_choice == 1) {
                load_manager.Load(player, "save.txt");
                UI.print_load_success();
            }
            break;
        }
        case MenuSelection::Exit :
            UI.print_exit_menu();
            return;
        default :
            UI.print_error_screen();
            break;
        }
    }
}