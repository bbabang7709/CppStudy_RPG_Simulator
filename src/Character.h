/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#pragma once

#include "StatPointType.h"
#include "StatBlock.h"
#include "Buff.h"
#include <string>
#include <vector>

class Character
{
public :
    Character(std::string name);
    virtual ~Character();

    int get_hp() const;
    int get_max_hp() const;
    int get_mp() const;
    int get_max_mp() const;
    int get_power() const;
    int get_defend() const;
    int get_vigor() const;
    int get_cri() const;
    float get_criDamage() const;
    int get_speed() const;
    
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);
    void set_mp(int _mp);
    void set_max_mp(int _max_mp);
    void set_power(int _power);
    void set_defend(int _defend);
    void set_vigor(int _vigor);
    void set_cri(int _cri);
    void set_criDamage(float _criDamage);
    void set_speed(int _speed);

    StatBlock get_base_stats() const;
    StatBlock get_buf_stats() const;
    StatBlock get_final_stats() const;

    void reset_buf_stats();
    
    int get_cur_hp() const;
    int get_cur_mp() const;

    virtual void reset_condition();
    int take_damage(int damage);

    void add_buff(const Buff &new_buf);
    void update_buffs();


protected :
    std::string name;
    int ATK;
    int DEF;
    int max_HP;
    int max_MP;

    StatBlock base_stats;
    StatBlock final_stats;
    
    std::vector<Buff> active_buffs;

    int cur_hp;
    int cur_mp;

    virtual void recalc_final_stats();
};