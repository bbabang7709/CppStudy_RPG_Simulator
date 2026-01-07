/*****************************************
 *  File_name : SaveSystem.h
 *  저장 및 불러오기 시스템
 ******************************************/
#pragma once

#include "Sys.h"
#include "Player.h"

class SaveManager : public Sys
{
public :
    void Save(Player &player);
};

class LoadManager : public Sys
{
public :
    void Load(Player &player);
};