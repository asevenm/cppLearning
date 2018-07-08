//
//  fact.cpp
//  cppFunction1
//
//  Created by 罗林峰 on 2018/7/7.
//  Copyright © 2018年 罗林峰. All rights reserved.
//
#include <iostream>
#include "fact.hpp"
using std::cout;
using std::endl;

int fact(int &i) {
    if(i < 1)
        return i;
    int k = i;
    while(--i)
        k *= i;
    return k;
}

void exchange(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void exchangeByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool hasCapital(const string &str) {
    for(auto &s: str) {
        if(isupper(s)) {
            return true;
            break;
        }
    }
    return false;
}

void convertToLowercase(string &str) {
    for(auto &s: str)
        s = tolower(s);
}

int compare(const int a, const int *b) {
    if(a > *b)
        return a;
    else
        return *b;
}

void exchangePtr(int *&a, int *&b) {
    int *temp = a;
    a = b;
    b = temp;
}

void exchangePtr(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void print(const int i) {
    cout << "void print(const int i):" << i << endl;
}

void print(const int *beg, const int *end) {
    cout << "void print(const int *beg, const int *end):" << endl;
    while(beg != end) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

void print(const int arr[], size_t size) {
    cout << "void print(const int arr[], size_t size): " << endl;
    for(size_t i = 0; i != size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(const int (&arr)[2]) {
    cout << "void print(const int (&arr)[2]):" << endl;
    for(size_t i = 0; i != 2; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
