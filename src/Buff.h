/*****************************************
 *  File_name : Buff.h
 *  Buff 구조체 정의
 ******************************************/
#pragma once

#include "StatBlock.h"
#include <string>

enum class BuffType
{
    Buff,
    Debuff
};

struct Buff
{
    std::string buff_name;
    BuffType type;
    StatBlock effect = {0};
    int tick_hp;
    int duration;
    void clear()
    {
        buff_name = "";
        type = BuffType::Buff;
        effect.clear();
        duration = 0;
    }

    bool is_expired() const { return duration <= 0; }
    void tick() 
    { 
        if (duration > 0) {
            duration--;
        } 
    }
};