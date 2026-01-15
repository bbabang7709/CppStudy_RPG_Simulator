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

class Character;
class Player;

struct BattleContext;

class Monster : public Character
{
public :
    Monster(std::string name, int drop_gold, int exp);
    virtual ~Monster();

    std::string get_name() const;
    int get_drop_gold() const;
    int get_exp() const;

    virtual void take_turn(BattleContext &context) = 0;
    virtual void basic_attack(Player &target);
    virtual void basic_defend();
    virtual void wait_turn(std::string msg);

    virtual const std::vector<DropItem> &get_drop_table() const = 0;

protected :
    int drop_gold;
    int exp;

    void print_msg(std::string msg);
};