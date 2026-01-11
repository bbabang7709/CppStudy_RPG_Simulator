/*****************************************
 *  File_name : Monster.cpp
 *  Player에 대적하는 Monster 클래스
 ******************************************/
#include "Monster.h"
#include <iostream>
#include <algorithm>


Monster::Monster(std::string name, int drop_gold) : name(name), drop_gold(drop_gold) {}

Monster::~Monster() = default;

std::string Monster::get_name() const
{
    return name;
}
int Monster::get_drop_gold() const
{
    return drop_gold;
}
void Monster::attack(Character &target)
{
    int dmg = target.take_damage(power);
    std::cout << "몬스터의 공격!!" << std::endl;
    std::cout << "플레이어는 " << dmg << " 데미지를 입었다!!" << std::endl;
}
void Monster::strong_attack(Character &target)
{
    int dmg = target.take_damage(power * 1.7);
    std::cout << "몬스터의 강공격!!" << std::endl;
    std::cout << "플레이어는 " << dmg << " 데미지를 입었다!!" << std::endl;
}
void Monster::defend()
{
    int def = get_defend() + 2;
    int pow = get_power() - 2;
    set_defend(def);
    set_power(pow);
    std::cout << "몬스터가 방어자세를 취했다!!" << std::endl;
    std::cout << "방어가 올랐지만, 공격력이 내려갔다!" << std::endl;
}
void Monster::heal()
{
    int heal_point = get_vigor();
    int cur_hp = get_hp();
    set_hp(cur_hp + heal_point);
    std::cout << "몬스터가 " << heal_point << " HP를 회복했다!!" << std::endl;
}
void Monster::idle()
{
    std::cout << "몬스터는 멍하니 서 있다......" << std::endl;
}