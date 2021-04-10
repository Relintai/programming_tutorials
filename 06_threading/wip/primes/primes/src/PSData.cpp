#include "PSData.h"

void PSData::_thread_func(PSData *data)
{
    data->work();
}

bool PSData::is_prime(uint64_t num)
{
    for (uint64_t i = 2; i < num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void PSData::work()
{
    finished = false;

    for (uint64_t i = rmin; i < rmax; ++i)
    {
        results.push_back(is_prime(i));
    }

    finished = true;
}

void PSData::start(uint64_t p_min, uint64_t p_max)
{
    rmin = p_min;
    rmax = p_max;

    if (t)
    {
        t->join();
        delete t;
    }

    t = new thread(PSData::_thread_func, this);
}

void PSData::print()
{
    for (uint64_t j = 0; j < results.size(); ++j)
    {
        cout << j + rmin << "->" << (results[j] ? "p" : "np") << ", ";
    }
}

PSData::PSData()
{
    rmin = 0;
    rmax = 0;
    finished = true;
    t = nullptr;
}

PSData::~PSData()
{
        if (t)
    {
        t->join();
        delete t;
    }
}
