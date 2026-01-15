/*****************************************
 *  File_name : Sys.h
 *  화면 출력 등을 담당하는 시스템 호출
 ******************************************/
#pragma once

class Sys
{
public :
    static void clear_screen();
    static void delay(int milliseconds);
    static int safe_int_input();
    static int safe_int_input(int min, int max);
    static int safe_int_input_without_enter();
    static int safe_int_input_without_enter(int min, int max);
};