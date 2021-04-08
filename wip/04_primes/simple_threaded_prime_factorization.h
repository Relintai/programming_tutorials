#ifndef SIMPLE_THREADED_PRIME_FACTORIZATION_H
#define SIMPLE_THREADED_PRIME_FACTORIZATION_H

#include <iostream>
#include <thread>

using namespace std;

class SimpleThreadedPrimeFactorization {
public:
    thread *t;
    bool is_prime;
    uint32_t num;
    bool finished;

    void launch(uint32_t p_num) {
        num = p_num;

        if (t) {
            t->join();
            delete t;
        }

        t = new thread(SimpleThreadedPrimeFactorization::_thread_func, this);
    }

    static void _thread_func(SimpleThreadedPrimeFactorization *p) {
        p->check();
    }

    void check() {
        finished = false;

        is_prime = true;

        for (uint32_t i = 2; i < num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                finished = true;

                return;
            }
        }

        finished = true;
    }

    void print() {
        cout << num << "->" << (is_prime ? "p" : "np") << ", ";
    }

    SimpleThreadedPrimeFactorization() {
        t = nullptr;
        finished = true;
        is_prime = false;
        num = 0;
    }

    ~SimpleThreadedPrimeFactorization() {
        if (t) {
            t->join();
            delete t;
        }
    }
};


#endif // PRIME_TEST_H

