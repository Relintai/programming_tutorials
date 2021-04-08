#include "PrimeFactorizationWithMultipleThreads.h"

void PrimeFactorizationWithMultipleThreads::launch(uint64_t p_num) {
    num = p_num;
    finished = false;
    is_prime = true;


    for (uint64_t i = 0; i < _threads.size(); ++i)
    {
        thread *t = _threads[i];

        if (t)
        {
            t->join();
            delete t;
        }
    }

    _threads.resize(0);

    thread_finished = 0;

    uint64_t slice = num / thread_count;

    for (uint64_t i = 0; i < thread_count; ++i) {
        uint64_t slice_start = slice * i;

        if (i == 0)
            slice_start = 2;

        uint64_t slice_end;

        if (i - 1 == thread_count)
            slice_end = num;
        else
            slice_end = slice * (i + 1);

        thread *t = new thread(PrimeFactorizationWithMultipleThreads::_thread_func, this, slice_start, slice_end);

        _threads.push_back(t);
    }
}

void PrimeFactorizationWithMultipleThreads::check_range(uint64_t p_min, uint64_t p_max)
{
    for (uint64_t i = p_min; i < p_max; ++i)
    {
        if (num % i == 0)
        {
            is_prime = false;
            finished = true;
            return;
        }

        if (finished) {
            return;
        }
    }

    thread_finished++;

    if (thread_finished == thread_count) {
        finished = true;
    }
}


void PrimeFactorizationWithMultipleThreads::_thread_func(PrimeFactorizationWithMultipleThreads *c, uint64_t p_min, uint64_t p_max) {
    c->check_range(p_min, p_max);
}

PrimeFactorizationWithMultipleThreads::PrimeFactorizationWithMultipleThreads() : PrimeFactorization()
{
    thread_count = 4;
}

PrimeFactorizationWithMultipleThreads::~PrimeFactorizationWithMultipleThreads()
{
    for (uint64_t i = 0; i < _threads.size(); ++i)
    {
        thread *t = _threads[i];

        if (t)
        {
            t->join();
            delete t;
        }
    }
}
