#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

using namespace std;

#define VERBOSE 1

#if VERBOSE
#include <thread>
#include <iostream>
#endif

class Semaphore {
public:

    Semaphore(int p_count = 0) {
        count = p_count;
    }

    void notify() {
        unique_lock<mutex> lock(mtx);

        ++count;

#if VERBOSE
        cout << "thread " << this_thread::get_id() << " nofity" << endl;
#endif

        cv.notify_one();
    }

    void wait() {
        unique_lock<mutex> lock(mtx);

        while (count == 0) {
#if VERBOSE
        cout << "thread " << this_thread::get_id() << " wait" << endl;
#endif

            cv.wait(lock);

#if VERBOSE
        cout << "thread " << this_thread::get_id() << " run" << endl;
#endif
        }

        --count;
    }

private:
    mutex mtx;
    condition_variable cv;
    int count;
};


#endif // SEMAPHORE_H

