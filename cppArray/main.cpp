//
//  main.cpp
//  cppArray
//
//  Created by 罗林峰 on 2018/6/27.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
using std::strcmp;
using std::strcat;
using std::strcpy;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

bool compare(int *const pa1, int *const pa2, int *const pb1, int *const pb2) {
    if((pa2 - pa1) != (pb2 - pb1)) {
        return false;
    } else {
        for(int *i = pa1, *j = pb1; (i != pa2) && (j != pb2); ++i, ++j) {
            if(*i != *j) return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr2[10];
    for(int i = 0; i < 10; ++ i)
        arr2[i] = arr[i];
    for(auto i: arr2)
        cout << i << " ";
    cout << endl;
    
    vector<int> v(10);
    for(auto i = 0; i < v.size(); ++i)
        v[i] = arr[i];
    vector<int> v2(v);
    for(auto s: v2)
        cout << s << " ";
    cout << endl;*/
    
    /*int arr[5] = { 1, 3, 5, 7};
    int *pbeg = arr, *pend = arr + 5;
    while(pbeg != pend) {
       *pbeg = 0;
        ++pbeg;
    }
    for(auto s: arr)
        cout << s << " ";
    cout << endl;*/
    
    /*int arr1[3] = {0, 2, 4};
    int arr2[3] = {0, 1, 4};
    if(compare(begin(arr1), end(arr1), begin(arr2), end(arr2))) {
        cout << " arr1 and arr2 are equal" << endl;
    } else {
        cout << " arr1 and arr2 are not equal" << endl;
    }
    
    vector<int> vec1(10);
    vector<int> vec2(10, 0);
    if(vec1 == vec2)
        cout << "vec1 and vec2 are equal" << endl;
    else
        cout << "vec1 and vec2 are not equal" << endl;*/
    
    /*string str1 = "luolinfeng";
    string str2 = "luolinfeng";
    if(str1 == str2)
        cout << "str1 and str2 are equal" << endl;
    else
        cout << "str1 and str2 are not equal" << endl;
    
    const char str3[] = "luolinfeng";
    const char str4[] = "luolinfeng";
    if(strcmp(str3, str4) == 0)
        cout << "str3 and str4 are equal" << endl;
    else
        cout << "str3 and str4 are not equal" << endl;*/
    
    /*const char str1[] = "luolinfeng";
    const char str2[] = "wangdan";
    char str3[100];
    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);
    cout << str3 << endl;*/
    
    /*int arr[] = {1, 3, 5, 7, 9};
    vector<int> ivec(begin(arr), end(arr));
    for(auto s: ivec)
        cout << s << " ";
    cout << endl;*/
    
    /*vector<int> ivec(10, 5);
    int arr[10];
    for(int i = 0; i < ivec.size(); ++i)
        arr[i] = ivec[i];
    for(auto s: arr)
        cout << s << " ";
    cout << endl;*/
    
    int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    using int_four = int[4];
//    for(int (&i)[4]: ia){
//        for(int s: i)
//            cout << s << " ";
//        cout << endl;
//    }
//
//
//    for(size_t i = 0; i != 3; ++i) {
//        for(size_t j = 0; j != 4; ++j)
//            cout << ia[i][j] << " ";
//        cout << endl;
//    }
//
//
//    for(int (*i)[4] = begin(ia); i != end(ia); ++i) {
//        for(int *j = *i; j != end((*i)); ++j)
//            cout << *j << " ";
//        cout << endl;
//    }
    
    for(int_four &i: ia) {
        for(int s: i)
            cout << s << " ";
        cout << endl;
    }
    
    for(int_four *i = begin(ia); i != end(ia); ++i) {
        for(int *j = begin(*i); j != end(*i); ++j)
            cout << *j << " ";
        cout << endl;
    }
    
    
    return 0;
}
