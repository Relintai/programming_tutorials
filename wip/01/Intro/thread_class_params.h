#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class ThreadClassParams {

    static void hello_params(ThreadClassParams *p)
    {
        cout << "Hello Class Params World yay" << endl;

        p->test_obj();
    }

    void test_obj() {
        cout << "ok!" << endl;
    }

    public:

    int intro()
    {
        thread t(ThreadClassParams::hello_params, this);
        t.join();

        thread t2(&ThreadClassParams::hello_params, this);
        t2.join();


        function<void(ThreadClassParams*)> p = &ThreadClassParams::hello_params;

        thread t3(p, this);
        t3.join();

        return 0;
    }
};

