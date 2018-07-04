//
//  main.cpp
//  cppString
//
//  Created by 罗林峰 on 2018/6/23.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::getline;

int main(int argc, const char * argv[]) {
    // insert code here...
    // 输出一行
    /*while(getline(cin, str))
        cout << str << endl;*/
    
    //一次输入一个词
    /*while(cin >> str)
        cout << str << endl;*/
    
    //比较字符串的大小
    /*string str1, str2;
    cin >> str1 >> str2;
    if(str1 >= str2)
        cout << str1 << endl;
    else
        cout << str2 <<endl;*/
    
    //比较两个字符串的长度
    /*string str1, str2;
    cin >> str1 >> str2;
    if(str1.size() > str2.size())
        cout << str1 << endl;
    else
        cout << str2 << endl;*/
    
    //输入多个字符串并输出
    /*string str;
    string res;
    while(cin >> str)
        res += str + " ";
    cout << res << endl;*/
    
    //字符串操作
    /*string str("I love wangdan");
    for(auto &c: str)
        c = 'X';
    cout << str << endl;*/
    /*string str("I, love wangdan!");
    string res;
    for(decltype(str.size()) index = 0; index != str.size(); ++index)
        if(!ispunct(str[index])){
            res += toupper(str[index]);
        }
    
    cout << res << endl;*/
    string str = "I love wangdan";
    decltype(str.size()) i = 0;
    while( i != str.size()) {
        str[i] = 'X';
        ++i;
    }
    cout << str << endl;
    return 0;
}
