//
//  main.cpp
//  ioIter
//
//  Created by 罗林峰 on 2018/8/27.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<string> &str) {
    for(const auto &s: str)
        cout << s << " ";
    cout << endl;
}

void saveStrings() {
    // vector<string> strs;
    string filename;
    cin >> filename;
    ifstream in(filename);
    if(in) {
        istream_iterator<string> beg(in);
        istream_iterator<string> eof;
//        while(beg != eof) {
//            strs.push_back(*beg++);
//        }
        vector<string> strs(beg, eof);
        print(strs);
    } else
        cout << "Failed to open file: " << filename << endl;
    
}

void saveInts() {
    istream_iterator<int> in(cin), eof;
    vector<int> ivs(in, eof);
    sort(ivs.begin(), ivs.end());
    ostream_iterator<int> out(cout, " ");
    // for(auto i: ivs)
    //    *out++ = i;
    
    // copy(ivs.begin(), ivs.end(), out);
    unique_copy(ivs.begin(), ivs.end(), out);
    cout << endl;
}

void cinAndCout() {
    string inFile;
    string outFile1;
    string outFile2;
    cin >> inFile >> outFile1 >> outFile2;
    ifstream in(inFile);
    if(in.is_open()) {
        ofstream out1(outFile1);
        ofstream out2(outFile2, ofstream::app);
//        int i;
//        while(in >> i) {
//            if(i % 2 == 0)
//                out2 << i << endl;
//            else
//                out1 << i << " ";
//        }
        istream_iterator<int> i_iter(in), eof;
        ostream_iterator<int> out_odd(out1, " "), out_even(out2, "\n");
        for_each(i_iter, eof, [&](int i) { i % 2 == 0 ? out_odd = i : out_even = i; });
    } else {
        cout << "Failed to open file: " << inFile << endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // saveStrings();
    // saveInts();
    cinAndCout();
    return 0;
}
