//
//  fact.cpp
//  cppFunctionPointer
//
//  Created by 罗林峰 on 2018/7/13.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include "fact.hpp"
#include <iostream>

int test(int a, int b) {
    std::cout << "called test(int " << a <<", int " << b << ")" << std::endl;
    return 0;
}

int test2(int a, int b) {
    std::cout << "called test2(int" << a << ", int" << b << ")" << std::endl;
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int reduce(int a, int b) {
    return a - b;
}

int multiple(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}
