#include <iostream>

#include "thread_intro.h"
#include "thread_class_intro.h"
#include "thread_class_params.h"

#include "thread_problem_count.h"
#include "thread_problem_cout.h"

#include "lock_guard_count.h"
#include "unique_lock_coun.h"

#include "atomic_count.h"

#include "semaphore.h"

#include "semaphore_demo.h"


using namespace std;

void thread_intros() {
    thread_intro();

    ThreadClassintro ti;
    ti.intro();

    ThreadClassParams tcp;
    tcp.intro();

    ThreadSleep ts;
    ts.demo();
}

void thread_problems() {
    ThreadProblemCount tpc;
    tpc.demo();


}

void mutexes() {
    LockGuardCount c;
    c.demo();

    uniqueLockCount u;
    u.demo();
}

void atomic_demo() {
    AtomicCount c;
    c.demo();
}

void semaphore_demo() {
    SemaphoreDemo s;

    s.demo();
}

//best: none

int main()
{
    //thread_intros();
    //thread_problems();
    //mutexes();
    //atomic_demo();
    semaphore_demo();


    return 0;
}
