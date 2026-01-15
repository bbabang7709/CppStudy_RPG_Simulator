/*****************************************
 *  File_name : NormalMonsterList.h
 *  일반 몬스터 리스트 관리
 ******************************************/
#pragma once

#include "Monster.h"
#include "BattleSystem.h"
#include "DropItem.h"

enum class NormalMonsterType
{
    Exit = 0,
    Tutorial,
    Slime,
    Goblin,
    Orc
    //Random,
    
};

class Tutorial : public Monster
{
public:
    Tutorial();
    const std::vector<DropItem> &get_drop_table() const override;
    void take_turn(BattleContext &context) override;

private :
    std::vector<DropItem> drop_table;
};

class Slime : public Monster
{
public :
    Slime();
    const std::vector<DropItem> &get_drop_table() const override;
    void take_turn(BattleContext &context) override;

private :
    std::vector<DropItem> drop_table;
    void skill_regeneration();
    bool has_regenerated = false;
};

class Goblin : public Monster
{
public :
    Goblin();
    const std::vector<DropItem> &get_drop_table() const override;
    void take_turn(BattleContext &context) override;

private :
    std::vector<DropItem> drop_table;
    void double_slash(Player &target);
};

class Orc : public Monster
{
public :
    Orc();
    const std::vector<DropItem> &get_drop_table() const override;
    void take_turn(BattleContext &context) override;

private :
    std::vector<DropItem> drop_table;
};