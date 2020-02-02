//
//  main.cpp
//  MessageAndFolder
//
//  Created by 罗林峰 on 11/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include "Message.hpp"
#include "Folder.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    Folder f1, f2;
    Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");
    
    m1.save(f1); m2.save(f1); m5.save(f1);
    m3.save(f2); m4.save(f2); m5.save(f2);
    std::cout << "\n===== Message save =====\n";
    f1.print(); f2.print(); std::cout << std::endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();
    
    swap(m1, m3);
    std::cout << "\n===== Message swap =====\n";
    f1.print(); f2.print(); std::cout << std::endl;
    m1.print(); m3.print();
    
    return 0;
}
 
