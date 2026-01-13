/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#pragma once

#include "StatBlock.h"

class Character
{
public :
    Character();
    virtual ~Character();

    int get_hp() const;
    int get_max_hp() const;
    int get_mp() const;
    int get_max_mp() const;
    int get_power() const;
    int get_defend() const;
    int get_vigor() const;
    int get_cri() const;
    int get_speed() const;
    
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);
    void set_mp(int _mp);
    void set_max_mp(int _max_mp);
    void set_power(int _power);
    void set_defend(int _defend);
    void set_vigor(int _vigor);
    void set_cri(int _cri);
    void set_speed(int _speed);

    StatBlock get_base_stats() const;
    StatBlock get_final_stats() const;
    int get_cur_hp() const;
    int get_cur_mp() const;

    virtual void reset_condition();
    int take_damage(int damage);

protected :
    StatBlock base_stats;
    StatBlock final_stats;
    int cur_hp;
    int cur_mp;

    virtual void recalc_final_stats();
};