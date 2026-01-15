/*****************************************
 *  File_name : BattleSystem.h
 *  Monster과의 전투 진행을 담당
 ******************************************/
#pragma once
#include "Character.h"
#include "Player.h"
#include "PlayerController.h"
#include "Monster.h"
#include "MonsterAI.h"
#include "Sys.h"

class GameUI;

struct BattleContext
{
    Player &player;
    Monster &monster;
    int currentTurn;

    BattleContext(Player &p, Monster &m, int turn = 0) 
                : player(p), monster(m), currentTurn(turn) {} 
};

class BattleSystem : public Sys
{
public :
    BattleSystem(Player &p, PlayerController &p_controller, Monster &m, MonsterAI &ai, GameUI &UI);
    int get_turn();
    void start_battle();
    static int calculate_damage(const Player &player);

private :
    Player &player;
    PlayerController &p_controller;
    Monster &monster;
    MonsterAI &ai;
    GameUI &UI;
    int turn;
    bool is_escaped;
    void player_turn();
    void playerPhase();

    void monster_turn();
    void monsterPhase();
    
    bool is_battle_end();
    void reward(Monster &monster, Player &player);
};

