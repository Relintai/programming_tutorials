#include <iostream>

#include "simple_threaded_prime_factorization.h"

#include "01_first_prime_threaded.h"
#include "02_first_prime_thread_class.h"
#include "03_simple_prime_finder.h"
#include "04_prime_finder.h"

using namespace std;

void basic_prime_demo()
{
    for (uint32_t i = 5; i < 15; ++i)
    {
        cout << i << "->" << (is_prime(i) ? "p" : "np") << ", ";
    }

    cout << endl;
}

void first_prime_threaded_demo()
{
    FirstPrimeThreaded p;

    p.search(955555555, 955555995);
}

void first_prime_thread_class_demo()
{
    FirstPrimeThreadClass f;

    f.search(955555555, 955555655);
}

void simple_prime_finder_demo()
{
    SimplePrimeFinder f;

    f.search(500, 530);
}

void prime_finder_demo()
{
    PrimeFinder p;
    p.search(955555555, 955555655);
}

int main()
{
    //basic_prime_demo();
    //first_prime_threaded_demo();
    //first_prime_thread_class_demo();
    //simple_prime_finder_demo();
    prime_finder_demo();

    return 0;
}
