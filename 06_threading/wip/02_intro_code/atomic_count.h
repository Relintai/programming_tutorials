//új
#pragma once

//régi
#ifndef ATOMIC_COUNT_H
#define ATOMIC_COUNT_H

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class AtomicCount {
    atomic<int> counter;

    static void thread_func(AtomicCount *obj) {
        obj->count();
    }

    void count() {
        for (int i =0; i < 100000; ++i) {
            ++counter;
            cout << 1;
        }
    }

public:

    void demo() {
        thread t1(AtomicCount::thread_func, this);
        thread t2(AtomicCount::thread_func, this);

        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << endl;
    }

    AtomicCount () {
        counter = 0;
    }

};

#endif // ATOMIC_COUNT_H
