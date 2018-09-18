//
//  main.cpp
//  associativeContainer1
//
//  Created by 罗林峰 on 2018/8/29.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <utility>

using namespace std;

typedef map<string, vector<string>> family_type;
typedef map<string, vector<pair<string, string>>> family_type_new;

string trimStr(string s) {
    constexpr char *punctuations{"\"'`:*-_;,.?!()[]{}"};
    for(auto &c: s)
        c = tolower(c);
    size_t beg = s.find_first_not_of(punctuations);
    if(beg == string::npos)
        return " ";
    size_t end = s.find_last_not_of(punctuations);
    return s.substr(beg, end - beg + 1);
}

void counter() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[trimStr(word)];
    for(const auto &w: word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time" ) << endl;
}

void addFamily(family_type &families, const string &firstName) {
    auto res = families.insert({firstName, vector<string>()});
    if(!res.second)
        cerr << " Already has family <" << firstName << ">" << endl;
}

void addFamily(family_type_new &families, const string &firstName) {
    auto res = families.insert({ firstName, vector<pair<string, string>>()});
    if(!res.second)
        cerr << " Already has family <" << firstName << ">" << endl;
}

void addChild(family_type &families, const string &firstName, const string &lastName) {
    auto it = families.find(firstName);
    if(it != families.end())
        it->second.push_back(lastName);
    else
        cerr << " no family named: " << firstName << endl;
}

void addChild(family_type_new &families, const string &firstName, const string &lastName, const string &birthday) {
    auto it = families.find(firstName);
    if(it != families.end()) {
        pair<string, string> p(lastName, birthday);
        it->second.push_back(p);
    } else
        cerr << " no family named: " << firstName << endl;
}

void print(family_type &families) {
    for(const auto &family: families)
        for(const auto &name: family.second)
            cout << family.first << " " << name << endl;
}

void print(family_type_new &families) {
    for(const auto &family: families)
        for(const auto &child: family.second)
            cout << family.first << " " << child.first << " " << child.second << endl;
}

void elimDups(vector<string> &words) {
    sort(words. begin(), words.end());
    auto unique_iter = unique(words.begin(), words.end());
    words.erase(unique_iter, words.end());
}

void wordsLines() {
    map<string, list<int>> words{
        {"luo", {1, 3, 5}}, {"wang", {2, 4, 6}}
    };
    for(const auto &w: words) {
        cout << w.first << " occurs at: ";
        for(const auto &l: w.second) {
            cout << l << " ";
        }
        cout << endl;
    }
}

void savePair() {
    vector<pair<string, int>> vp;
    string w;
    int i;
    while(cin >> w >> i) {
        // pair<string, int> p{w, i};
        // pair<string, int> p = {w, i};
        auto p = make_pair(w, i);
        vp.push_back(p);
    };
    for(const auto &v: vp) {
        cout << v.first << v.second << endl;
    }
}

void copyDemo() {
    multiset<string> ms = {"luo", "wang"};
    vector<string> vs = {"lin"};
    copy(ms.begin(), ms.end(), inserter(vs, vs.end()));
    for(const auto &s: vs)
        cout << s << " ";
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // counter();
    
    /*family_type families;
    addFamily(families, "luo");
    addFamily(families, "wang");
    addFamily(families, "luo");
    // print(families);
    addChild(families, "luo", "tunan");
    addChild(families, "wang", "dan");
    print(families);*/
    
    family_type_new families_new;
    addFamily(families_new, "luo");
    addFamily(families_new, "wang");
    addChild(families_new, "luo", "linfeng", "0906");
    addChild(families_new, "wang", "dan", "don't know");
    print(families_new);
    
    // wordsLines();
    
    // savePair();
    
    copyDemo();
    return 0;
}
