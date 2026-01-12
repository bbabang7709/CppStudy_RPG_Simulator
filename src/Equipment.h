/*****************************************
 *  File_name : Equipment.h
 *  착용 가능한 아이템 클래스 정의
 ******************************************/
#pragma once
#include "Item.h"
#include "ItemDatabase.h"

class Equipment : public Item
{
public :
    Equipment(const ItemData &data);
    int get_enhance_level() const override;
    bool can_enhance() const;
    void enhance();
    bool is_enhanceable() const override;
    void set_enhance_level(int e_level) override;
    
protected :
    int enhance_level = 0;
    static constexpr int MAX_ENHANCE = 10;
};