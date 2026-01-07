/*****************************************
 *  File_name : PlayerController.h
 *  캐릭터의 모든 행동 관리
 ******************************************/
#pragma once

class Character;
class Player;

class PlayerController
{
public :
    PlayerController();
    bool normal_attack(Player &player, Character &target);
    bool special_attack(Player &player, Character &target);
    bool heal(Player &player);
    bool escape(bool *is_escaped);
    void reset_status(Player &player);
};