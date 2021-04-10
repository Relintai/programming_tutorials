#include <iostream>
#include <thread>

using namespace std;

class ThreadProblemCount {
    int counter;

    static void thread_func(ThreadProblemCount *obj)
    {
        obj->run();
    }

    void run() {
        for (int i = 0; i < 100000; ++i) {
            ++counter;
            cout << " ";
            //std::this_thread::sleep_for(std::chrono::nanoseconds(3));
        }
    }

    public:

    int demo()
    {
        thread t1(ThreadProblemCount::thread_func, this);
        thread t2(ThreadProblemCount::thread_func, this);
        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << " (200000-nek kellene lennie!)" << endl;

        return 0;
    }

    ThreadProblemCount() {
        counter = 0;
    }
};

