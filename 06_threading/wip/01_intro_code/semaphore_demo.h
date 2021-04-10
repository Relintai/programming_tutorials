#ifndef SEMAPHORE_DEMO_H
#define SEMAPHORE_DEMO_H

#include <iostream>
#include <thread>
#include <functional>
#include <chrono>

#include <stdlib.h>
#include <time.h>

#include "semaphore.h"


using namespace std;

class SemaphoreDemo {
    Semaphore s;
    bool running;

    static void run(SemaphoreDemo *p) {
        p->calculate();
    }

    void calculate() {
        while (running) {
            //"számolás"
            this_thread::sleep_for(chrono::milliseconds(10));

            s.wait();
        }
    }

public:

    void demo() {
        thread t(SemaphoreDemo::run, this);

        srand(time(NULL));

        for (int i = 0; i < 4; ++i) {
            cout << "Main thread notif" << endl;

            int calls = rand() % 4 + 1;

            for (int j = 0; j < calls; ++j) {
                s.notify();
            }

            cout << "Main thread sleep" << endl;

            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        cout << "Exiting demo" << endl;

        running = false;
        s.notify();

        t.join();
    }


};

#endif
