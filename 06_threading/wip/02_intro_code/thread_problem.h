#ifndef THREAD_PROBLEM_H
#define THREAD_PROBLEM_H

#include <iostream>
#include <thread>

using namespace std;

//Race Condition

class ThreadProblem {
    int counter;

    static void thread_func(ThreadProblem *obj) {
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
        thread t1(ThreadProblem::thread_func, this);
        thread t2(ThreadProblem::thread_func, this);

        t1.join();
        t2.join();

        cout << "Eredmeny: " << counter << " (200000 nek kellene lennie!)" << endl;
    }

    ThreadProblem () {
        counter = 0;
    }

};

#endif
