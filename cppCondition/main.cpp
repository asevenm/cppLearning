//
//  main.cpp
//  cppCondition
//
//  Created by 罗林峰 on 2018/7/3.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

bool compare(const vector<int> &arr1, const vector<int> &arr2) {
    if(arr1.size() > arr2.size()) {
        return compare(arr2, arr1);
    } else {
        for(int i = 0; i != arr1.size(); ++i) {
            if(arr1[i] != arr2[i]){
                return false;
                break;
            }
        }
        return true;
    }
}
bool isPrefix(const vector<int> &arr1, const vector<int> &arr2) {
    auto it1 = arr1.cbegin(), it2 = arr2.cbegin();
    for(; it1 != arr1.cend() && it2 != arr2.cend(); ++it1, ++it2)
        if(*it1 != *it2)
            break;
    return it1 == arr1.cend() || it2 == arr2.cend();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*vector<string> scores = {"F", "E", "D", "C", "B", "A" };
    int grades;
    cin >> grades;
    string lettergrade;
    string lettergradeNew;
    if(grades < 60)
        lettergrade = scores[0];
    else
        lettergrade = scores[(grades - 50)/10];
    cout << "lettergrade is:" << lettergrade << endl;
    
    lettergradeNew = grades < 60 ? scores[0] : scores[(grades - 50) / 10];
    cout << "lettergradeNew is:" << lettergradeNew << endl;*/
    
    /*unsigned acnt = 0, ecnt = 0, ocnt = 0, ucnt = 0, ffcnt = 0, flcnt = 0, ficnt = 0;
    bool fpresent = false;
    char str;
    while(cin >> str) {
        switch (str) {
            case 'a':
            case 'A':
                ++acnt;
                break;
            case 'e':
            case 'E':
                ++ecnt;
                break;
            case 'o':
            case 'O':
                ++ocnt;
                break;
            case 'u':
            case 'U':
                ++ucnt;
                break;
            case 'f':
                if(fpresent)
                    ++ffcnt;
                else
                    fpresent = true;
                break;
            case 'l':
                if(fpresent) {
                    ++flcnt;
                    fpresent = false;
                }
                break;
            case 'i':
                if(fpresent) {
                    ++ficnt;
                    fpresent = false;
                }
                break;
            default:
                break;
        }
    }
    cout << "acnt" << acnt << " ";
    cout << "ecnt" << ecnt << " ";
    cout << "ocnt" << ocnt << " ";
    cout << "ucnt" << ucnt << " ";
    cout << "ffcnt" << ffcnt << " ";
    cout << "flcnt" << flcnt << " ";
    cout << " ficnt" << ficnt << " ";
    cout << endl;*/
    
    /*string str;
    string tempStr;
    string maxStr;
    unsigned cnt = 0;
    unsigned tempCnt = 0;
    while(cin >> str) {
        if(tempStr == str) {
            ++tempCnt;
        } else {
            if(tempCnt > cnt) {
                cnt = tempCnt;
                maxStr = tempStr;
            }
            tempStr = str;
            tempCnt = 1;
        }
    }
    if(tempCnt > cnt) {
        cnt = tempCnt;
        maxStr = tempStr;
    }
    cout << maxStr << " " << cnt << endl;*/
    
    /*vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = {1, 2, 3, 5};
    bool res = compare(arr1, arr2);
    cout << (compare(arr1, arr2) ? "true" : "false") << endl;
    cout << (isPrefix(arr1, arr2) ? "true" : "false" ) << endl;*/
    string str1, str2;
    cout << "please enter two strings" << endl;
    cin >> str1 >> str2;
    do {
        cout << (str1.size() > str2.size() ? str2 : str1) << endl;
    } while(cin >> str1 >> str2);
    return 0;
    
}
