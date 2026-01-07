/*****************************************
 *  File_name : Random.h
 *  다양한 난수 생성 메서드 정의
 ******************************************/
#pragma once

class Random
{
public :
    // 0 ~ (max - 1)
    static int range(int max);

    // min ~ max
    static int range(int min, int max);

    // 확률 판정 (0.0 ~ 1.0)
    static bool chance(double probability);
};
