//
//  main.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/20/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include "query.hpp"
#include "StrBlob.hpp"

using namespace std;

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while(true) {
        cout << "Enter word to look for, or 'q' to exit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s));
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Enter the file name to look up: ";
    string filename;
    cin >> filename;
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "can not open the file: <" << filename << ">" << endl;
        return -1;
    }
    runQueries(infile);
//    runQueryWithoutClass(infile);
    
    return 0;
}
