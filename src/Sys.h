/*****************************************
 *  File_name : Sys.h
 *  화면 출력 등을 담당하는 시스템 호출
 ******************************************/
#pragma once

class Sys
{
public :
    void clear_screen();
    void delay(int milliseconds);
    int safe_int_input();
    int safe_int_input(int min, int max);
};