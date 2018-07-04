//
//  main.cpp
//  cppIterator
//
//  Created by 罗林峰 on 2018/6/25.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, const char * argv[]) {
    // insert code here...
    /*vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<int> v6{10};
    vector<string> v7{10, "hi"};
    cout << "v1" << " ";
    for(auto it = v1.cbegin(); it != v1.cend(); ++it)
        cout << *it << ",";
    cout << "v1 size:" << v1.size() << endl;
    cout << "v2" << " ";
    for(auto it = v2.cbegin(); it != v2.cend(); ++it)
        cout << *it << ",";
    cout << " v2 size:" << v2.size() << endl;*/
    
    /*vector<string> words;
    string word;
    while(cin >> word)
        words.push_back(word);
    for(auto it = words.begin(); it != words.end() && !it->empty(); ++it) {
        for(auto &c: *it)
            if(isalpha(c))
                c = toupper(c);
    }
    for(auto it = words.cbegin(); it != words.cend() && !it->empty(); ++it)
        cout << *it << endl;*/
    
    /*vector<int> arr(10, 24);
    for(auto it = arr.begin(); it != arr.end(); ++it)
        *it = (*it) * 2;
    for(auto it = arr.cbegin(); it != arr.cend(); ++it)
        cout << *it << endl;*/
    
    /*vector<int> arr;
    int c;
    while(cin >> c)
        arr.push_back(c);
    for(auto it = arr.cbegin(); it != arr.cend() - 1; ++it) {
        auto next = it + 1;
        cout << (*it) + (*next) << endl;
    }
    
    auto beg = arr.cbegin();
    auto end = arr.cend() - 1;
    while(beg < end) {
        cout << *beg + * end << endl;
        beg++;
        end--;
    }*/
    
    vector<unsigned> scores(11, 0);
    unsigned score;
    while(cin >> score)
        ++*(scores.begin() + score / 10);
    for(auto s: scores)
        cout << s << " ";
    cout << endl;
    return 0;
    
    
}
