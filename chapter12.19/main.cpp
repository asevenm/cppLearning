//
//  main.cpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
#include "ConstStrBlobPtr.hpp"

using namespace std;

void testStrBlob(StrBlob &sb) {
    try {
        sb.push_back("abc");
        cout << "front: " << sb.front() << " back: " << sb.back() << endl;
        sb.pop_back();
        cout << "front: " << sb.front() << " back: " << sb.back() << endl;
        sb.begin().deref() = "change";
        for (auto p = sb.begin(); ; p.inc())
            cout << "deref: " << p.deref() << endl;
    } catch (out_of_range err){
        cerr << err.what() << "out of range" << endl;
    } catch (exception err) {
        cerr << err.what() << endl;
    }
}

void testStrBlob(const StrBlob &sb) {
    try {
        cout << "front: " << sb.front() << " back: " << sb.back() << endl;
    } catch (out_of_range err) {
        cerr << err.what() << "out of range" << endl;
    } catch (exception err) {
        cerr << err.what() << endl;
    }
}

void testStrBlobPtr(StrBlobPtr &sbp) {
    try {
        sbp.deref() = "Change2";
        for (auto p = sbp; ; p.inc())
            cout << "deref: " << p.deref() << endl;
    } catch (out_of_range err) {
        cerr << err.what() << " out of range" << endl;
    } catch (exception err) {
        cerr << err.what() << endl;
    }
}

void testConstStrBlobPtr(ConstStrBlobPtr &csbp) {
    try {
//        csbp.deref() = "Change const csbp";
        for (auto p = csbp; ; p.inc())
            cout << "deref: " << p.deref() << endl;
    } catch (out_of_range err) {
        cerr << err.what() << " out of rang" << endl;
    } catch (exception err) {
        cerr << err.what() << endl;
    }
}

void readFromFile() {
    cout << "Input filename: " << endl;
    string file;
    cin >> file;
    ifstream in(file);
    if (!in.is_open()) {
        cerr << "Can't open file <" << file << ">" << endl;
    }
    StrBlob texts;
    for (string line; getline(in, line); texts.push_back(line)) {}
    StrBlobPtr p = texts.begin();
    for (StrBlob::size_type pos = 0; pos != texts.size(); ++pos, p.inc())
        cout << pos + 1 << ":\t" << p.deref() << endl;
    // for (StrBlobPtr p = texts.begin(); p != texts.back(); p.inc()) 未定义 != 操作符报错
}

int main(int argc, const char * argv[]) {
//    StrBlob sb1;
//    testStrBlob(sb1);
//    cout << endl;
//
//    StrBlob sb2{"hello", "world"};
//    testStrBlob(sb2);
//    cout << endl;
//
    const StrBlob csb1{"good", "news"};
    testStrBlob(csb1);
    cout << endl;

    const StrBlob csb2;
    testStrBlob(csb2);
    cout << endl;
    
    ConstStrBlobPtr csbp1(csb1);
    testConstStrBlobPtr(csbp1);
    cout << endl;
    

//    testStrBlob({"this", "is"});
//    cout << endl;
//
//    StrBlobPtr sbp1;
//    testStrBlobPtr(sbp1);
//    cout << endl;
//
//    StrBlobPtr sbp2(sb1);
//    testStrBlobPtr(sbp2);
//    cout << endl;
//
//    StrBlobPtr sbp3(sb2);
//    testStrBlobPtr(sbp3);
//    cout << endl;
//
//    StrBlobPtr sbp4(sb2, sb2.size());
//    testStrBlobPtr(sbp4);
//    cout << endl;
//    readFromFile();
    return 0;
}
