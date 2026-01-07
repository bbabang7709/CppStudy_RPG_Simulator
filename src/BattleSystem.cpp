/*****************************************
 *  File_name : BattleSystem.cpp
 *  Monster과의 전투 진행을 담당
 ******************************************/
#include "BattleSystem.h"
#include "PlayerAction.h"
#include "MonsterAction.h"
#include "Random.h"
#include "ItemFactory.h"

#include <iostream>
#include <chrono>
#include <thread>

BattleSystem::BattleSystem(Player &p, PlayerController &p_controller, Monster &m, MonsterAI &ai) : player(p), p_controller(p_controller),
                                                                                                   monster(m), ai(ai),
                                                                                                   turn(0), is_escaped(false) {};

int BattleSystem::get_turn() { return turn; }

void BattleSystem::start_battle()
{
    clear_screen();
    std::cout << "앗, 몬스터가 나타났다!!";

    delay(1500);

    while (true)
    {
        clear_screen();
        
        turn++;
        player_turn();
        if (is_escaped) {
            std::cout << "무사히 도망쳤다..." << std::endl;
            delay(2000);
            break;
        }
        if (is_battle_end()) {
            std::cout << "몬스터가 쓰러졌다!!" << std::endl;
            reward(monster, player);
            delay(2000);
            break;
        }
        player.set_mp(std::min((player.get_mp() + 1), player.get_max_mp()));

        monster_turn();
        if (is_battle_end()) {
            std::cout << "이런... 눈 앞이 캄캄해진다..." << std::endl;
            delay(2000);
            break;
        }
        monster.set_mp(std::min((monster.get_mp() + 1), monster.get_max_mp()));
    }
}

void BattleSystem::player_turn()
{
    int reply;
    bool is_turn_end;
    while (true)
    {
        is_turn_end = true;
        clear_screen();
        print_status(monster, player);
        print_menu();
        if (!(std::cin >> reply)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "잘못된 입력!!" << std::endl;
            delay(1000);
            continue;
        }
        std::cout << std::endl;
        PlayerAction action = static_cast<PlayerAction>(reply);

        switch(action)
        {
        case PlayerAction::Attack :
            is_turn_end = p_controller.normal_attack(player, monster);
            break;
        case PlayerAction::Special :
            is_turn_end = p_controller.special_attack(player, monster);
            break;
        case PlayerAction::Heal :
            is_turn_end = p_controller.heal(player);
            break;
        case PlayerAction::Escape :
            is_turn_end = p_controller.escape(&is_escaped);
            return;
        default :
            std::cout << "잘못된 입력!!" << std::endl;
            break;
        }
        delay(1000);
        std::cout << std::endl;
        if (is_turn_end)
            break;
        else
            clear_screen();
    }
}
void BattleSystem::monster_turn()
{
    MonsterAction action = ai.decide_action(monster);
    switch(action)
    {
    case MonsterAction::Attack :
        monster.attack(player);
        break;
    case MonsterAction::StrongAttack :
        monster.strong_attack(player);
        break;
    case MonsterAction::Defend :
        monster.defend();
        break;
    case MonsterAction::Heal :
        monster.heal();
        break;
    case MonsterAction::Idle :
        monster.idle();
        break;
    }
    delay(1000);
    std::cout << std::endl;
}

bool BattleSystem::is_battle_end()
{
    bool _is;
    (monster.get_hp() <= 0 || player.get_hp() <= 0) ? _is = true : _is = false;
    return _is;
}

void BattleSystem::reward(Monster &monster, Player &player)
{
    ItemFactory itemFactory;
    int cur_gold = player.get_inventory().show_gold();
    player.get_inventory().earn_gold(monster.get_drop_gold());
    std::cout << monster.get_drop_gold() << " 골드를 얻었다! (현재 골드 : " << cur_gold + monster.get_drop_gold() << ")" << std::endl;
    for (const auto &drop : monster.get_drop_table())
    {        
        int roll = Random::range(1, 100);
        if (roll <= drop.chance)
        {
            auto item = itemFactory.create(drop.create()->get_id());
            std::cout << "아이템을 획득했다!!" << std::endl;
            std::cout << "획득한 아이템 : " << item->get_name() << std::endl;
            player.get_inventory().add_item(std::move(item));
            break;
        }
    }
}