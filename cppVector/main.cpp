//
//  main.cpp
//  cppVector
//
//  Created by 罗林峰 on 2018/6/24.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, const char * argv[]) {
    /*int item;
    vector<int> arrs;
    while(cin >> item) {
       arrs.push_back(item);
    }*/
    
    /*vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<int> v6{10};
    vector<string> v7{10, "hi"};
    cout << "v1 content" << " ";
    for(auto c: v1)
        cout << c << ",";
    cout << "v1 size:" << v1.size() << endl;
    cout << "v2 content" << " ";
    for(auto c: v2)
        cout << c << " ,";
    cout << "v2 size" << v2.size() << endl;*/
    
    /*vector<string> str;
    string s;
    while(cin >> s)
        str.push_back(s);
    for(auto &c : str){
        for(auto &i: c)
            i = toupper(i);
    }
    for(auto c: str)
        cout << c << endl;*/
    
    vector<int> arr;
    int i;
    while(cin >> i)
        arr.push_back(i);
//    for(decltype(arr.size()) index = 0; index < arr.size() - 1; ++index)
//        cout << arr[index] + arr[index+1] << " " << endl;
    for(decltype(arr.size()) index = 0; index <= arr.size() / 2; ++index)
        cout << arr[index] + arr[arr.size() - index - 1] << " " << endl;
    return 0;
}
