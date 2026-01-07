/*****************************************
 *  File_name : Monster.h
 *  Player에 대적하는 Monster 클래스
 ******************************************/
#pragma once
#include "Character.h"
#include "DropItem.h"
#include "MonsterAI.h"

#include <string>
#include <vector>
#include <functional>
#include <memory>

class Monster : public Character
{
public :
    Monster(std::string name, int drop_gold);
    virtual ~Monster();

    std::string get_name() const;
    int get_drop_gold() const;
    void attack(Character &target);
    virtual void strong_attack(Character &target);
    void defend();
    void heal();
    void idle();

    virtual const std::vector<DropItem> &get_drop_table() const = 0;

protected :
    std::string name;
    int drop_gold;
};