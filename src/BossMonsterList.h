/*****************************************
 *  File_name : BossMonsterList.h
 *  보스 몬스터 리스트 관리
 ******************************************/
#pragma once

#include "Monster.h"
#include "BattleSystem.h"
#include "ItemFactory.h"
#include "Sys.h"

enum class BossMonsterType
{
    Exit = 0,
    Dragon
};

class Dragon : public Monster
{
public :
    Dragon();
    const std::vector<DropItem> &get_drop_table() const override;
    void take_turn(BattleContext &context) override;

private :
    std::vector<DropItem> drop_table;
    ItemFactory item_factory;
    void dragon_breathe(Player &target);
};