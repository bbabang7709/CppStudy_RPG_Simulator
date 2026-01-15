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
    float criDamage = 0.0f;
    int speed = 0;

    void clear() { hp = 0; mp = 0; power = 0; defend = 0; vigor = 0; cri = 0; criDamage = 0.0f; speed = 0; }

    StatBlock &operator+=(const StatBlock &rhs) {
        StatBlock res;
        res.clear();

        res.hp = this->hp + rhs.hp;
        res.mp = this->mp + rhs.mp;
        res.power = this->power + rhs.power;
        res.defend = this->defend + rhs.defend;
        res.vigor = this->vigor + rhs.vigor;
        res.cri = this->cri + rhs.cri;
        res.criDamage = this->criDamage + rhs.criDamage;
        res.speed = this->speed + rhs.speed;

        *this = res;
        return *this;
    }
    StatBlock &operator+(const StatBlock &rhs) {
        StatBlock res;
        res.clear();

        res.hp = this->hp + rhs.hp;
        res.mp = this->mp + rhs.mp;
        res.power = this->power + rhs.power;
        res.defend = this->defend + rhs.defend;
        res.vigor = this->vigor + rhs.vigor;
        res.cri = this->cri + rhs.cri;
        res.criDamage = this->criDamage + rhs.criDamage;
        res.speed = this->speed + rhs.speed;

        *this = res;
        return *this;
    }
};

struct StatPointBlock
{
    int str = 0;
    int dex = 0;
    int con = 0;

    StatPointBlock &operator+=(const StatPointBlock &other) {
        str += other.str;
        dex += other.dex;
        con += other.con;

        return *this;
    }
    StatPointBlock &operator+(const StatPointBlock &other) {
        str += other.str;
        dex += other.dex;
        con += other.con;

        return *this;
    }
    StatPointBlock &operator-(const StatPointBlock &other) {
        str -= other.str;
        dex -= other.dex;
        con -= other.con;

        return *this;
    }
};