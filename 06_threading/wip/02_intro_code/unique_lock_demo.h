#ifndef UNIQUE_LOCK_DEMO
#define UNIQUE_LOCK_DEMO

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class UniqueLockCount {
    int counter;
    mutex mtx;

    static void thread_func(UniqueLockCount *p) {
        p->count();
    }

    void count() {
        unique_lock<mutex> lock(mtx, std::defer_lock);

        for (int i = 0; i < 100000; ++i) {
            lock.lock();
            ++counter;
            lock.unlock();

            cout << "1";
        }

        //std::lock(l1, l2, ...) le lehet zárni, többet egyszerre
        //lock.try_lock() csak visszatér, ha nem sikerül lezárnia
    }

public:

    void demo() {
        thread t1(UniqueLockCount::thread_func, this);
        thread t2(UniqueLockCount::thread_func, this);

        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << endl;

    }

    UniqueLockCount() {
        counter = 0;
    }
};

#endif
