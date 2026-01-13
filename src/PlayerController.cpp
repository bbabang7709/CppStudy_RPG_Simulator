/*****************************************
 *  File_name : PlayerController.cpp
 *  캐릭터의 모든 행동 관리
 ******************************************/
#include "Character.h"
#include "Player.h"
#include "PlayerController.h"

#include <iostream>

PlayerController::PlayerController() {}

bool PlayerController::normal_attack(Player &player, Character &target)
{
    int dmg = target.take_damage(player.get_final_stats().power);
    std::cout << "플레이어의 일반 공격!!" << std::endl;
    std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    return true;
}
bool PlayerController::special_attack(Player &player, Character &target)
{
    if (!(player.get_my_weapon())) {
        std::cout << "장착한 무기가 없다!!" << std::endl;
        return false;
    }
    if (player.get_mp() < player.get_my_weapon()->get_cost()) {
        std::cout << "MP가 부족하다.( " << player.get_my_weapon()->get_cost() << " MP 필요)" << std::endl;
        return false;
    }
    player.get_my_weapon()->special_attack(player, target);
    return true;
}
bool PlayerController::heal(Player &player)
{
    auto stats = player.get_final_stats();
    int heal_point = stats.vigor;
    int cur_hp = player.get_cur_hp();
    player.set_hp(std::min((cur_hp + heal_point), player.get_max_hp()));
    std::cout << "플레이어는 " << player.get_cur_hp() - cur_hp << " HP를 회복했다!" << std::endl; 
    return true;
}
bool PlayerController::escape(bool *is_escaped)
{
    *is_escaped = true;
    return true;
}

