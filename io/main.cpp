//
//  main.cpp
//  io
//
//  Created by 罗林峰 on 2018/8/6.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

istream &read(istream &is) {
    is.clear();
    string str;
    while(is >> str) {
        cout << str << " ";
    }
    cout << endl;
    is.clear();
    return is;
}

vector<string> saveLine(const string &file) {
    vector<string> str;
    ifstream in(file);
    if(in) {
        for(string s; getline(in, s);)
            str.push_back(s);
    } else {
        cerr << "fail open file: " << file << endl;
    }
    return str;
}

vector<string> saveWord(const string &file) {
    vector<string> str;
    ifstream in(file);
    if(in) {
        string s;
        while(in >> s)
            str.push_back(s);
    } else {
        cerr << "fail open file: " << file << endl;
    }
    return str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string filename;
    cin >> filename;
    // auto str = saveLine(filename);
    auto str = saveWord(filename);
    for (decltype(str.size()) i = 0; i != str.size(); ++i)
        cout << i + 1 << "\t: " << str[i] << endl;
    // read(cin);
    return 0;
}
