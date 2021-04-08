#include <iostream>

#include "thread_creation.h"
#include "thread_class.h"
#include "thread_class_params.h"

#include "thread_problem.h"

#include "lock_guard_demo.h"
#include "unique_lock_demo.h"

#include "semaphore_demo.h"

#include "atomic_count.h"

//thread -> thread készítés
//mutex (2 féle (c++ nál)) -> szinkronizáció v1
//atomic -> szinkronizáció v2
//semaphore/condition_variable -> threadek ideiglenes megállítása

using namespace std;

//Thread
void thread_demos() {
    create_thread();

    ThreadClass tc;
    tc.hello();

    ThreadClassParams tcp;
    tcp.demo();
}

void problem_demo() {
    ThreadProblem p;
    p.demo();
}

void mutex_demo() {
    LockGuardCount l;
    l.demo();

    UniqueLockCount l2;
    l2.demo();
}

void atomic_demo() {
    AtomicCount c;
    c.demo();
}

void semaphore_demo() {
    SemaphoreDemo d;
    d.demo();
}

int main()
{
    //thread_demos();
    //problem_demo();
    //mutex_demo();
    //atomic_demo();
    semaphore_demo();

    return 0;
}
