#ifndef SIMPLE_PRIME_FINDER_H
#define SIMPLE_PRIME_FINDER_H

#include <vector>

using namespace std;

#include "PrimeFactorizationWithSingleThread.h"
#include "PrimeFactorizationWithMultipleThreads.h"
#define CurrentPrimeFinder PrimeFactorizationWithMultipleThreads

class SimplePrimeFinder {
public:

    void search(uint64_t from, uint64_t to) {
        uint64_t range = to - from;

        vector<PrimeFactorization *> tests;

        for (uint64_t i = 0; i < range; ++i) {
            PrimeFactorization *t = new CurrentPrimeFinder();
            t->launch(i + from);

            tests.push_back(t);
        }

        bool all_finished = false;

        while (!all_finished) {
            all_finished = true;

            for (uint64_t i = 0; i < tests.size(); ++i) {
                if (!tests[i]->finished) {
                    all_finished = false;

                    //wait f.e.

                    break;
                }
            }
        }

        for (uint64_t i = 0; i < range; ++i) {
            tests[i]->print();
            delete tests[i];
        }

        cout << endl;
    }

};

#undef CurrentPrimeFinder

#endif // FIRST_PRIME_THREADS_H
