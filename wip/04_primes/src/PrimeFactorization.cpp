#include "PrimeFactorization.h"

#include <iostream>

using namespace std;

void PrimeFactorization::launch(uint64_t p_num)
{
    num = p_num;

    check();
}
void PrimeFactorization::check()
{
    finished = false;

    is_prime = true;

    for (uint64_t i = 2; i < num; ++i) {
        if (num % i == 0) {
            is_prime = false;
            finished = true;
            return;
        }
    }

    finished = true;
}
void PrimeFactorization::print()
{
    cout << num << "->" << (is_prime ? "p" : "np") << ", ";
}

PrimeFactorization::PrimeFactorization()
{
    finished = true;
    is_prime = false;
    num = 0;
}

PrimeFactorization::~PrimeFactorization()
{
}
