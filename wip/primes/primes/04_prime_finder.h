#ifndef PRIME_FINDER_H
#define PRIME_FINDER_H

#include <vector>

using namespace std;

#include "PrimeFactorizationWithSingleThread.h"
#include "PrimeFactorizationWithMultipleThreads.h"

#define CurrentPrimeFinder PrimeFactorizationWithSingleThread

class PrimeFinder
{
public:
    void search(uint64_t from, uint64_t to)
    {
        uint64_t current = from;

        const uint64_t thread_count = 4;

        PrimeFactorization *data[thread_count];

        for (uint64_t i = 0; i < thread_count; ++i)
        {
            if (current != to)
            {
                PrimeFactorization *t = new CurrentPrimeFinder();
                t->launch(current++);

                data[i] = t;
            } else {
                data[i] = nullptr;
            }
        }

        bool all_finished = false;
        while (!all_finished)
        {
            all_finished = true;

            for (uint64_t i = 0; i < thread_count; ++i)
            {
                if (data[i]->finished)
                {
                    if (current != to)
                    {
                        data[i]->print();
                        data[i]->launch(current++);

                        all_finished = false;
                    }
                }
            }
        }

        for (uint64_t i = 0; i < thread_count; ++i)
        {
            //kevesebb szam volt mint thread
            if (data[i] == nullptr)
                continue;

            if (data[i]->finished)
            {
                data[i]->print();
                delete data[i];
            }
        }

        cout << endl;
    }

};

#undef CurrentPrimeFinder

#endif // SIMPLE_PRIME_SEARCH_H
