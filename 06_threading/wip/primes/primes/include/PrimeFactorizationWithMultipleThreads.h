#ifndef PRIMEFACTORIZATIONWITHMULTIPLETHREADS_H
#define PRIMEFACTORIZATIONWITHMULTIPLETHREADS_H

#include "PrimeFactorization.h"

#include <thread>
#include <atomic>
#include <vector>

using namespace std;

class PrimeFactorizationWithMultipleThreads : public PrimeFactorization
{
    public:
        vector<thread *> _threads;
        uint64_t thread_count;
        atomic<uint64_t> thread_finished;

        void launch(uint64_t p_num);
        void check_range(uint64_t p_min, uint64_t p_max);

        static void _thread_func(PrimeFactorizationWithMultipleThreads *c, uint64_t p_min, uint64_t p_max);

        PrimeFactorizationWithMultipleThreads();
        virtual ~PrimeFactorizationWithMultipleThreads();
};

#endif // PRIMEFACTORIZATIONWITHMULTIPLETHREADS_H
