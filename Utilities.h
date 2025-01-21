#pragma once
#include "Macro.h"

u_int GetUniqueID();

static int RandomInt(const int _min, const int _max)
{
    std::random_device _dev;
    std::mt19937 _rng(_dev());
    std::uniform_int_distribution<std::mt19937::result_type> _dist(_min, _max);

    return _dist(_rng);
}

template<typename ReturnValue>
static ReturnValue GetRandomNumberInRange(const ReturnValue _min, const ReturnValue _max)
{
    std::random_device _dev;
    std::mt19937 _rng(_dev());
    std::uniform_real_distribution<> _dist(_min, _max);

    return _dist(_rng);
}
