//
//  main.cpp
//  cppMainParams
//
//  Created by 罗林峰 on 2018/7/9.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str(argv[1]);
    std::cout << argv[0] << std::endl;
    std::cout << argv[argc - 1] << std::endl;
    for(size_t i = 0; i != argc; ++i) {
        if(i != 0 && i != 1)
            str += argv[i];
    }
    std::cout << str << std::endl;
    return 0;
}
