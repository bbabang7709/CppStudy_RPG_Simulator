/*****************************************
 *  File_name : NormalWeapon.cpp
 *  가장 기본적인 Weapon
 ******************************************/
#include "WeaponList.h"
#include <iostream>

NormalWeapon::NormalWeapon(const std::string name, ItemType type, int price) : Weapon(name, type, price)
{
    set_id(ItemId::NormalWeapon);
    set_weapon_power(10);
    set_weapon_defend(0);
    set_cost(2);
}
void NormalWeapon::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "강력 회전 공격!!" << std::endl;
        int dmg = target.take_damage(2 * weapon_power);
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}

SlimeSword::SlimeSword(const std::string name, ItemType type, int price) : Weapon(name, type, price)
{
    set_id(ItemId::SlimeSword);
    set_weapon_power(30);
    set_weapon_defend(3);
    set_weapon_vigor(20);
    set_cost(3);
}
void SlimeSword::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "슬라임 슬래시!!" << std::endl;
        int dmg = target.take_damage(2 * weapon_power);
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}

PowerGauntlet::PowerGauntlet(const std::string name, ItemType type, int price) : Weapon(name, type, price)
{
    set_id(ItemId::PowerGauntlet);
    set_weapon_power(45);
    set_weapon_defend(8);
    set_weapon_hp(30);
    set_cost(5);
}
void PowerGauntlet::special_attack(Player &user, Character &target)
{
    int cur_mp = user.get_mp();
    if (cur_mp >= cost) {
        user.set_mp(cur_mp - cost);
        std::cout << "파워 스트라이크!!" << std::endl;
        int dmg = target.take_damage(3 * weapon_power);
        std::cout << "몬스터는 " << dmg << " 데미지를 입었다!!" << std::endl;
    } else {
        std::cout << "특수 기술을 사용할 MP가 부족합니다. (" << cost << " MP 필요)" << std::endl;
    }
    std::cout << std::endl;
}