
#include <iostream>
#include <thread>
#include <chrono>

//sleep, id

using namespace std;

class ThreadSleep {
    static void thread_func(ThreadSleep *obj, const int index)
    {
        obj->run(index);
    }

    void run(const int index) {
        int sl = 0;

        if (index == 0) {
            sl = 100;
        } else {
            sl = 230;
        }

        for (int i = 0; i < 4; ++i) {
            cout << index << ": Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sed quam lobortis." << this_thread::get_id() << endl;


            std::this_thread::sleep_for(std::chrono::milliseconds(sl));
        }

    }

    public:

    int demo()
    {
        std::srand(std::time(nullptr));

        thread t1(ThreadSleep::thread_func, this, 0);
        thread t2(ThreadSleep::thread_func, this, 1);
        t1.join();
        t2.join();

        return 0;
    }
};

