#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class uniqueLockCount {
    int counter;
    mutex mtx;

    static void thread_func(uniqueLockCount *obj)
    {
        obj->run();
    }

    void run() {
        unique_lock<mutex> l(mtx, std::defer_lock);

        //lock(l1, l2, ...) can lock more that one
        //lock - locks the mutex, blocks if the mutex is not available
        //try_lock - tries to lock the mutex, returns if the mutex is not available
        //unlock - unlocks the mutex

        l.lock();

        for (int i = 0; i < 100000; ++i) {
            ++counter;
            cout << "1";
        }

        l.unlock();
    }

    public:

    int demo()
    {
        thread t1(uniqueLockCount::thread_func, this);
        thread t2(uniqueLockCount::thread_func, this);
        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << " (200000-nek kell lennie!)" << endl;

        return 0;
    }

    uniqueLockCount() {
        counter = 0;
    }
};

