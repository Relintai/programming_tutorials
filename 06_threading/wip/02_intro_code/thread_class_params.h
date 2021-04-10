#ifndef THREAD_CLASS_PARAMS_H
#define THREAD_CLASS_PARAMS_H

#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class ThreadClassParams {
    private:
    int num;

    static void hello_with_params(ThreadClassParams *p) {
        cout << "ThreadClassParams: Hello World! " << endl;

        p->print_test();
    }

    void print_test() {
        cout << "ok! " << num << endl;
    }

    public:

    void demo() {
        num = 8;

        thread t(ThreadClassParams::hello_with_params, this);
        t.join();

        num = 10;

        thread t2(&ThreadClassParams::hello_with_params, this);
        t2.join();

        num = 12;

        function<void(ThreadClassParams *)> p = &ThreadClassParams::hello_with_params;

        thread t3(p, this);
        t3.join();

    }

};

#endif
