/*****************************************
 *  File_name : MainMenu.cpp
 *  메인 메뉴(홈) 관리
 ******************************************/
#include "MainMenu.h"
#include "PlayerAction.h"
#include "MonsterList.h"
#include "SaveSystem.h"

#include <iostream>
#include <thread>
#include <chrono>

void MainMenu::print_mainMenu()
{
    std::cout << "======== 무엇을 할까?? ========" << std::endl;
    std::cout << "1. 전투 시작" << std::endl;
    std::cout << "2. 플레이어 정보" << std::endl;
    std::cout << "3. 인벤토리 확인" << std::endl;
    std::cout << "4. 상점(미구현)" << std::endl;
    std::cout << "5. 저장하기" << std::endl;
    std::cout << "6. 불러오기" << std::endl;
    std::cout << "7. 종료" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "입력 >>> ";
}

void MainMenu::print_playerInfo(Player &player)
{
    clear_screen();
    std::cout << "======== 플레이어 정보 ========" << std::endl;
    std::cout << "HP : " << player.get_hp() << " / " << player.get_max_hp() << std::endl;
    std::cout << "MP : " << player.get_mp() << " / " << player.get_max_mp() << std::endl;
    std::cout << "공격력 : " << player.get_power() << std::endl;
    std::cout << "방어력 : " << player.get_defend() << std::endl;
    std::cout << "활력 : " << player.get_vigor() << std::endl << std::endl;
    std::cout << "무기 : " << player.get_weapon_name() << std::endl;
    std::cout << "방어구 : " << player.get_armor_name() << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "계속하려면 Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void MainMenu::print_monster_selection_menu()
{
    std::cout << "======== 몬스터 선택 ========" << std::endl;
    std::cout << "1. 슬라임" << std::endl;
    std::cout << "2. 고블린" << std::endl;
    std::cout << "3. 오크" << std::endl;
    std::cout << "4. 돌아가기" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "입력 >>> ";
}

void MainMenu::equip_menu(Player &player)
{
    int choice;
    while (true)
    {
        clear_screen();
        player.get_inventory().list_inventory();
        std::cout << "장착할 아이템의 번호를 입력하세요. (0 : 돌아가기) >>> ";
        std::cin >> choice;
        if (choice == 0)
            break;
        auto item = player.get_inventory().take_item(choice - 1);
        if (!item)
        {
            std::cout << "잘못된 입력!!!" << std::endl;
            delay(1000);
            continue;
        } else {
            player.equip_item(std::move(item));
            std::cout << "아이템을 장착했습니다." << std::endl;
            delay(1000);
        }

    }
}

void MainMenu::game_process(Player &player, PlayerController &p_controller)
{
    int reply, m_select, e_select;
    
    while (true)
    {
        player.reset_status();
        clear_screen();
        print_mainMenu();
        std::cin >> reply;
        MenuSelection index = static_cast<MenuSelection>(reply);
        switch (index)
        {
        case MenuSelection::BattleStart :
        {
            clear_screen();
            MonsterAI ai;
            MonsterType m_type;
            print_monster_selection_menu();
            std::cin >> m_select;
            m_type = static_cast<MonsterType>(m_select);
            switch (m_type)
            {
            case MonsterType::Slime :
            {
                Slime monster;
                BattleSystem battleSystem(player, p_controller, monster, ai);
                battleSystem.start_battle();
                break;
            }
            case MonsterType::Goblin :
            {
                Goblin monster;
                BattleSystem battleSystem(player, p_controller, monster, ai);
                battleSystem.start_battle();
                break;
            }
            case MonsterType::Orc :
            {
                Orc monster;
                BattleSystem battleSystem(player, p_controller, monster, ai);
                battleSystem.start_battle();
                break;
            }
            case MonsterType::Exit :
                continue;
            default :
                std::cout << "잘못된 입력!!!" << std::endl;
                delay(1000);
                continue;   
            }
            
            break;
        }
        case MenuSelection::PlayerInfo :
            print_playerInfo(player);
            break;
        case MenuSelection::Inventory :
            clear_screen();
            player.get_inventory().list_inventory();
            std::cout << "무엇을 하시겠습니까? (0: 돌아가기 1. 아이템 장착) >>> ";
            std::cin >> e_select;
            if (e_select == 0)
                break;
            if (e_select == 1)
                equip_menu(player);
            break;
        case MenuSelection::Shop :
            break;
        case MenuSelection::Save :
        {
            int save_choice;
            SaveManager save_manager;
            std::cout << "정말 저장하시겠습니까?? 이전에 저장된 데이터가 삭제됩니다.(0 : 저장하지 않는다 1 : 저장한다)" << std::endl;
            std::cout << "입력 >>> ";
            std::cin >> save_choice;
            if (save_choice == 1) {
                save_manager.Save(player);
                std::cout << "저장 완료!!" << std::endl;
                delay(1500);
            }
            break;
        }
        case MenuSelection::Load :
        {
            int load_choice;
            LoadManager load_manager;
            std::cout << "정말 불러오시겠습니까?? 현재 데이터가 삭제됩니다.(0 : 불러오지 않는다 1 : 불러온다)" << std::endl;
            std::cout << "입력 >>> ";
            std::cin >> load_choice;
            if (load_choice == 1) {
                load_manager.Load(player);
                std::cout << "불러오기 완료!!" << std::endl;
                delay(1500);
            }
            break;
        }
        case MenuSelection::Exit :
            std::cout << "게임을 종료합니다." << std::endl;
            delay(1500);
            return;
        default :
            std::cout << "잘못된 입력!!!" << std::endl;
            break;
        }
    }
}