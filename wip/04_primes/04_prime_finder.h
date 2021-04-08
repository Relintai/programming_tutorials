#ifndef PRIME_FINDER_H
#define PRIME_FINDER_H

#include "PrimeFactorization.h"
#include "PrimeFactorizationWithSingleThread.h"
#include "PrimeFactorizationWithMultipleThreads.h"

using namespace std;

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
                //PrimeFactorization *t = new PrimeFactorization();
                //vagy
                PrimeFactorization *t = new PrimeFactorizationWithSingleThread();
                //vagy
                //PrimeFactorization *t = new PrimeFactorizationWithMultipleThreads();

                t->launch(current++);

                data[i] = t;
            }
            else
            {
                data[i] = nullptr;
            }
        }

        bool all_finished = false;

        while (!all_finished)
        {
            all_finished = true;

            for (uint64_t i = 0; i < thread_count; ++i)
            {
                if (data[i] == nullptr)
                    continue;

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


        for (uint64_t i = 0; i < thread_count; ++i) {
            if (data[i] == nullptr)
                continue;

            if (data[i]->finished) {
                data[i]->print();
                delete data[i];
            }
        }
    }


};

#endif // PRIME_FINDER_H


