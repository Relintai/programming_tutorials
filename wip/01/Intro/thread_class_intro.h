#include <iostream>
#include <thread>

using namespace std;

class ThreadClassintro {

    static void hello()
    {
        cout << "Hello Class World yay" << endl;
    }

    public:

    int intro()
    {
        thread t(ThreadClassintro::hello);
        t.join();

        return 0;
    }
};
