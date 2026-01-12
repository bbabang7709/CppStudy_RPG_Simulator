/*****************************************
 *  File_name : CommercialProcess.h
 *  상업지구 프로세스 구현
 ******************************************/
#pragma once

#include "Player.h"
#include "Sys.h"
#include "GameUI.h"

enum class CommercialSelect
{
    Exit = 0,
    Shop,
    Forge
};

class CommercialProcess : public Sys
{
public :
    void shop_process(Player &player);
    void forge_process(Player &player);
    void run(Player &player);

private :
    GameUI UI;
};