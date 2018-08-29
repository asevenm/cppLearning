//
//  main.cpp
//  reverseIterator
//
//  Created by 罗林峰 on 2018/8/29.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printReverse(vector<int> &vi) {
    for(auto beg = vi.crbegin(); beg != vi.crend(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

void print(vector<int> &vi) {
    for(auto beg = vi.begin(); beg != vi.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

void findLast0(vector<int> &vi) {
    auto pos = find(vi.crbegin(), vi.crend(), 0);
    cout << " the last 0 is at position of: " << pos.base() - vi.cbegin() - 1 << endl;
}

void reverseCopy(vector<int> &vi, vector<int> &vi2) {
    copy(vi.crbegin() + 2, vi.crend() - 3, vi2.begin());
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> vi{1, 3, 4, 2, 0, 8, 10, 5, 0, 90};
    vector<int> vi2(10, 0);
    printReverse(vi);
    print(vi);
    findLast0(vi);
    reverseCopy(vi, vi2);
    for(const auto &i: vi2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
