//
//  main.cpp
//  sequenceContainer
//
//  Created by 罗林峰 on 2018/8/11.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
#include <string>
#include <forward_list>
#include <vector>
#include <fstream>

using namespace std;

void dequeOperation() {
    deque<string> ds;
    string word;
    while(cin >> word)
        ds.push_back(word);
    deque<string>::const_iterator beg = ds.cbegin();
    deque<string>::const_iterator end = ds.cend();
    while(beg != end) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

void listOperation() {
    list<string> ls;
    string word;
    while(cin >> word)
        ls.push_back(word);
    list<string>::const_iterator beg = ls.cbegin();
    list<string>::const_iterator end = ls.cend();
    while(beg != end) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

void copyOperation() {
    list<int> ls = {1, 3, 5, 7, 9, 11, 13, 2, 4, 6, 8, 10};
    deque<int> odd;
    deque<int> even;
    list<int>::const_iterator beg = ls.cbegin();
    list<int>::const_iterator end = ls.cend();
    while(beg != end) {
        if(*beg % 2 == 0)
            even.push_back(*beg);
        else
            odd.push_back(*beg);
        ++beg;
    }
    for(const auto s: odd)
        cout << s << " ";
    cout << endl;
    for(const auto s: even)
        cout << s << " ";
    cout << endl;
}
void firstEle() {
    vector<int> vi = {1, 2, 3, 4, 5};
    auto v1 = vi[0];
    auto v2 = vi.front();
    auto v3 = *vi.begin();
    auto v4 = vi.at(0);
    cout << v1 << " " << v2 << " " << v3 << " " << v4 << " ";
    cout << endl;
}

void deleteOperation() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    // int *e = &ia[11];
    // vector<int> vi(ia, e);
    // list<int> li(ia, e);
    vector<int> vi(begin(ia), end(ia));
    list<int> li(begin(ia), end(ia));
    forward_list<int> fi(begin(ia), end(ia));
    
    for(const auto s: vi)
        cout << s << " ";
    cout << endl;
    for(const auto s: li)
        cout << s << " ";
    cout << endl;
    for(const auto s: fi)
        cout << s << " ";
    cout << endl;
    
    auto end1 = vi.cend();
    for(auto beg = vi.cbegin(); beg != vi.cend(); ++beg) {
        if(!(*beg % 2))
            vi.erase(beg);
    }
    auto end2 = vi.cend();
    cout << "res" << (end1 == end2) << endl;
    
    for(auto beg = li.cbegin(); beg != li.cend(); ++beg) {
        if(*beg % 2)
            li.erase(beg);
    }
    
    auto prev = fi.before_begin();
    auto cur = fi.begin();
    while(cur != fi.end()) {
        if(*cur % 2)
            cur = fi.erase_after(prev);
        else {
            prev = cur;
            ++cur;
        }
    }
    
    cout << "+++++++++++++++++++++++" << endl;
    for(const auto s: vi)
        cout << s << " ";
    cout << endl;
    for(const auto s: li)
        cout << s << " ";
    cout << endl;
    for(const auto s: fi)
        cout << s << " ";
    cout << endl;
}

void insertForwardList(forward_list<string> &fs, const string &s1, const string &s2) {
    auto prev = fs.before_begin();
    auto cur = fs.begin();
    while(cur != fs.end()) {
        if(*cur == s1) {
            fs.insert_after(prev, s2);
            break;
        } else {
            prev = cur;
            ++cur;
        }
    }
    fs.emplace_after(prev, s2);
    for(const auto &s: fs)
        cout << s << " ";
    cout << endl;
}

void vectorIncrease() {
    vector<int> vi;
    cout << "size: " << vi.size() << "\tCapacity: " << vi.capacity() << endl;
    int i;
    while(cin >> i) {
        vi.push_back(i);
        cout << "size: " << vi.size() << "\tCapacity: " << vi.capacity() << endl;
    }
}

void initString() {
    vector<char> vc = {'w', 'o', 'x', 'i', 'h', 'u', 'a', 'n', 'w', 'a', 'n', 'g', 'd', 'a', 'n'};
    string s1(vc.cbegin(), vc.cend());
    cout << s1 << endl;
}

void stringOperation(string &s, const string &oldVal, const string &newVal) {
    for(auto it = s.begin(); it < s.end() - oldVal.size() + 1;) {
        auto it2 = oldVal.cbegin();
        for(auto it3 = it; it2 != oldVal.cend(); ++it3, ++it2) {
            if(*it2 != *it3)
                break;
        }
        if(it2 == oldVal.cend()) {
            string::size_type pos = it - s.begin();
            s.erase(pos, oldVal.size());
            s.insert(pos, newVal);
            it = s.begin() + pos + newVal.size();
        } else
            ++it;
    }
}

void stringOperationTwo(string &s, const string &oldVal, const string newVal) {
    for(string::size_type pos = 0; pos != s.size() - oldVal.size();) {
        if(s.substr(pos, oldVal.size()) == oldVal) {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        } else
            ++pos;
    }
}

string stringOperationThree(const string &name, const string &prefix, const string &postfix) {
    string newName = name;
    string prev = prefix + " ";
    newName.insert(newName.cbegin(), prev.begin(), prev.end());
    newName.append(" " + postfix);
    return newName;
}

string stringOperationFout(const string &name, const string &prefix, const string &postfix) {
    string newName = name;
    string prev = prefix + " ";
    newName.insert(0, prev);
    newName.insert(newName.size(), " " + postfix);
    return newName;
}

void findStr() {
    const string s = "ab2c3d7R4E6";
    const string numbers = "0123456789";
    string::size_type pos = 0;
    while((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << " element is: " << s[pos] << endl;
        ++pos;
    }
}

void findStr_v2() {
    const string s = "ab2c3d7R4E6";
    const string numbers = "0123456789";
    string::size_type lastpos = 0;
    string::size_type pos = 0;
    while((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
        for(auto i = lastpos; i != pos; ++i)
            cout << "found number at index: " << i << " elements is: " << s[i] << endl;
        lastpos = ++pos;
    }
    for(auto i = lastpos; i != s.size(); ++i)
        cout << "found number at index: " << i << " element is: " << s[i] << endl;
}

void calculator() {
    vector<string> vs = {"1", "2", "3"};
    int sum = 0;
    for(const auto &s: vs)
        sum += stoi(s);
    cout << sum << endl;
}

bool is_not_ascender_descender(const string &s) {
    string ascender_descender{"bdfghijklpqty"};
    return s.find_first_of(ascender_descender) == string::npos;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // dequeOperation();
    // listOperation();
    // copyOperation();
    // firstEle();
    // deleteOperation();
    /*forward_list<string> fs = {"wo", "xi", "huan", "wang", "dan"};
    string s1 = "xi";
    string s2 = "hen";
    insertForwardList(fs, s1, s2);*/
    
    // vectorIncrease();
    // initString();
    
    /*string str = "I love wang dan tho I don't know much about her, I want to chat with her thru wechat";
    string tho = "tho";
    string though = "though";
    // stringOperation(str, tho, though);
    stringOperationTwo(str, tho, though);
    cout << str << endl;
    string thru = "thru";
    string through = "through";
    // stringOperation(str, thru, through);
    stringOperationTwo(str, thru, through);
    cout << str << endl;*/
    
    /*string name = "kobe";
    string prefix = "Mr";
    string postfix = "III";
    auto newName = stringOperationFout(name, prefix, postfix);
    // auto newName = stringOperationThree(name, prefix, postfix);
    cout << newName << endl;*/
    
    // findStr();
    // findStr_v2();
    // calculator();
    
    string filename;
    cin >> filename;
    ifstream in(filename);
    if(in.is_open()) {
        string longestword, word;
        while(in >> word) {
            cout << word << " " << is_not_ascender_descender(word) << endl;
            if(is_not_ascender_descender(word) && word.size() > longestword.size()) {
                longestword = word;
            }
        }
        cout << "longestword: " << longestword << endl;
        if(longestword.empty())
            cout << "there is no word contains neither ascender or descender in " << filename << endl;
        else
            cout << longestword << " find in " << filename;
    } else
        cerr << "Failed to open file: " << filename << endl;
    return 0;
}
