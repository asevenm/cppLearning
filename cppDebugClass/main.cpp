//
//  main.cpp
//  cppDebugClass
//
//  Created by 罗林峰 on 2018/7/21.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
using namespace std;

class Debug {
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
    
    constexpr bool any() const { return hw || io || other; }
    void set_hw(bool h) { hw = h; }
    void set_io(bool i) { io = i; }
    void set_other(bool o) { other = o; }
private:
    bool hw;
    bool io;
    bool other;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Debug io_sub(true);
    if(io_sub.any())
        cout << "Error message 1" << endl;
    constexpr Debug one_bug(false, false, true);
    if(one_bug.any())
        cout << "Error message 2" << endl;
    constexpr Debug set_bug = false;
    // set_bug.set_other(true); //error;
    if(set_bug.any())
        cout << "Error messaage 3" << endl;
    Debug last_bug(false);
    if(last_bug.any())
        cout << "Error message 4" << endl;
    last_bug.set_hw(true);
    if(last_bug.any())
        cout << "Error message 5" << endl;
    return 0;
}
