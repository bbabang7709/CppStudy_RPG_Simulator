/*****************************************
 *  File_name : Sys.cpp
 *  화면 출력 등을 담당하는 시스템 호출
 ******************************************/
#include "Sys.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <string>



void Sys::clear_screen()
{
    //cout << "\x1B[2J\x1B[H";
    system("cls");
}

void Sys::delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
int Sys::safe_int_input()
{
    std::string input;
    std::cin >> input;

    try {
        size_t idx;
        int value =std::stoi(input, &idx);

        if (idx != input.size()) {
            return -1;
        }

        return value;
    }
    catch (...) {
        return -1;
    }
}
int Sys::safe_int_input(int min, int max)
{
    std::string input;
    std::cin >> input;

    try {
        int value = std::stoi(input);
        if (value < min || value > max) 
            return -1;
        
        return value;
    }
    catch (...) {
        return -1;
    }
}