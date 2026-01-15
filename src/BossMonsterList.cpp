/*****************************************
 *  File_name : BossMonsterList.cpp
 *  보스 몬스터 리스트 관리
 ******************************************/
#include "BossMonsterList.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "MeterialList.h"
#include "Random.h"
#include <iostream>

Dragon::Dragon() : Monster("드래곤", 5000, 500)
{
    base_stats.hp = 4000;
    base_stats.mp = 10;
    base_stats.power = 180;
    base_stats.defend = 60;
    base_stats.vigor = 30;
    base_stats.cri = 0;
    base_stats.speed = 0;

    recalc_final_stats();
    reset_condition();

    drop_table = {
        { 41, ItemID::ReinforceStone },
        {40, ItemID::DragonScale},
        {10, ItemID::SoulStone_Dragon},
        {3, ItemID::DragonArmor},
        {1, ItemID::DragonSpear}
    };
}
const std::vector<DropItem> &Dragon::get_drop_table() const
{
    return drop_table;
}
void Dragon::take_turn(BattleContext &context)
{
    int roll = Random::range(1, 100);
    if (roll <= 70) {
        this->basic_attack(context.player);
    } else if (roll <= 90) {
        this->basic_defend();
    } else {
        this->dragon_breathe(context.player);
    }
}


void Dragon::dragon_breathe(Player &target)
{
    std::cout << "드 "; Sys::delay(300);
    std::cout << "레 "; Sys::delay(300);
    std::cout << "곤 "; Sys::delay(300);
    std::cout << "브 "; Sys::delay(300);
    std::cout << "레 "; Sys::delay(300);
    std::cout << "스 "; Sys::delay(300);
    for (int i = 0; i < 5; i++) {
            std::cout << "!";
            Sys::delay(300);
    }
    int dmg = target.take_damage(this->get_final_stats().power * 5);
    std::cout << "플레이어는 " << dmg << " 데미지를 입었다!!" << std::endl;   
}