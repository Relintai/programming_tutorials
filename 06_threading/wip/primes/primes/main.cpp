#include <iostream>

//other changes:
//Prime.h -> moved the class to simple_threaded_prime_fact.h

//PrimeFactorizationWithMultipleThreads base constructor call
//i <

#include "prime_test.h"
#include "01_first_prime_threads.h"
#include "02_first_prime_thread_class.h"
#include "03_simple_prime_finder.h"
#include "04_prime_finder.h"
#include "05_prime_search_range.h"

#include "04_b_prime_finder_cstyle.h"
#include "05_b_prime_search_range_cstyle.h"

using namespace std;

void simple_prime_text() {
    for (uint32_t i = 5; i < 15; ++i) {
        cout << i << "->" << (is_prime(i) ? "p" : "np") << ", ";
    }

    cout << endl;
}

void first_prime_threads() {
    FirstPrimeThreads fpt;

    fpt.search(34444434, 34447994);
}

void first_prime_thread_class() {
    FirstPrimeThreadClass fpt;

    fpt.search(34444434, 34447994);
}

void simple_prime_finder_test() {
    SimplePrimeFinder f;

    f.search(9999989, 9999999);
}

void prime_finder_test() {
    PrimeFinder f;

    f.search(9959689, 9999999);
}

void prime_search_range() {
    PrimeSearchRange r;

    r.search(9959689, 9999999);
}

void simple_prime_fender_cstyle_search() {
    simple_prime_fender_search(3333, 33343);
}

void psr_cstyle_search() {
    psr_search(3333, 40);
}

int main()
{
    //first_prime_threads();
    //simple_prime_text();
    //first_prime_thread_class();
    //simple_prime_finder_test();
    //prime_finder_test();
    //prime_search_range();
    //simple_prime_fender_cstyle_search();
    psr_cstyle_search();

    return 0;
}
