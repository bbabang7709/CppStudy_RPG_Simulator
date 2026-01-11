/*****************************************
 *  File_name : BossMonsterList.h
 *  보스 몬스터 리스트 관리
 ******************************************/
#pragma once

#include "Monster.h"
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
    void special_pattern(Character &target);
    const std::vector<DropItem> &get_drop_table() const override;

private :
    std::vector<DropItem> drop_table;
    ItemFactory item_factory;
    Sys system;
};