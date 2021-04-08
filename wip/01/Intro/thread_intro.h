#include <iostream>
#include <thread>

using namespace std;

void hello_thread()
{
    cout << "Hello World yay" << endl;
}

int thread_intro()
{
    thread t(hello_thread);
    t.join();

    return 0;
}
