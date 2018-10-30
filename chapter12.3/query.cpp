//
//  query.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/28/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "query.hpp"

void runQueryWithoutClass(ifstream &is) {
    typedef vector<string>::size_type line_no;
    vector<string> file;
    map<string, set<line_no>> wordLines;
    initText(is, file, wordLines);
    cout << "Enter the word for look, or 'q' to exit: " << endl;
    while(true) {
        string sought;
        if (!(cin >> sought) || sought == "q")
            break;
        auto it = wordLines.find(sought);
        if (it == wordLines.end()) {
            cout << sought << " occurs 0 time" << endl;
            continue;
        }
        auto size = it->second.size();
        cout << sought << " occurs " << size << (size > 1 ? "times" : " time") << endl;
        for (auto num: it->second)
            cout << "\t(line " << num + 1 << ") " << *(file.begin() + num) << endl;
    }
}

void initText(ifstream &is, vector<string> &file, map<string, set<line_no>> &wordLines) {
    string text;
    while(getline(is, text)) {
        file.push_back(text);
        line_no n = file.size() - 1;
        istringstream line(text);
        string word;
        while(line >> word) {
            wordLines[word].insert(n);
        }
        
    }
}




