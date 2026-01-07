/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#include "Character.h"
#include <algorithm>

class Character;

Character::Character() : hp(100), max_hp(100),
                         mp(0), max_mp(5),
                         power(5), defend(0), vigor(0)
{};
Character::~Character() = default;

int Character::get_hp() const { return hp; }
int Character::get_max_hp() const { return max_hp; }
int Character::get_mp() const { return mp; }
int Character::get_max_mp() const { return max_mp; }
int Character::get_power() const { return power; }
int Character::get_defend() const { return defend; }
int Character::get_vigor() const { return vigor; }
void Character::set_hp(int _hp)
{
    hp = std::clamp(_hp, 0, max_hp);
}
void Character::set_max_hp(int _max_hp)
{
    max_hp = _max_hp;
}
void Character::set_mp(int _mp)
{
    mp = std::clamp(_mp, 0, max_mp);
}
void Character::set_max_mp(int _max_mp)
{
    max_mp = _max_mp;
}
void Character::set_power(int _power)
{
    power = std::max(5, _power);
}
void Character::set_defend(int _defend)
{
    defend = std::max(0, _defend);
}
void Character::set_vigor(int _vigor)
{
    vigor = std::max(0, _vigor);
}
void Character::reset_status()
{
    hp = max_hp;
    mp = 0;
}
int Character::take_damage(int damage)
{
    int dmg = std::max((damage - defend), 5);
    set_hp(hp - dmg);
    return dmg;
}