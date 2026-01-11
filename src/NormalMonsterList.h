/*****************************************
 *  File_name : NormalMonsterList.h
 *  일반 몬스터 리스트 관리
 ******************************************/
#pragma once

#include "Monster.h"
#include "DropItem.h"

enum class NormalMonsterType
{
    Exit = 0,
    Slime,
    Goblin,
    Orc
    //Random,
    
};

class Slime : public Monster
{
public :
    Slime();
    const std::vector<DropItem> &get_drop_table() const override;

private :
    std::vector<DropItem> drop_table;
};

class Goblin : public Monster
{
public :
    Goblin();
    const std::vector<DropItem> &get_drop_table() const override;

private :
    std::vector<DropItem> drop_table;
    
};

class Orc : public Monster
{
public :
    Orc();
    const std::vector<DropItem> &get_drop_table() const override;

private :
    std::vector<DropItem> drop_table;
};