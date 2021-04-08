#ifndef PSDATA_H
#define PSDATA_H

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class PSData
{
public:
    uint64_t rmin;
    uint64_t rmax;
    bool finished;
    vector<bool> results;
    thread *t;

    static void _thread_func(PSData *data);

    bool is_prime(uint64_t num);

    void work();

    void start(uint64_t p_min, uint64_t p_max);
    void print();

    PSData();
    virtual ~PSData();
};


#endif // PSDATA_H
