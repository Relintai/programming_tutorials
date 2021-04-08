#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class LockGuardCount {
    int counter;
    mutex mtx;

    static void thread_func(LockGuardCount *obj)
    {
        obj->run();
    }

    void run() {
        const lock_guard<mutex> lock(mtx);

        for (int i = 0; i < 100000; ++i) {
            ++counter;
            cout << "1";
        }
    }

    public:

    int demo()
    {
        thread t1(LockGuardCount::thread_func, this);
        thread t2(LockGuardCount::thread_func, this);
        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << " (200000-nek kell lennie!)" << endl;

        return 0;
    }

    LockGuardCount() {
        counter = 0;
    }
};

