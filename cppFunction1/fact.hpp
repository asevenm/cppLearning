//
//  fact.hpp
//  cppFunction1
//
//  Created by 罗林峰 on 2018/7/7.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#ifndef fact_hpp
#define fact_hpp

#include <stdio.h>
#include <string>

using std::string;

int fact(int&);
void exchange(int*, int*);
void exchangeByRef(int&, int&);
bool hasCapital(const string&);
void convertToLowercase(string&);
int compare(const int, const int*);

void exchangePtr(int*&, int*&);
void exchangePtr(int**, int**);

void print(const int);
void print(const int*beg, const int*end);
void print(const int[], size_t);
void print(const int (&arr)[2]);
#endif /* fact_hpp */
