#ifndef LOCK_GUARD_H
#define LOCK_GUARD_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class LockGuardCount {
    int counter;
    mutex mtx;

    static void thread_func(LockGuardCount *p) {
        p->count();
    }

    void count() {
        const lock_guard<mutex> lock(mtx);

        for (int i = 0; i < 100000; ++i) {
            ++counter;
            cout << "1";
        }
    }

public:

    void demo() {
        thread t1(LockGuardCount::thread_func, this);
        thread t2(LockGuardCount::thread_func, this);

        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << endl;

    }

    LockGuardCount() {
        counter = 0;
    }
};

#endif // LOCK_GUARD_H
