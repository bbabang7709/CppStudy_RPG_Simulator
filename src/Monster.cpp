/*****************************************
 *  File_name : Monster.cpp
 *  Player에 대적하는 Monster 클래스
 ******************************************/

#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"
#include <iostream>
#include <algorithm>

Monster::Monster(std::string name, int drop_gold, int exp) : Character(name), drop_gold(drop_gold), exp(exp) {}

Monster::~Monster() = default;

std::string Monster::get_name() const { return name; }
int Monster::get_drop_gold() const { return drop_gold; }
int Monster::get_exp() const { return exp; }

void Monster::basic_attack(Player &target) 
{
    std::cout << "[" << name << "]의 일반 공격!!" << std::endl;
    Sys::delay(1000);
    target.take_damage(this->get_power());
}
void Monster::basic_defend()
{
    std::cout << "[" << name << "]이 방어 자세를 취합니다." << std::endl;
    this->add_buff({"방어", BuffType::Buff, StatBlock{.defend = 10}, 0, 1});
    Sys::delay(1000);
}
void Monster::wait_turn(std::string msg)
{
    std::cout << "[" << name << "]이(가) " << msg << std::endl;
    Sys::delay(1000);
}

// protected
void Monster::print_msg(std::string msg)
{
    std::cout << "[" << name << "]이(가) " << msg << std::endl;
    Sys::delay(1000);
}