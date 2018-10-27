//
//  main.cpp
//  cppFunction1
//
//  Created by 罗林峰 on 2018/7/5.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include "fact.hpp"
#include <iterator>
using std::cout;
using std::endl;
using std::cin;
using std::begin;
using std::end;


//int fact(int i) {
//    int ret = 1;
//    if(i < 1)
//        return 0;
//    while(i >= 1)
//        ret *= i--;
//    return ret;
//}
//int count_calls(int i) {
//    int j = 0;
//    static int k = 0;
//    return k++;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*int c;
    cin >> c;
    int j = fact(c);
    cout << j << endl;*/
    
    /*for(int i = 0; i != 6; ++i)
        cout << count_calls(i) << endl;*/
    
    /*6.2.1
    int a = 1, b = 2, c = 3, d = 4;
    exchange(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    cout << " and this is exchanged by reference" << endl;
    exchangeByRef(c, d);
    cout << "c:" << c << " d:" << d << endl;
    6.2.1*/
    
    /*6.17
    string str = "I love";
    bool boolret = hasCapital(str);
    cout << "this string " << (boolret ? "has " : "don't have ") << "uppercase literal" << endl;
    convertToLowercase(str);
    cout << str << endl;
    6.17*/
    
    /*6.21
    int a = 4, b = 5;
    int c = compare(a, &b);
    cout << c << endl;
    6.21*/
    
    /*6.22
    int a = 4, b = 6;
    int *c = &a, *d = &b;
    cout << c << " " << d << endl;
    exchangePtr(c, d);
    cout << c << " " << d << endl;
    exchangePtr(c, d);
    cout << c << " " << d << endl;
    6.22*/
    
    /*6.23*/
    int i = 0, j[2] = {0, 1};
    print(i);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));
    print(j);
    /*6.23*/
    return 0;
}
