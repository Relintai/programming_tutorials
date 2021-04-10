#ifndef PRIMEFACTORIZATIONWITHSINGLETHREAD_H
#define PRIMEFACTORIZATIONWITHSINGLETHREAD_H

//Öröklődésnél itt kell includeolni! A .cpp ből nem fog működni!
#include "PrimeFactorization.h"

#include <thread>

using namespace std;

class PrimeFactorizationWithSingleThread : public PrimeFactorization
{
    public:
        thread *t;

        void launch(uint64_t p_num);

        static void _thread_func(PrimeFactorizationWithSingleThread *c);

        PrimeFactorizationWithSingleThread();
        virtual ~PrimeFactorizationWithSingleThread();

    protected:

    private:
};

#endif // PRIMEFACTORIZATIONWITHSINGLETHREAD_H
