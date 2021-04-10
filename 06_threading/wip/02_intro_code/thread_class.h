#ifndef THREAD_CLASS_H
#define THREAD_CLASS_H

#include <iostream>
#include <thread>

using namespace std;

class ThreadClass {

    static void print_hello() {
        cout << "Hello, thread form a class!" << endl;
    }

public:
    void hello() {
        thread t(ThreadClass::print_hello);
        t.join();
    }
};

#endif
