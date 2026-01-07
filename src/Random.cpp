/*****************************************
 *  File_name : Random.cpp
 *  다양한 난수 생성 메서드 정의
 ******************************************/
#include "Random.h"
#include <random>
#include <chrono>

static std::mt19937 &global_engine()
{
    static std::mt19937 engine (
        static_cast<unsigned int>(
            std::chrono::steady_clock::now()
                .time_since_epoch()
                .count()
        )
    );
    return engine;
}

int Random::range(int max)
{
    std::uniform_int_distribution<int> dist(0, max - 1);
    return dist(global_engine());
}

int Random::range(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(global_engine());
}

bool Random::chance(double probability)
{
    std::bernoulli_distribution dist(probability);
    return dist(global_engine());
}