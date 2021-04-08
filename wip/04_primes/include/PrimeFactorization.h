#ifndef PrimeFactorization_H
#define PrimeFactorization_H

#include <cstdint>


class PrimeFactorization
{
    public:
        virtual void launch(uint64_t p_num);
        void check();
        void print();

        PrimeFactorization();
        virtual ~PrimeFactorization();

        bool is_prime;
        uint64_t num;
        bool finished;
};

#endif // PrimeFactorization_H
