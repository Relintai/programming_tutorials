#ifndef SIMPLE_PRIME_SEARCH_H
#define SIMPLE_PRIME_SEARCH_H

#include <thread>
#include "prime_test.h"

using namespace std;

struct SPSData
{
    uint32_t num = 0;
    bool finished = true;
    bool is_prime = false;
    thread *t = nullptr;
};

void simple_prime_fender_is_prime_thread_func(SPSData *data)
{
    data->finished = false;
    data->is_prime = is_prime(data->num);
    data->finished = true;
}

void simple_prime_fender_search(uint32_t from, uint32_t to)
{
    uint32_t current = from;

    const uint32_t thread_count = 4;

    SPSData data[thread_count];

    for (uint32_t i = 0; i < thread_count; ++i)
    {
        if (current != to)
        {
            data[i].finished = false;
            data[i].num = current++;

            data[i].t = new thread(simple_prime_fender_is_prime_thread_func, &data[i]);
        }
    }

    bool all_finished = false;
    while (!all_finished)
    {
        all_finished = true;

        for (uint32_t i = 0; i < thread_count; ++i)
        {
            if (data[i].finished)
            {
                if (current != to)
                {
                    cout << data[i].num << "->" << (data[i].is_prime ? "p" : "np") << ", ";

                    data[i].num = current++;

                    data[i].t->join();
                    if (data[i].t != nullptr)
                        delete data[i].t;

                    data[i].t = new thread(simple_prime_fender_is_prime_thread_func, &data[i]);

                    all_finished = false;
                }
            }
            else
            {
                all_finished = false;
            }
        }
    }

    for (uint32_t i = 0; i < thread_count; ++i)
    {
        if (data[i].finished)
        {
            //kevesebb szam volt mint thread
            if (data[i].t == nullptr)
                continue;

            cout << data[i].num << "->" << (data[i].is_prime ? "p" : "np") << ", ";

            data[i].t->join();
            delete data[i].t;
        }
    }

    cout << endl;
}

#endif // SIMPLE_PRIME_SEARCH_H
