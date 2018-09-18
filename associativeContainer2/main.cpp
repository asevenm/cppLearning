//
//  main.cpp
//  associativeContainer2
//
//  Created by 罗林峰 on 2018/9/13.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

map<string, size_t> counter() {
    map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        auto ret = word_count.insert(make_pair(word, 1));
        if (!ret.second)
            ++ret.first->second;
    }
    return word_count;
}

void print(map<string, size_t> &word_count) {
    for(const auto &wc: word_count)
        cout << wc.first << " ocours " << wc.second
        << (wc.second > 1 ? " times" : " time") << endl;
}

void print(const multimap<string, vector<string>> &families) {
    for(const auto &family: families)
        for (const auto &child: family.second)
            cout << family.first << " " << child << endl;
}

void addFamily(multimap<string, vector<string>> &families, const string &firstName) {
    families.insert({ firstName, vector<string>()});
}

void addChildren(multimap<string, vector<string>> &families, const string &firstName, const string &lastName) {
    auto it = families.find(firstName);
    if (it != families.end())
        it->second.push_back(lastName);
    else
        cerr << "no family named <" << firstName << ">" << endl;
}

void familyProgram() {
    multimap<string, vector<string>> families;
    addFamily(families, "luo");
    addFamily(families, "wang");
    addChildren(families, "luo", "linfeng");
    addChildren(families, "wang", "dan");
    addChildren(families, "zhao", "jiamin");
    print(families);
}

void findAndDelete(multimap<string, vector<string>> &autorBooks, const string &author) {
    auto it = autorBooks.find(author);
    if (it != autorBooks.end()) 
        autorBooks.erase(it);
    else
        cerr << "No author named<" << author << ">" << endl;
}

void print(multimap<string, vector<string>> &authorBooks) {
    for(const auto &item: authorBooks) {
        cout << item.first << ": ";
        for(const auto &book: item.second)
            cout << book << ", ";
        cout << endl;
    }
}

void authorAndBooks() {
    multimap<string, vector<string>> authorBooks;
    authorBooks.insert({"aseven", vector<string>{"book1", "book2"}});
    authorBooks.insert(make_pair("careless", vector<string>{"book3", "book4"}));
    authorBooks.insert(pair<string, vector<string>>("test", vector<string>{"book5", "book6"}));
    findAndDelete(authorBooks, "test");
    findAndDelete(authorBooks, "test2");
    print(authorBooks);
}

void wordCount() {
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w: word_count) {
        cout << w.first << "ocurrs "
        << w.second << " " << (w.second > 1 ? "times" : "time") << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    auto counts = counter();
//    print(counts);
    
    // familyProgram();
//    authorAndBooks();
    wordCount();
    return 0;
}
