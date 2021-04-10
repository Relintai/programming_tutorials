#ifndef PRIME_SEARCH_RANGE_H
#define PRIME_SEARCH_RANGE_H

#include <thread>
#include <vector>
#include "PSData.h"

using namespace std;

//PSDATA class

class PrimeSearchRange {
public:
    void search(uint64_t start_at, uint64_t element_per_thread) {
        const uint64_t thread_count = 4;

        PSData data[thread_count];

        for (uint64_t i = 0; i < thread_count; ++i) {
            data[i].start(start_at + element_per_thread * i, start_at + element_per_thread * (i + 1));
        }

        bool all_finished = false;
        while (!all_finished) {
            all_finished = true;

            for (uint64_t i = 0; i < thread_count; ++i) {
                if (!data[i].finished) {
                    all_finished = false;
                    //sleep
                }
            }
        }

        for (uint64_t i = 0; i < thread_count; ++i) {
            data[i].print();
        }

        cout << endl;
    }

};

#endif // SIMPLE_PRIME_SEARCH_H

