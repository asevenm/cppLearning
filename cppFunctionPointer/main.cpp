//
//  main.cpp
//  cppFunctionPointer
//
//  Created by 罗林峰 on 2018/7/13.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include "fact.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<int (*)(int, int)> vec;
//    vec.push_back(test);
//    vec.push_back(test2);
    vec.push_back(add);
    vec.push_back(reduce);
    vec.push_back(multiple);
    vec.push_back(divide);
    std::cout << vec[0](1, 3) << std::endl;
    std::cout <<vec[1](2, 4) << std::endl;
    std::cout << vec[2](5, 5) << std::endl;
    std::cout << vec[3](4, 2) << std::endl;
    for(auto &e: vec)
        e(9, 9);
    
    return 0;
}
