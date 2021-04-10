#ifndef THREAD_CREATION_H
#define THREAD_CREATION_H


#include <iostream>
#include <thread>

using namespace std;

void hello_thread() {
    cout << "Hello, thread!" << endl;
}

void create_thread() {
    thread t(hello_thread);
    t.join();
}

#endif
