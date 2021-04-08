#ifndef FIRST_PRIME_THREAD_CLASS_H
#define FIRST_PRIME_THREAD_CLASS_H

#include "simple_threaded_prime_factorization.h"

#include <vector>

using namespace std;

class FirstPrimeThreadClass {
public:
    void search(uint32_t from, uint32_t to) {
        uint32_t range = to - from;

        vector<SimpleThreadedPrimeFactorization *> tests;

        for (uint32_t i = 0; i < range; ++i) {
            SimpleThreadedPrimeFactorization *t = new SimpleThreadedPrimeFactorization();

            t->launch(i + from);

            tests.push_back(t);
        }

        bool all_finished = false;

        while (!all_finished) {
            all_finished = true;

            for (uint32_t i = 0; i < tests.size(); ++i) {
                if (!tests[i]->finished) {
                    all_finished =  false;

                    //lehetne  várni, hogy ne maxoljuk ki a cpu-t

                    break;
                }
            }
        }

        for (uint32_t i = 0; i < tests.size(); ++i) {
            tests[i]->print();
            delete tests[i];
        }

        cout << endl;
    }

};


#endif
