/**
 * @brief Implements all classes that are relevant
 *
 * @file class.cpp
 */

#include "class.h"


Effects::Effects(int born, int sick) : born(born), sleep(0), depressive(0), hatching(0), overworked(0), sick(sick) {};
Effects::Effects(int born, int sleep, int depressive, int hatching, int overworked, int sick) :
    born(born),
    sleep(sleep),
    depressive(depressive),
    hatching(hatching),
    overworked(overworked),
    sick(sick)
{};

Stats::Stats() : fitness(10), happiness(10), motivation(10), resillience(10), restfulness(10), saturation(10) {};
Stats::Stats(int fitness, int happiness, int motivation, int resillience, int restfulness, int saturation) :
    fitness(fitness),
    happiness(happiness),
    motivation(motivation),
    resillience(resillience),
    restfulness(restfulness),
    saturation(saturation)
{};