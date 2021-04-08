#include "PrimeFactorizationWithSingleThread.h"

void PrimeFactorizationWithSingleThread::launch(uint64_t p_num)
{
    num = p_num;

    if (t)
    {
        t->join();
        delete t;
    }

    t = new thread(PrimeFactorizationWithSingleThread::_thread_func, this);
}

void PrimeFactorizationWithSingleThread::_thread_func(PrimeFactorizationWithSingleThread *c)
{
    c->check();
}

PrimeFactorizationWithSingleThread::PrimeFactorizationWithSingleThread() : PrimeFactorization()
{
    t = nullptr;
}

PrimeFactorizationWithSingleThread::~PrimeFactorizationWithSingleThread()
{
    if (t)
    {
        t->join();
        delete t;
    }
}
