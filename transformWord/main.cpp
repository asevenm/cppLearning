//
//  main.cpp
//  transformWord
//
//  Created by 罗林峰 on 2018/9/18.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1); // 删除空格
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m) {
    auto map_it = m.find(s);
    if (map_it != m.end())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input, ofstream &out) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                out << " ";
            out << transform(word, trans_map);
        }
        out << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (argc < 2) {
        cout << "Useage: 11.33 <dict filename> [<input filename>] "
        "[<output filename>]" << endl;
        return -1;
    }
    
    ifstream in_dict(argv[1]);
    if (!in_dict.is_open()) {
        cerr << "Cannot open file: " << argv[1] << endl;
        return -2;
    }
    
    ifstream in_text(argv[2]);
    if (!in_text.is_open()) {
        std::cerr << "Cannot open file: " << argv[2] << std::endl;
        return -2;
    }
    
    ofstream out(argv[3]);
    if (!out.is_open()) {
        cerr << "Cannot open file: " << argv[2] << endl;
        return -3;
    }
    
    word_transform(in_dict, in_text, out);
    return 0;
}
