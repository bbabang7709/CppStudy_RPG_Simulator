/*****************************************
 *  File_name : GameUI.cpp
 *  UI 출력 시스템 구현
 ******************************************/
#include "GameUI.h"
#include <iostream>
#include <chrono>

void GameUI::print_message(std::string msg)
{
    std::cout << msg << std::endl;
}

void GameUI::print_line()
{
    std::cout << "-----------------------------------------------------" << std::endl;
}

void GameUI::print_mainMenu()
{
    std::cout << "======== 무엇을 할까?? ========" << std::endl;
    std::cout << "1. 전투 시작" << std::endl;
    std::cout << "2. 플레이어 정보" << std::endl;
    std::cout << "3. 인벤토리 확인" << std::endl;
    std::cout << "4. 상업지구 입장" << std::endl;
    std::cout << "5. 저장하기" << std::endl;
    std::cout << "6. 불러오기" << std::endl;
    std::cout << "7. 종료" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_status(Monster &mon, Player &player)
{
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "[" << mon.get_name() << "]" << std::endl;
    std::cout << "HP : " << mon.get_hp() << " / " << mon.get_max_hp() << std::endl;
    std::cout << "MP : " << mon.get_mp() << std::endl << std::endl;
    std::cout << "[플레이어]" << std::endl;
    std::cout << "HP : " << player.get_hp() << " / " << player.get_max_hp() << std::endl;
    std::cout << "MP : " << player.get_mp() << std::endl << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
}
void GameUI::print_menu()
{
    std::cout << std::endl;
    std::cout << "무엇을 할까 ??" << std::endl;
    std::cout << "1. 일반공격 2. 특수공격 3. 회복   4. 도망" << std::endl; 
    std::cout << "선택 >>> ";
}

void GameUI::print_playerInfo(const Player &player)
{
    clear_screen();
    std::cout << "======== 플레이어 정보 ========" << std::endl;
    std::cout << "HP : " << player.get_hp() << " / " << player.get_max_hp() << std::endl;
    std::cout << "MP : " << player.get_mp() << " / " << player.get_max_mp() << std::endl;
    std::cout << "공격력 : " << player.get_power() << std::endl;
    std::cout << "방어력 : " << player.get_defend() << std::endl;
    std::cout << "활력 : " << player.get_vigor() << std::endl << std::endl;
    std::cout << "무기 : " << player.get_weapon_name();
    if (player.get_my_weapon()) {
        std::cout << " + " << player.get_my_weapon()->get_enhance_level();
    }
    std::cout << std::endl;
    std::cout << "방어구 : " << player.get_armor_name();
    if (player.get_my_armor()) {
        std::cout << " + " << player.get_my_armor()->get_enhance_level();
    }
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "계속하려면 Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void GameUI::print_monster_type_selection_menu()
{
    std::cout << "======== 몬스터 선택 ========" << std::endl;
    std::cout << "0. 돌아가기" << std::endl;
    std::cout << "1. 일반 몬스터" << std::endl;
    std::cout << "2. 보스 몬스터" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_normal_monster_selection_menu()
{
    std::cout << "======== 몬스터 선택 ========" << std::endl;
    std::cout << "0. 돌아가기" << std::endl;
    std::cout << "1. 슬라임" << std::endl;
    std::cout << "2. 고블린" << std::endl;
    std::cout << "3. 오크" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_boss_monster_selection_menu()
{
    std::cout << "======== 몬스터 선택 ========" << std::endl;
    std::cout << "0. 돌아가기" << std::endl;
    std::cout << "1. 드래곤" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_inventory_selection_menu()
{
    std::cout << "무엇을 하시겠습니까? (0: 돌아가기 1. 아이템 장착 2. 인벤토리 확장) >>> ";
}
void GameUI::print_equip_selection_menu()
{
    std::cout << "장착할 아이템의 번호를 입력하세요. (0 : 돌아가기) >>> ";
    
}
void GameUI::print_equip_success()
{
    std::cout << "아이템을 장착했습니다." << std::endl;
    delay(1000);
}
void GameUI::print_equip_fail()
{
    std::cout << "장착할 수 없는 아이템입니다." << std::endl;
    delay(1000);
}
void GameUI::print_expand_success()
{
    std::cout << "인벤토리 확장에 성공했습니다!!" << std::endl;
    delay(1000);
}
void GameUI::print_expand_fail()
{
    std::cout << "인벤토리 확장에 실패했습니다..." << std::endl;
    delay(1000);
}
void GameUI::print_get_gold(int drop_gold, int after_gold)
{
    std::cout << drop_gold << " 골드를 얻었다! (현재 골드 : " 
    << after_gold << ")" << std::endl << std::endl;
}
void GameUI::print_get_item(std::string item_name)
{
    std::cout << "아이템을 획득했다!!" << std::endl;
    std::cout << "획득한 아이템 : " << item_name << std::endl << std::endl;
}
void GameUI::print_save_menu()
{
    std::cout << "정말 저장하시겠습니까?? 이전에 저장된 데이터가 삭제됩니다." << std::endl 
                << "(0 : 저장하지 않는다 1 : 저장한다)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_save_success()
{
    std::cout << "저장 완료!!" << std::endl;
    delay(1000);
}
void GameUI::print_load_menu()
{
    std::cout << "정말 불러오시겠습니까?? 현재 진행한 데이터가 삭제됩니다." << std::endl
                << "(0 : 불러오지 않는다 1 : 불러온다)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_load_success()
{
    std::cout << "불러오기 완료!!" << std::endl;
    delay(1000);
}
void GameUI::print_exit_menu()
{
    std::cout << "게임을 종료합니다." << std::endl;
    delay(1500);
}
void GameUI::print_error_screen()
{
    std::cout << "잘못된 입력!!!" << std::endl;
    delay(1000);
}


void GameUI::print_commercialArea_menu()
{
    std::cout << "상업지구에 오신 것을 환영합니다!!!" << std::endl;
    delay(1000);
    std::cout << "무엇을 하시겠습니까??" << std::endl;
    std::cout << "(0 : 돌아가기 1 : 상점 2 : 대장간)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_shop_menu()
{
    clear_screen();
    std::cout << "상점에 오신 것을 환영합니다!!";
    delay(1000);

    std::cout << std::endl << std::endl << "무엇을 도와드릴까요???" << std::endl;
    std::cout << "(0 : 돌아가기 1 : 아이템 구매 2 : 아이템 판매)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_shop_buy_menu()
{
    std::cout << "어떤 아이템을 구매하시겠습니까?? (0 : 돌아가기)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_shop_buy_result(bool TF)
{
    if (TF)
        std::cout << "성공적으로 구매했습니다!!" << std::endl;
    else 
        std::cout << "구매에 실패했습니다..." << std::endl;
    delay(1000);
}
void GameUI::print_shop_sell_menu()
{
    std::cout << "어떤 아이템을 판매하시겠습니까?? (0 : 돌아가기)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_ask_sell_count()
{
    std::cout << "몇 개를 판매하시겠습니까?? (0 : 돌아가기)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_shop_sell_result(bool TF)
{
    if (TF)
        std::cout << "성공적으로 판매했습니다!!" << std::endl;
    else 
        std::cout << "판매에 실패했습니다..." << std::endl;
    delay(1000);
}
void GameUI::print_forge_menu()
{
    std::cout << "이곳은 대장간입니다. 무엇을 하시겠습니까?" << std::endl;
    std::cout << "(0 : 돌아가기 1 : 장비 강화)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_enhance_selection()
{
    std::cout << "강화할 장비를 선택하세요. (0 : 돌아가기)" << std::endl;
    std::cout << "입력 >>> ";
}
void GameUI::print_forge_result(EnhanceResult result)
{
    switch (result)
    {
    case EnhanceResult::Success :
        std::cout << "성공!!" << std::endl;
        break;
    case EnhanceResult::Failed :
        std::cout << "실패..." << std::endl;
        break;
    case EnhanceResult::MaxLevel :
        std::cout << "이미 최대로 강화했습니다." << std::endl;
        break;
    case EnhanceResult::noMeterial :
        std::cout << "필요한 재료가 부족합니다." << std::endl;
        break;
    case EnhanceResult::Destroyed :
        std::cout << "장비가 파괴되었습니다..." << std::endl;
        break;
    case EnhanceResult::Disable :
        std::cout << "강화할 수 없는 아이템입니다." << std::endl;
        break;
    case EnhanceResult::Error :
        std::cout << "오류가 발생했습니다." << std::endl;
        break;
    default : 
        break;
    }
    delay(1000);
}