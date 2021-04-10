#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class AtomicCount {
    atomic<int> counter;

    static void thread_func(AtomicCount *obj)
    {
        obj->run();
    }

    void run() {
        for (int i = 0; i < 100000; ++i) {
            ++counter;
            cout << "1";
        }
    }

    public:

    int demo()
    {
        thread t1(AtomicCount::thread_func, this);
        thread t2(AtomicCount::thread_func, this);
        t1.join();
        t2.join();

        cout << "Atmomic eredmeny: " << counter << " (200000-nek kell lennie!)" << endl;

        return 0;
    }

    AtomicCount() {
        counter = 0;
    }
};

