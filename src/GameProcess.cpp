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

void GameProcess::player_info_process(Player &player)
{
    while (true)
    {
        clear_screen();
        UI.print_playerInfo(player);
        std::cout << "========= 무엇을 할까? =========" << std::endl;
        std::cout << "0. 돌아가기" << std::endl;
        std::cout << "1. 스탯 포인트 분배" << std::endl;
        std::cout << "2. 스탯 포인트 초기화" << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "입력 >>> ";
        int c1 = safe_int_input();
        if (c1 == 0)
            break;
        else if (c1 == 1) {
            while (true)
            {
                clear_screen();
                auto stats = player.get_stat_point_total();
                int amount = 0;
                std::cout << "===============================" << std::endl;
                std::cout << "STR : " << stats.str << "   DEX : " << stats.dex << "   CON : " << stats.con << std::endl << std::endl;
                std::cout << "남은 스탯포인트 : " << player.get_stat_point() << std::endl;
                std::cout << "===============================" << std::endl << std::endl;
                std::cout << "========= 어떻게 할까? =========" << std::endl;
                std::cout << "0. 돌아가기." << std::endl;
                std::cout << "1. STR에 분배" << std::endl;
                std::cout << "2. DEX에 분배" << std::endl;
                std::cout << "3. CON에 분배" << std::endl;
                std::cout << "===============================" << std::endl;
                std::cout << "입력 >>> ";
                int c2 = safe_int_input(1, 3);
                if (c2 != 1 && c2 != 2 && c2 != 3)
                    break;
                if (player.get_stat_point() == 0)
                    continue;
                std::cout << "얼마나 분배하시겠습니까??" << std::endl;
                std::cout << "입력 >>> ";
                amount = safe_int_input();
                if (amount < 0 ) {
                    UI.print_error_screen();
                    continue;
                }
                if (amount > player.get_stat_point()) {
                    std::cout << "포인트가 부족합니다." << std::endl;
                    delay(1000);
                    continue;
                }
                if (c2 == 1) {
                    player.invest_stat_point(StatPointType::STR, amount);
                } else if (c2 == 2) {
                    player.invest_stat_point(StatPointType::DEX, amount);
                } else if (c2 == 3) {
                    player.invest_stat_point(StatPointType::CON, amount);
                } else 
                    break;
            }
        } else if (c1 == 2) {
            player.reset_stat_point();
            std::cout << "초기화 되었습니다." << std::endl;
            delay(1000);
        }
    }
}

void GameProcess::itemInfo_process(Player &player)
{
    while (true)
    {
        clear_screen();
        auto &inventory = player.get_inventory();
        inventory.list_inventory();
        std::cout << "정보를 확인할 아이템을 선택하세요. (0 : 돌아가기)" << std::endl;
        std::cout << "입력 >>> ";
        int c = safe_int_input();
        clear_screen();
        if (c == 0) 
            break;
        if (!player.try_request_item_info(c)) {
            std::cout << "오류가 발생했습니다." << std::endl;
            continue;
        }
        std::cout << std::endl << "계속하려면 Enter...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
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
            player_info_process(player);
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
                case InventoryMenu::ItemInfo :
                    itemInfo_process(player);
                    break;
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