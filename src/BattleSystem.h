/*****************************************
 *  File_name : BattleSystem.h
 *  Monster과의 전투 진행을 담당
 ******************************************/
#pragma once
#include "Player.h"
#include "PlayerController.h"
#include "Monster.h"
#include "MonsterAI.h"
#include "Sys.h"


class Player;
class PlayerController;
class Monster;
class MonsterAI;
class Sys;

class BattleSystem : public Sys
{
public :
    BattleSystem(Player &p, PlayerController &p_controller, Monster &m, MonsterAI &ai);
    int get_turn();
    void start_battle();

private :
    Player &player;
    PlayerController &p_controller;
    Monster &monster;
    MonsterAI &ai;
    int turn;
    bool is_escaped;
    void player_turn();
    void monster_turn();
    bool is_battle_end();
    void reward(Monster &monster, Player &player);
};

