
#include <iostream>

#include "int_vector.h"
#include "vector.h"

int main() {

    //iv
    IntVector iv;

    iv.push_back(123);
    iv.push_back(232);

    for (int i = 0; i < iv.size(); ++i) {
        std::cout << iv[i] << std::endl;
    }

    std::cout << std::endl;

    //v
    Vector<int> v;

    v.push_back(123);
    v.push_back(232);

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "asd" << std::endl;
    return 0;
}