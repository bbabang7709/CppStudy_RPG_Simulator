/*****************************************
 *  File_name : Player.cpp
 *  모험을 진행하는 플레이어 클래스
 ******************************************/
#include "Player.h"
#include "ExpTable.h"
#include "Random.h"
#include "InventoryExpand.h"
#include "GameUI.h"
#include <algorithm>
#include <iostream>

Player::Player()
{
    base_stats.hp = 100;
    base_stats.mp = 5;
    base_stats.power = 10;
    base_stats.defend = 5;
    base_stats.vigor = 30;
    base_stats.cri = 0;
    base_stats.speed = 0;

    recalc_final_stats();
    reset_condition();
}
Player::~Player() = default;

int Player::get_base_hp() const { return base_stats.hp; }
int Player::get_base_mp() const { return base_stats.mp; }
int Player::get_base_power() const { return base_stats.power; }
int Player::get_base_defend() const { return base_stats.defend; }
int Player::get_base_vigor() const { return base_stats.vigor; }

void Player::set_base_hp(int _hp)
{
    base_stats.hp = _hp;
}
void Player::set_base_mp(int _mp)
{
    base_stats.mp = _mp;
}
void Player::set_base_power(int _power)
{
    base_stats.power = _power;
}
void Player::set_base_defend(int _defend)
{
    base_stats.defend = _defend;
}
void Player::set_base_vigor(int _vigor)
{
    base_stats.vigor = _vigor;
}

StatBlock Player::get_base_stats() const { return base_stats; }
StatBlock Player::get_final_stats() const { return final_stats; }

//================= EXP =================//

int Player::get_level() const { return level; }

int Player::get_exp() const { return exp; }

void Player::gain_exp(int _exp)
{
    exp += _exp;

    while (exp >= ExpTable::get_required_exp(level))
    {
        exp -= ExpTable::get_required_exp(level);
        level_up();
    }
}

void Player::set_level(int _level)
{
    level = _level;
}

void Player::level_up()
{
    level++;
    stat_point += 5;

    std::cout << "레벨 업!! LV. " << level << std::endl;
}

//============== Stat Point ==============//

int Player::get_stat_point() const { return stat_point; }

bool Player::invest_stat_point(StatType type, int amount)
{
    switch (type)
    {
    case StatType::HP :
        base_stats.hp += amount * 10;
        break;
    case StatType::MP :
        base_stats.mp += amount * 2;
        break;
    case StatType::POWER :
        base_stats.power += amount * 2;
        break;
    case StatType::DEFEND :
        base_stats.defend += amount * 2;
        break;
    case StatType::VIGOR :
        base_stats.vigor += amount * 3;
        break;
    default :
        return false;
    }

    stat_point -= amount;
    recalc_final_stats();

    return true;
}

void Player::recalc_final_stats()
{
    final_stats = base_stats;

    if (my_weapon) {
        final_stats += my_weapon->get_total_bonus();
    }
    if (my_armor) {
        final_stats += my_armor->get_total_bonus();
    }
}

void Player::reset_stat_point()
{
    base_stats.hp = 100;
    base_stats.mp = 5;
    base_stats.power = 10;
    base_stats.defend = 5;
    base_stats.vigor = 30;
    base_stats.cri = 0;
    base_stats.speed = 0;

    stat_point += (level - 1) * 5;

    recalc_final_stats();
}

void Player::attack(Character &target)
{
    target.take_damage(final_stats.power);
}

void Player::reset_player()
{
    if (get_my_weapon())
        unequip_Weapon();
    if (get_my_armor())
        unequip_Armor();

    level = 1;
    exp = 0;
    recalc_final_stats();
    reset_condition();
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
            // set_max_hp(max_hp + weapon->get_weapon_hp());
            // set_max_mp(max_mp + weapon->get_weapon_mp());
            // set_power(power + weapon->get_weapon_power() + weapon->get_enhance_level() * 5);
            // set_defend(defend + weapon->get_weapon_defend());
            // set_vigor(vigor + weapon->get_weapon_vigor());
            my_weapon = std::move(weapon);
            recalc_final_stats();
            break;
        }
        case ItemType::Armor :
        {
            auto armor = std::unique_ptr<Armor>(dynamic_cast<Armor *>(item.release()));
            if (!armor)
                return false;
            if (my_armor)
                get_inventory().add_item(unequip_Armor());
            // set_max_hp(max_hp + armor->get_armor_hp());
            // set_max_mp(max_mp + armor->get_armor_mp());
            // set_power(power + armor->get_armor_power());
            // set_defend(defend + armor->get_armor_defend() + armor->get_enhance_level() * 3);
            // set_vigor(vigor + armor->get_armor_vigor());
            my_armor = std::move(armor);
            recalc_final_stats();
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
        // set_max_hp(max_hp - my_weapon->get_weapon_hp());
        // set_max_mp(max_mp - my_weapon->get_weapon_mp());
        // set_power(power - my_weapon->get_weapon_power() - my_weapon->get_enhance_level() * 5);
        // set_defend(defend - my_weapon->get_weapon_defend());
        // set_vigor(vigor - my_weapon->get_weapon_vigor());
        auto unequiped_weapon = std::move(my_weapon);
        recalc_final_stats();

        return unequiped_weapon; 
    }
}

std::unique_ptr<Armor> Player::unequip_Armor()
{
    if (!my_armor) {
        std::cout << "장착된 방어구가 없습니다." << std::endl;
        return nullptr;
    } else {
        // set_max_hp(max_hp - my_armor->get_armor_hp());
        // set_max_mp(max_mp - my_armor->get_armor_mp());
        // set_power(power - my_armor->get_armor_power());
        // set_defend(defend - my_armor->get_armor_defend() - my_armor->get_enhance_level() * 3);
        // set_vigor(vigor - my_armor->get_armor_vigor());
        auto unequiped_armor = std::move(my_armor);
        recalc_final_stats();

        return unequiped_armor;
    }
}
bool Player::try_unequip(int index)
{
    if (index == 1) {
        if (!inventory.add_item(unequip_Weapon()))
            return false;
    } else if (index == 2) {
        if (!inventory.add_item(unequip_Armor()))
            return false;
    } else {
        return false;
    }

    return true;
}

EnhanceResult Player::enhance_item(int inventory_index)
{
    int index = inventory_index - 1;
    int meterial_index = -1;
    int roll;
    bool is_success = false;

    auto &slots = inventory.get_slots();
    if (index < 0 || index >= static_cast<int>(slots.size()))
        return EnhanceResult::Error;

    auto &slot = slots[index];

    if (!slot.item->is_enhanceable())
        return EnhanceResult::Disable;
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
    
    roll = Random::range(1, 100);
    if (roll > rule.success_rate) 
        is_success = false;
    
    slot.item->set_enhance_level(slot.item->get_enhance_level() + 1);
    is_success = true;

    inventory.spend_gold(rule.gold_cost);
    meterial_slot.count -= rule.meterial_cost;

    if (meterial_slot.count == 0)
        inventory.get_slots().erase(inventory.get_slots().begin() + meterial_index);

    if (is_success)
        return EnhanceResult::Success;
    else
        return EnhanceResult::Failed;
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