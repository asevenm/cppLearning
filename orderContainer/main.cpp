//
//  main.cpp
//  orderContainer
//
//  Created by 罗林峰 on 2018/8/9.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int>::const_iterator beg, vector<int>::const_iterator end, const int i) {
    while(beg != end) {
        if(*beg == i) {
            return true;
            break;
        }
        ++beg;
    }
    return false;
}

vector<int>::const_iterator findIt(vector<int>::const_iterator beg, vector<int>::const_iterator end, const int i) {
    while(beg != end) {
        if(*beg == i) {
            return beg;
            break;
        }
        ++beg;
    }
    return end;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> ivc = {1, 2, 3, 4, 5, 6};
    int i = 0;
    int j = 0;
    cout << j++ << ++i << endl;
    auto res = find(ivc.cbegin(), ivc.cend(), 5);
    cout << (res ? "we find" : " we doesn't find") << endl;
    auto res2 = findIt(ivc.cbegin(), ivc.cend(), 10);
    if(res2 == ivc.cend())
        cout << "we doesn't find" << endl;
    else
        cout << "we find" << endl;
    return 0;
}
