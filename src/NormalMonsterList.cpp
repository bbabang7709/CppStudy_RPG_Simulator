/*****************************************
 *  File_name : NormalMonsterList.cpp
 *  일반 몬스터 리스트 관리
 ******************************************/
#include "NormalMonsterList.h"
#include "Random.h"
#include "Item.h"
#include "ItemID.h"
#include "WeaponList.h"
#include "ArmorList.h"

#include <iostream>
#include <string>
#include <memory>

Tutorial::Tutorial() : Monster("훈련용 짚인형", 0, 0)
{
    base_stats.hp = 50;
    base_stats.power = 5;
    base_stats.cri = 0;
    base_stats.criDamage = 1.0f;
    base_stats.speed = 0;

    recalc_final_stats();
    reset_condition();

    drop_table = {
        { 49, ItemID::NormalWeapon },
        { 51, ItemID::NormalArmor }
    };
}
const std::vector<DropItem> &Tutorial::get_drop_table() const
{
    return drop_table;
}
void Tutorial::take_turn(BattleContext &context)
{
    this->basic_attack(context.player);
}

Slime::Slime() : Monster("슬라임", 300, 30)
{
    base_stats.hp = 100;
    base_stats.power = 20;
    base_stats.defend = 5;
    base_stats.vigor = 10;
    
    recalc_final_stats();
    reset_condition();

    drop_table = {
        { 20, ItemID::ReinforceStone },
        { 10, ItemID::NormalWeapon },
        { 15, ItemID::NormalArmor },
        { 7, ItemID::SlimeSword } 
    };
}

const std::vector<DropItem> &Slime::get_drop_table() const
{
    return drop_table;
}
void Slime::take_turn(BattleContext &context)
{
    float hp_ratio = (float)this->get_hp() / this->get_max_hp();
    if (hp_ratio < 0.4f && !has_regenerated) {
        this->skill_regeneration();
        return;
    }
    int roll = Random::range(1, 100);
    if (roll <= 70) {
        this->basic_attack(context.player);
    } else{
        this->basic_defend();
    }
}
void Slime::skill_regeneration()
{
    print_msg("몸을 웅크려 상처를 회복합니다!!");
    this->add_buff({ "체력 재생", BuffType::Buff, StatBlock{}, 15, 5 });
    this->has_regenerated = true;
    Sys::delay(1000);
}

Goblin::Goblin() : Monster("고블린", 700, 50)
{
    base_stats.hp = 400;
    base_stats.power = 45;
    base_stats.defend = 15;
    base_stats.vigor = 15;
    
    recalc_final_stats();
    reset_condition();

    drop_table = {
        { 30, ItemID::ReinforceStone },
        { 10, ItemID::NormalWeapon },
        { 20, ItemID::NormalArmor },
        { 5, ItemID::GoblinArmor }
    };
}

const std::vector<DropItem> &Goblin::get_drop_table() const
{
    return drop_table;
}
void Goblin::take_turn(BattleContext &context)
{
    int roll = Random::range(1, 100);
    if (roll <= 70) {
        this->basic_attack(context.player);
    } else if (roll <= 80) {
        print_msg("멍청하다는 듯이 당신을 바라봅니다...");
    } else {
        this->double_slash(context.player);
    }
}
void Goblin::double_slash(Player &target)
{
    print_msg("간악하게 웃으며 눈 깜짝할 새 두 번 베어냅니다.");
    std::cout << "[첫 번째 공격!] ";
    target.take_damage(this->get_final_stats().power * 0.7);
    std::cout << "[두 번째 공격!] ";
    target.take_damage(this->get_final_stats().power * 0.7);
}

Orc::Orc() : Monster("오크", 1200, 80)
{
    base_stats.hp = 1200;
    base_stats.power = 85;
    base_stats.defend = 35;
    base_stats.vigor = 25;

    recalc_final_stats();
    reset_condition();

    drop_table = {
        { 35, ItemID::ReinforceStone },
        { 20, ItemID::NormalWeapon },
        { 20, ItemID::NormalArmor },
        { 3, ItemID::PowerGauntlet }
    };
}

const std::vector<DropItem> &Orc::get_drop_table() const
{
    return drop_table;
}
void Orc::take_turn(BattleContext &context)
{
    int roll = Random::range(1, 100);
    if (roll <= 70) {
        this->basic_attack(context.player);
    } else if (roll <= 90) {
        this->basic_defend();
    } else {
        if (context.player.get_final_stats().defend >= 20) {
            print_msg("오크가 당신의 방어구를 부수려 합니다!! (방어력 감소)");
            context.player.add_buff({"갑옷 파괴", BuffType::Debuff, StatBlock{.defend = -10}, 0, 2});
        } else {
            print_msg("무거운 도끼로 내려찍습니다.");
            context.player.take_damage(this->get_final_stats().power * 1.3);
        }
    }
}
