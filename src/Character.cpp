/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#include "Character.h"
#include <algorithm>

class Character;

Character::Character()
{
    base_stats.hp = 100;
    base_stats.mp = 0;
    base_stats.power = 0;
    base_stats.defend = 0;
    base_stats.vigor = 0;
    base_stats.cri = 0;
    base_stats.speed = 0;

    recalc_final_stats();
};
Character::~Character() = default;

int Character::get_hp() const { return cur_hp; }
int Character::get_max_hp() const { return final_stats.hp; }
int Character::get_mp() const { return cur_mp; }
int Character::get_max_mp() const { return final_stats.mp; }
int Character::get_power() const { return final_stats.power; }
int Character::get_defend() const { return final_stats.defend; }
int Character::get_vigor() const { return final_stats.vigor; }
int Character::get_cri() const { return final_stats.cri; }
int Character::get_speed() const { return final_stats.speed; }
void Character::set_hp(int _hp)
{
    cur_hp = std::clamp(_hp, 0, final_stats.hp);
}
void Character::set_max_hp(int _max_hp)
{
    final_stats.hp =  _max_hp;
}
void Character::set_mp(int _mp)
{
    cur_mp = std::clamp(_mp, 0, final_stats.mp);
}
void Character::set_max_mp(int _max_mp)
{
    final_stats.mp = _max_mp;
}
void Character::set_power(int _power)
{
    final_stats.power = std::max(5, _power);
}
void Character::set_defend(int _defend)
{
    final_stats.defend = std::max(0, _defend);
}
void Character::set_vigor(int _vigor)
{
    final_stats.vigor = std::max(0, _vigor);
}
void Character::set_cri(int _cri)
{
    final_stats.cri = std::max(0, _cri);
}
void Character::set_speed(int _speed)
{
    final_stats.speed = std::max(0, _speed);
}

StatBlock Character::get_base_stats() const { return base_stats; }
StatBlock Character::get_final_stats() const { return final_stats; }

int Character::get_cur_hp() const { return cur_hp; }
int Character::get_cur_mp() const { return cur_mp; }

void Character::reset_condition()
{
    cur_hp = final_stats.hp;
    cur_mp = 0;
}
int Character::take_damage(int damage)
{
    int dmg = std::max((damage - final_stats.defend), 5);
    set_hp(cur_hp - dmg);
    return dmg;
}

void Character::recalc_final_stats()
{
    final_stats = base_stats;
}