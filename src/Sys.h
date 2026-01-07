/*****************************************
 *  File_name : Sys.h
 *  화면 출력 등을 담당하는 시스템 호출
 ******************************************/
#pragma once

class Monster;
class Player;

class Sys
{
public :
    void clear_screen();
    void print_status(Monster &mon, Player &player);
    void print_menu();
    void delay(int milliseconds);
};