#include <mutex>
#include <condition_variable>

#define VERBOSE 1

#if VERBOSE
#include <thread>
#endif

class Semaphore {
public:
    Semaphore (int p_count = 0)
    {
        count = p_count;
    }

    inline void notify() {
        std::unique_lock<std::mutex> lock(mtx);

        count++;

#if VERBOSE
        cout << "thread " << std::this_thread::get_id() <<  " notify" << endl;
#endif

        //notify the waiting thread
        cv.notify_one();
    }

    inline void wait() {
        std::unique_lock<std::mutex> lock(mtx);

        while(count == 0) {
#if VERBOSE
            cout << "thread " << std::this_thread::get_id() << " wait" << endl;
#endif

            //wait on the mutex until notify is called
            cv.wait(lock);

#if VERBOSE
            cout << "thread " << std::this_thread::get_id() << " run" << endl;
#endif
        }

        count--;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};
