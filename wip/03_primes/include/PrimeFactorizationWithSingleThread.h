#ifndef PRIMEFACTORIZATIONWITHSINGLETHREAD_H
#define PRIMEFACTORIZATIONWITHSINGLETHREAD_H

#include "PrimeFactorization.h"

#include <thread>

using namespace std;

class PrimeFactorizationWithSingleThread : public PrimeFactorization
{
    public:
        void launch(uint64_t p_num);

        static void _thread_func(PrimeFactorizationWithSingleThread *p);

        PrimeFactorizationWithSingleThread();
        virtual ~PrimeFactorizationWithSingleThread();

        thread *t;
};

#endif // PRIMEFACTORIZATIONWITHSINGLETHREAD_H
