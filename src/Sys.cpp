/*****************************************
 *  File_name : Sys.cpp
 *  화면 출력 등을 담당하는 시스템 호출
 ******************************************/
#include "Sys.h"
#include "Monster.h"
#include "Player.h"

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void Sys::print_status(Monster &mon, Player &player)
{
    cout << "-----------------------------------------------------" << endl;
    cout << "[" << mon.get_name() << "]" << endl;
    cout << "HP : " << mon.get_hp() << " / " << mon.get_max_hp() << endl;
    cout << "MP : " << mon.get_mp() << endl << endl;
    cout << "[플레이어]" << endl;
    cout << "HP : " << player.get_hp() << " / " << player.get_max_hp() << endl;
    cout << "MP : " << player.get_mp() << endl << endl;
    cout << "-----------------------------------------------------" << endl;
}

void Sys::clear_screen()
{
    //cout << "\x1B[2J\x1B[H";
    system("cls");
}

void Sys::print_menu()
{
    cout << endl;
    cout << "무엇을 할까 ??" << endl;
    cout << "1. 일반공격 2. 특수공격 3. 회복   4. 도망" << endl; 
    cout << "선택 >>> ";
}

void Sys::delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}