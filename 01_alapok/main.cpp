
#include <iostream>

#include "int_vector.h"
#include "vector.h"
#include "string.h"

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

    //s
    String s;

    s.push_back('1');
    s.push_back('1');
    s += "daddaad";

    for (int i = 0; i < s.size(); ++i) {
        std::cout << s[i] << std::endl;
    }

    std::cout << s.c_str() << std::endl;

    std::cout << std::endl;

    std::cout << String("12").to_int() << std::endl;
    std::cout << String("12.43").to_float() << std::endl;

    std::cout << "asd" << std::endl;
    return 0;
}