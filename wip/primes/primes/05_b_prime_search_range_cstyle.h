#ifndef PRIME_SEARCH_RANGE_CS_H
#define PRIME_SEARCH_RANGE_CS_H

#include <thread>
#include <vector>
#include "prime_test.h"

using namespace std;

struct PRPSData
{
    uint32_t rmin = 0;
    uint32_t rmax = 0;
    bool finished = true;
    vector<bool> results;
    thread *t = nullptr;
};

void psr_prime_range_thread_func(PRPSData *data)
{
    data->finished = false;

    for (uint32_t i = data->rmin; i < data->rmax; ++i)
    {
        data->results.push_back(is_prime(i));
    }

    data->finished = true;
}

void psr_search(uint32_t start_at, uint32_t element_per_thread)
{
    const uint32_t thread_count = 4;

    PRPSData data[thread_count];

    for (uint32_t i = 0; i < thread_count; ++i)
    {
        data[i].rmin = start_at + element_per_thread * i;
        data[i].rmax = start_at + element_per_thread * (i + 1);

        data[i].t = new thread(psr_prime_range_thread_func, &data[i]);
    }

    bool all_finished = false;
    while (!all_finished)
    {
        all_finished = true;

        for (uint32_t i = 0; i < thread_count; ++i)
        {
            if (data[i].finished)
            {
                if (data[i].t == nullptr)
                    continue;

                for (uint32_t j = 0; j < data[i].results.size(); ++j)
                {
                    cout << j + data[i].rmin << "->" << (data[i].results[j] ? "p" : "np") << ", ";
                }

                data[i].t->join();
                delete data[i].t;
                data[i].t = nullptr;
            }
            else
            {
                all_finished = false;
            }
        }
    }

    cout << endl;
}


#endif // SIMPLE_PRIME_SEARCH_H

