//
//  main.cpp
//  ioSStream
//
//  Created by 罗林峰 on 2018/8/7.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

istream &read(istream &is) {
    is.clear();
    string s;
    while(is >> s)
        cout << s << " " << endl;
    is.clear();
    return is;
}

struct PersonInfo {
    string name;
    vector<string> phones;
};

constexpr int kPhoneNumberLength = 11;
bool valid(const string &phone) {
    if(phone.size() != kPhoneNumberLength)
        return false;
    for(const auto &s: phone)
        if(s < '0' || s > '9')
            return false;
    return true;
}

string format(const string &phone) {
    return phone.substr(0, 3) + "-" + phone.substr(3, 4) + "-" + phone.substr(7, 4);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*string str;
    getline(cin, str);
    istringstream iss(str);
    read(iss);*/
    
    
    /*string filename;
    cin >> filename;
    ifstream in(filename);
    if(!in) {
        cerr << "Fail to open file: " << filename << endl;
        return -1;
    }
    vector<string> vs;
    string line;
    while(getline(in, line))
        vs.push_back(line);
    for(auto &e: vs) {
        istringstream iss(e);
        read(iss);
    }*/
    
    string filename;
    cin >> filename;
    ifstream in(filename);
    if(!in) {
        cerr << "Failed to open file: " << filename << endl;
        return -1;
    }
    istringstream iss;
    string line, word;
    vector<PersonInfo> people;
    while(getline(in, line)) {
        iss.clear();
        iss.str(line);
        PersonInfo info;
        iss >> info.name;
        while(iss >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    string outputFile;
    cin >> outputFile;
    ofstream out(outputFile, ofstream::app);
    for(const auto &entry: people) {
        ostringstream formatted, badNums;
        for(const auto &nums: entry.phones) {
            if(!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if(badNums.str().empty())
            out << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
