/*****************************************
 *  File_name : Player.cpp
 *  모험을 진행하는 플레이어 클래스
 ******************************************/
#include "Player.h"
#include "Random.h"
#include "InventoryExpand.h"
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

void Player::attack(Character &target)
{
    target.take_damage(power);
}

void Player::reset_player()
{
    set_hp(base_hp);
    set_mp(0);
    set_defend(base_defend);
    set_power(base_power);
    set_vigor(base_vigor);
    if (get_my_weapon())
        unequip_Weapon();
    if (get_my_armor())
        unequip_Armor();
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

bool Player::equip_item(std::unique_ptr<Item> item)
{
    if (!item) return false;
    switch(item->get_type())
    {
        case ItemType::Weapon :
        {
            auto weapon = std::unique_ptr<Weapon>(dynamic_cast<Weapon *>(item.release()));
            if (!weapon)
                return false;
            if (my_weapon)
                get_inventory().add_item(unequip_Weapon());
            set_max_hp(max_hp + weapon->get_weapon_hp());
            set_max_mp(max_mp + weapon->get_weapon_mp());
            set_power(power + weapon->get_weapon_power() + weapon->get_enhance_level() * 5);
            set_defend(defend + weapon->get_weapon_defend());
            set_vigor(vigor + weapon->get_weapon_vigor());
            my_weapon = std::move(weapon);
            break;
        }
        case ItemType::Armor :
        {
            auto armor = std::unique_ptr<Armor>(dynamic_cast<Armor *>(item.release()));
            if (!armor)
                return false;
            if (my_armor)
                get_inventory().add_item(unequip_Armor());
            set_max_hp(max_hp + armor->get_armor_hp());
            set_max_mp(max_mp + armor->get_armor_mp());
            set_power(power + armor->get_armor_power());
            set_defend(defend + armor->get_armor_defend() + armor->get_enhance_level() * 3);
            set_vigor(vigor + armor->get_armor_vigor());
            my_armor = std::move(armor);
            break;
        }
        case ItemType::Meterial :
            return false;
        default :
            return false;
    }
    return true;
}
bool Player::try_equip_inventory_item(int slot_index)
{
    ItemSlot slot = inventory.take_slot(slot_index, 1);
    if (!slot.item)
        return false;
    
    ItemID id = slot.item->get_id();

    if (equip_item(std::move(slot.item))) {
        return true;
    } else {
        slot.item = ItemFactory::create(id);
        inventory.add_slot(std::move(slot));
        return false;
    }
}

std::unique_ptr<Weapon> Player::unequip_Weapon()
{
    if (!my_weapon) {
        std::cout << "장착된 무기가 없습니다." << std::endl;
        return nullptr;
    } else {
        set_max_hp(max_hp - my_weapon->get_weapon_hp());
        set_max_mp(max_mp - my_weapon->get_weapon_mp());
        set_power(power - my_weapon->get_weapon_power() - my_weapon->get_enhance_level() * 5);
        set_defend(defend - my_weapon->get_weapon_defend());
        set_vigor(vigor - my_weapon->get_weapon_vigor());

        return std::move(my_weapon);
    }
}

std::unique_ptr<Armor> Player::unequip_Armor()
{
    if (!my_armor) {
        std::cout << "장착된 방어구가 없습니다." << std::endl;
        return nullptr;
    } else {
        set_max_hp(max_hp - my_armor->get_armor_hp());
        set_max_mp(max_mp - my_armor->get_armor_mp());
        set_power(power - my_armor->get_armor_power());
        set_defend(defend - my_armor->get_armor_defend() - my_armor->get_enhance_level() * 3);
        set_vigor(vigor - my_armor->get_armor_vigor());
        return std::move(my_armor);
    }
}

EnhanceResult Player::enhance_item(int inventory_index)
{
    int index = inventory_index - 1;
    int meterial_index = -1;
    int roll;

    auto &slots = inventory.get_slots();
    if (index < 0 || index > (int)slots.size())
        return EnhanceResult::Error;

    auto &slot = slots[index];
    
    auto target_item = dynamic_cast<Equipment *>(slot.item.get());
    if (!target_item)
        return EnhanceResult::Error;
    if (!target_item->can_enhance())
        return EnhanceResult::MaxLevel;

    for (int i = 0; i < (int)slots.size(); i++) {
        if (slots[i].item && slots[i].item->get_id() == ItemID::ReinforceStone) {
            meterial_index = i;
            break;
        }
    }
    if (meterial_index == -1) 
        return EnhanceResult::noMeterial;

    auto &meterial_slot = slots[meterial_index];

    auto rule = EnhanceSystem::get_rule(target_item->get_enhance_level());
    
    if (inventory.show_gold() < rule.gold_cost || meterial_slot.count < rule.meterial_cost)
        return EnhanceResult::noMeterial;
    
    inventory.spend_gold(rule.gold_cost);
    meterial_slot.count -= rule.meterial_cost;

    if (meterial_slot.count == 0)
        inventory.get_slots().erase(inventory.get_slots().begin() + meterial_index);
    
    roll = Random::range(1, 100);
    if (roll > rule.success_rate) 
        return EnhanceResult::Failed;
    
    slot.item->set_enhance_level(slot.item->get_enhance_level() + 1);

    return EnhanceResult::Success;
}

bool Player::expand_inventory()
{
    int level = inventory.get_expansion_count();
    int max_level = inventory.get_max_expansion_count();
    if (level >= max_level) 
        return false;
    
    const auto &data = cost_table[level];
    int my_gold = inventory.show_gold();
    if (my_gold < data.cost)
        return false;
    
    inventory.spend_gold(data.cost);
    inventory.expand_inventory(data.add_slots);
    inventory.increase_expansion_count(1);

    return true;
}

Inventory &Player::get_inventory() { return inventory; }

bool Player::buy_item(const ItemData &item)
{
    int cur_gold = get_inventory().show_gold();
    if (cur_gold < item.price)
        return false;
    get_inventory().spend_gold(item.price);
    if (!get_inventory().add_item(ItemFactory::create(item.id)))
        return false;
    return true;
}

bool Player::buy_item(const ItemData &item, int count)
{
    int cur_gold = get_inventory().show_gold();
    int spend_gold = item.price * count;
    if (cur_gold < spend_gold)
        return false;
    get_inventory().spend_gold(spend_gold);
    if (!get_inventory().add_item(ItemFactory::create(item.id), count))
        return false;
    return true;
}

bool Player::sell_item(int inventory_index, int count)
{
    int earned = 0;
    int index = inventory_index - 1;
    if (!get_inventory().sell_slot(index, count, earned))
        return false;
    
    get_inventory().earn_gold(earned);
    return true;
}