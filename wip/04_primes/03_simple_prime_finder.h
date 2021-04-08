#ifndef SIMPLE_PRIME_FINDER_H
#define SIMPLE_PRIME_FINDER_H

#include <vector>

using namespace std;

#include "PrimeFactorizationWithMultipleThreads.h"
#include "PrimeFactorizationWithSingleThread.h"

class SimplePrimeFinder
{
public:

    void search(uint64_t from, uint64_t to)
    {
        uint64_t range = to - from;

        vector<PrimeFactorization *> tests;

        for (uint64_t i = 0; i < range; ++i)
        {
            PrimeFactorization *p = new PrimeFactorization();
            //vagy
            //PrimeFactorization *p = new PrimeFactorizationWithSingleThread();
            //vagy
            //PrimeFactorization *p = new PrimeFactorizationWithMultipleThreads();

            p->launch(i + from);

            tests.push_back(p);
        }

        bool all_finished = false;

        while (!all_finished)
        {
            all_finished = true;

            for (uint64_t i = 0; i < tests.size(); ++i)
            {
                if (!(tests[i]->finished))
                {
                    all_finished = false;

                    //lehetne várni kicsit

                    break;
                }
            }
        }

        for (uint64_t i = 0; i < tests.size(); ++i)
        {
            tests[i]->print();
            delete tests[i];
        }

        cout << endl;
    }

};

#endif
