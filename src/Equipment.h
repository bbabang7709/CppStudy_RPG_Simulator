/*****************************************
 *  File_name : Equipment.h
 *  착용 가능한 아이템 클래스 정의
 ******************************************/
#pragma once
#include "Item.h"
#include "ItemDatabase.h"
#include "StatBlock.h"

class Equipment : public Item
{
public :
    Equipment(const ItemData &data);
    
    int get_atk() const;
    int get_def() const;
    int get_vig() const;
    int get_cri() const;

    bool has_option() const { return true; }
    const StatBlock get_flat_stats() const override;
    const StatPointBlock get_stat_point_bonus() const override;

    int get_enhance_level() const override;
    bool can_enhance() const;
    void enhance();
    bool is_enhanceable() const override;
    void set_enhance_level(int e_level) override;
    
protected :
    StatBlock flat_stats;
    StatPointBlock stat_point_bonus;

    int enhance_level = 0;
    static constexpr int MAX_ENHANCE = 10;
};