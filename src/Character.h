/*****************************************
 *  File_name : Character.h
 *  Player, Monster 클래스의 공통 스탯 & 행위
 ******************************************/
#pragma once

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
    
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);
    void set_mp(int _mp);
    void set_max_mp(int _max_mp);
    void set_power(int _power);
    void set_defend(int _defend);
    void set_vigor(int _vigor);
    

    virtual void reset_status();
    int take_damage(int damage);

protected :
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int power;
    int defend;
    int vigor;
};