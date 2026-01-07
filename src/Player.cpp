/*****************************************
 *  File_name : Player.cpp
 *  모험을 진행하는 플레이어 클래스
 ******************************************/
#include "Player.h"
#include <algorithm>
#include <iostream>

Player::Player()
{
    set_base_hp(100);
    set_base_mp(5);
    set_base_power(10);
    set_base_defend(5);
    set_base_vigor(30);

    set_max_hp(base_hp);
    set_max_mp(base_mp);
    set_power(base_power);
    set_defend(base_defend);
    set_vigor(base_vigor);

    reset_status();
}
Player::~Player() = default;

int Player::get_base_hp() const { return base_hp; }
int Player::get_base_mp() const { return base_mp; }
int Player::get_base_power() const { return base_power; }
int Player::get_base_defend() const { return base_defend; }
int Player::get_base_vigor() const { return base_vigor; }

void Player::set_base_hp(int _hp)
{
    base_hp = _hp;
}
void Player::set_base_mp(int _mp)
{
    base_mp = _mp;
}
void Player::set_base_power(int _power)
{
    base_power = _power;
}
void Player::set_base_defend(int _defend)
{
    base_defend = _defend;
}
void Player::set_base_vigor(int _vigor)
{
    base_vigor = _vigor;
}

Weapon *Player::get_my_weapon() const
{
    return my_weapon.get();
}

Armor *Player::get_my_armor() const
{
    return my_armor.get();
}

std::string Player::get_weapon_name() const
{
    return my_weapon ? my_weapon->get_name() : "없음";
}

std::string Player::get_armor_name() const
{
    return my_armor ? my_armor->get_name() : "없음";
}

void Player::equip_item(std::unique_ptr<Item> item)
{
    switch(item->get_type())
    {
        case ItemType::Weapon :
        {
            auto weapon = std::unique_ptr<Weapon>(dynamic_cast<Weapon *>(item.release()));
            if (!weapon)
                return;
            if (my_weapon)
                get_inventory().add_item(unequip_Weapon());
            set_max_hp(max_hp + weapon->get_weapon_hp());
            set_max_mp(max_mp + weapon->get_weapon_mp());
            set_power(power + weapon->get_weapon_power());
            set_defend(defend + weapon->get_weapon_defend());
            set_vigor(vigor + weapon->get_weapon_vigor());
            my_weapon = std::move(weapon);
            break;
        }
        case ItemType::Armor :
        {
            auto armor = std::unique_ptr<Armor>(dynamic_cast<Armor *>(item.release()));
            if (!armor)
                return;
            if (my_armor)
                get_inventory().add_item(unequip_Armor());
            set_max_hp(max_hp + armor->get_armor_hp());
            set_max_mp(max_mp + armor->get_armor_mp());
            set_power(power + armor->get_armor_power());
            set_defend(defend + armor->get_armor_defend());
            set_vigor(vigor + armor->get_armor_vigor());
            my_armor = std::move(armor);
            break;
        }
        default :
        {
            std::cout << "착용할 수 없는 아이템입니다." << std::endl;
            break;
        }
    }
}

std::unique_ptr<Weapon> Player::unequip_Weapon()
{
    if (!my_weapon) {
        std::cout << "장착된 무기가 없습니다." << std::endl;
        return nullptr;
    } else {
        int total_power = power - my_weapon->get_weapon_power();
        set_power(total_power);
        return std::move(my_weapon);
    }
}

std::unique_ptr<Armor> Player::unequip_Armor()
{
    if (!my_armor) {
        std::cout << "장착된 방어구가 없습니다." << std::endl;
        return nullptr;
    } else {
        int total_defend = defend - my_armor->get_armor_defend();
        set_defend(total_defend);
        return std::move(my_armor);
    }
}

void Player::attack(Character &target)
{
    target.take_damage(power);
}

Inventory &Player::get_inventory() { return inventory; }