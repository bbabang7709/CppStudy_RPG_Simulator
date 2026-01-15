/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#include "Character.h"
#include "Sys.h"
#include <iostream>
#include <algorithm>

class Character;

Character::Character(std::string name) : name(name)
{
    base_stats.hp = 100;
    base_stats.mp = 0;
    base_stats.power = 0;
    base_stats.defend = 0;
    base_stats.vigor = 0;
    base_stats.cri = 5;
    base_stats.criDamage = 1.5f;
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
float Character::get_criDamage() const { return final_stats.criDamage; }
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
void Character::set_criDamage(float _criDamage)
{
    final_stats.criDamage = std::max(1.5f, _criDamage);
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
    float damage_multiplier = 100.0f / (100.0f + final_stats.defend);
    int final_damage = damage * damage_multiplier;

    // 최소 데미지 보정
    if (final_damage < 5)
        final_damage = 5;

    cur_hp -= final_damage;

    std::cout << final_damage << " 데미지!!" << std::endl;
    Sys::delay(1000);

    return final_damage;
}

void Character::add_buff(const Buff &new_buf)
{
    auto it = std::find_if(active_buffs.begin(), active_buffs.end(), [&](const Buff &b) { return b.buff_name == new_buf.buff_name; });
    if (it != active_buffs.end()) {
        it->duration = std::max(it->duration, new_buf.duration);
    } else {
        active_buffs.push_back(new_buf);
    }

    recalc_final_stats();
}

void Character::update_buffs()
{
    bool changed = false;
    for (auto &buf : active_buffs) {
        if (buf. duration > 0) {
            if (buf.tick_hp != 0) {
                this->cur_hp += buf.tick_hp;
                if (this->cur_hp > this->get_max_hp()) {
                    this->cur_hp = this->get_max_hp();
                }
                std::cout << "[" << name << "]" << buf.buff_name << " 효과로 " << buf.tick_hp << " HP ";
                if (buf.tick_hp > 0) {
                    std::cout << "회복";
                } else {
                    std::cout << "감소";
                }
                std::cout << std::endl;
                Sys::delay(1000);
            }
            buf.tick();
            changed = true;
        }
    }

    auto origianl_size = active_buffs.size();
    active_buffs.erase(
        std::remove_if(active_buffs.begin(), active_buffs.end(), [](const Buff &b) { return b.duration <= 0; }), active_buffs.end()   
    );

    if (changed || origianl_size != active_buffs.size()){
        recalc_final_stats();
    }
}

// private
void Character::recalc_final_stats()
{
    final_stats = base_stats;
    for (auto &buf : active_buffs) {
        final_stats += buf.effect;
    }
}