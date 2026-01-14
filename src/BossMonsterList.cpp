/*****************************************
 *  File_name : BossMonsterList.cpp
 *  보스 몬스터 리스트 관리
 ******************************************/
#include "BossMonsterList.h"
#include "WeaponList.h"
#include "ArmorList.h"
#include "MeterialList.h"
#include <iostream>

Dragon::Dragon() : Monster("드래곤", 1000, 100)
{
    base_stats.hp = 500;
    base_stats.mp = 5;
    base_stats.power = 60;
    base_stats.defend = 15;
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
void Dragon::special_pattern(Character &target)
{
    std::cout << "드 "; system.delay(300);
    std::cout << "레 "; system.delay(300);
    std::cout << "곤 "; system.delay(300);
    std::cout << "브 "; system.delay(300);
    std::cout << "레 "; system.delay(300);
    std::cout << "스 "; system.delay(300);
    for (int i = 0; i < 5; i++) {
            std::cout << "!";
            system.delay(300);
    }
    int dmg = target.take_damage(120);
    std::cout << "플레이어는 " << dmg << " 데미지를 입었다!!" << std::endl;   
}
