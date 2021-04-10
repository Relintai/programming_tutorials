#ifndef FIRST_PRIME_THREADED_H
#define FIRST_PRIME_THREADED_H

#include <thread>
#include <vector>
#include "prime_test.h"

using namespace std;

class FirstPrimeThreaded {
    static void _thread_func(uint32_t num) {
        bool p = is_prime(num);

        cout << num << "->" << (p ? "p" : "np") << ", ";
    }

public:
    void search(uint32_t from, uint32_t to) {
        uint32_t range = to - from;

        vector<thread *> threads;

        for (uint32_t i = 0; i < range; ++i) {
            thread *t = new thread(FirstPrimeThreaded::_thread_func, i + from);

            threads.push_back(t);
        }

        for (uint32_t i = 0; i < threads.size(); ++i) {
            threads[i]->join();
            delete threads[i];
        }

        cout << endl;
    }

};

#endif // FIRST_PRIME_THREADED_H
