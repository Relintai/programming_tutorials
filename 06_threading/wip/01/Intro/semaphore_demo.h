

#include <iostream>
#include <thread>
#include <functional>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class SemaphoreDemo {
    Semaphore s;
    bool running;

    static void run(SemaphoreDemo *p)
    {
        cout << "Hello Class Params World yay" << endl;

        p->calculate();
    }


    void calculate() {
        while (running) {

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            cout << "Calculation done!" << this_thread::get_id() << endl;

            s.wait();
        }
    }

    public:

    //main thread!
    void demo() {
        thread t(SemaphoreDemo::run, this);

        srand (time(NULL));

        for (int i = 0; i < 4; ++i) {
            int calls = rand() % 4 + 1;

            for (int j = 0; j < calls; ++j) {
                s.notify();
            }

            cout << "Sleep" << this_thread::get_id() << endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        cout << "Exiting demo " << this_thread::get_id() << endl;
        running = false;
        s.notify();

        t.join();
    }

};








