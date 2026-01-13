/*****************************************
 *  File_name : StatBlock.h
 *  스탯 블럭 구조체 정의
 ******************************************/
#pragma once

struct StatBlock
{  
    int hp = 0;
    int mp = 0;
    int power = 0;
    int defend = 0;
    int vigor = 0;
    int cri = 0;
    int speed = 0;

    StatBlock &operator+=(const StatBlock &rhs) {
        hp += rhs.hp;
        mp += rhs.mp;
        power += rhs.power;
        defend += rhs.defend;
        vigor += rhs.vigor;
        cri += rhs.cri;
        speed += rhs.speed;

        return *this;
    }
};