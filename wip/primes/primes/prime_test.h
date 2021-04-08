#ifndef PRIME_TEST_H
#define PRIME_TEST_H

bool is_prime(uint32_t num) {
    for (uint32_t i = 2; i < num; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

#endif // PRIME_TEST_H
