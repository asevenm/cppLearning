//
//  main.cpp
//  cppDynamicParams
//
//  Created by 罗林峰 on 2018/7/10.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <initializer_list>
#include <vector>

int addSum(std::initializer_list<int> li) {
    int sum = 0;
    //li.begin() or li.end() will return const int *
    //s is const int &, since element in li is const int
    for(auto &s: li)
        sum += s;
    return sum;
}
int addSumN(std::initializer_list<int> li) {
    int sum = 0;
    for(const int *beg = li.begin(); beg != li.end(); ++beg)
        sum += *beg;
    return sum;
}

void print(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
#ifndef NDEBUG
    std::cout << "in function: " << __func__ << ", "
    << "time: " << __DATE__ << __TIME__ << ", "
    << "vector size: " << end - beg << std::endl;
#endif
    if(beg == end)
        return;
    std::cout << *beg << std::endl;
    print(beg + 1, end);
}

inline bool isShorter(const std::string &a, const std::string &b) {
    return a.size() < b.size();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*int sum = addSum({2, 4, 6, 8});
    int sumN = addSumN({2, 4, 6, 8});
    std::cout << sum << std::endl;
    std::cout << sumN << std::endl;*/
    
    std::vector<int> arr = {1, 3, 4, 5, 8};
    print(arr.begin(), arr.end());
    
    /*std::string a = "wang dan";
    std::string b = "luo lin feng";
    std::cout << (isShorter(a, b) ? "a < b" : "b < a") << std::endl;*/
    
    std::string s;
    while(std::cin >> s && s != "sought")
        std::cout << s << std::endl;
    //assert(std::cin);
    return 0;
}
