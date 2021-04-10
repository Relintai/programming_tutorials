#include "PrimeFactorization.h"

//érdekesség: .cpp/be includeolni amit lehet optimalizáció -> gyorsabban fog fordulni a program
//Nyilván ez hatalmas codebaseknél jön szóba, de ott sokat számíthat
#include <iostream>

//meghj:
//Ha egy fájlt nem lehet beincludeolni a .h fájlba, akkor ott előre kell deklarálni mindent, és ide a .cpp-be beincludeolni
//Pl A.h inlcudeolná B.h-t, de B.h-nak is kellene A.h!
//Entity.h-nak kell Spell.h, és Spell.hnak is kell Entity.h!
//Vagy: A.h includeolná B.h-t, B.h includeolja C.h-t, és C.h includeolja A.h-t! Kör!
//Ekkor így lehet rákeresni: forward declaration v circular dependency
//Más nyelvekben is lehet ilyenekkel probléma, és lehet, hogy nem meogldható!

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

    for (uint64_t i = 2; i < num; ++i)
    {
        if (num % i == 0)
        {
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
    //dtor
}
