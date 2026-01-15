/*****************************************
 *  File_name : NormalWeapon.cpp
 *  가장 기본적인 Weapon
 ******************************************/
#include "WeaponList.h"
#include <iostream>

NormalWeapon::NormalWeapon() : Weapon(ItemDatabase::get(ItemID::NormalWeapon))
{
    flat_stats.power = 7;
    cost = 2;
}
void NormalWeapon::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "강력 회전 공격!!" << std::endl;
        int dmg = target.take_damage(1.2 * user.get_power());
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}

SlimeSword::SlimeSword() : Weapon(ItemDatabase::get(ItemID::SlimeSword))
{
    flat_stats.power = 20;
    flat_stats.vigor = 20;
    flat_stats.cri = 10;
    cost = 3;
}
void SlimeSword::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "슬라임 슬래시!!" << std::endl;
        int dmg = target.take_damage(1.5 * user.get_power());
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}

PowerGauntlet::PowerGauntlet() : Weapon(ItemDatabase::get(ItemID::PowerGauntlet))
{
    flat_stats.power = 40;
    flat_stats.defend = 8;
    flat_stats.hp = 40;
    flat_stats.cri = 10;
    cost = 5;
}
void PowerGauntlet::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "파워 스트라이크!!" << std::endl;
        int dmg = target.take_damage(1.8 * user.get_power());
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}

DragonSpear::DragonSpear() : Weapon(ItemDatabase::get(ItemID::DragonSpear))
{
    flat_stats.hp = 100;
    flat_stats.mp = 7;
    flat_stats.power = 80;
    flat_stats.defend = 15;
    flat_stats.vigor = 20;
    flat_stats.cri = 15;
    cost = 7;
}
void DragonSpear::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "용성락";
        for (int i = 0 ; i < 6 ; i++) {
            std::cout << ".";
            system.delay(100);
        }
        std::cout << "!" << std::endl;
        system.delay(1000);
        int dmg = target.take_damage(3 * user.get_power());
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}