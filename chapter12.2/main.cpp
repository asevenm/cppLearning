//
//  main.cpp
//  chapter12.2
//
//  Created by 罗林峰 on 10/18/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>

using namespace std;

void concatChar() {
    const char *c1 = "hello ";
    const char *c2 = "world";
    char *c3 = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(c3, c1);
    strcat(c3, c2);
    cout << c3 << endl;
    delete [] c3;
}

void concatString() {
    const string s1("hello ");
    const string s2("world");
    const string s3 = s1 + s2;
    cout << s3 << endl;
}

void saveString() {
    cout << "Input string length: " << endl;
    size_t len;
    cin >> len;
    cin.ignore();
    char *ca = new char[len + 1];
    cin.get(ca, len + 1);
    cout << ca << endl;
}

void allocateString() {
    cout << "input size: " << endl;
    allocator<string> allos;
    size_t n;
    cin >> n;
    auto const p = allos.allocate(n);
    string s;
    string *q = p;
    while(cin >> s && q != p + n)
        allos.construct(q++, s);
    for(auto pos = p; pos != q; ++pos)
        cout << *pos << endl;
    while(q != p)
        allos.destroy(--q);
    allos.deallocate(p, n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    concatChar();
    concatString();
//    saveString();
    allocateString();
    return 0;
}
