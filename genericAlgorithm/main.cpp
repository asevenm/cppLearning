//
//  main.cpp
//  genericAlgorithm
//
//  Created by 罗林峰 on 2018/8/13.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

void countTimes() {
    vector<int> vi;
    for(int i; cin >> i; vi.push_back(i)) {};
    int j = 5;
    cout << j << "occurs in vi " << count(vi.cbegin(), vi.cend(), j) << " times" << endl;
}

void accumulateSum() {
    vector<int> vi{1, 3, 5, 7};
    auto sum = accumulate(vi.cbegin(), vi.cend(), 0);
    cout << sum << endl;
}

void rest() {
    vector<int> vi;
    vector<int> vi2{1, 2, 3, 4, 5};
    fill_n(vi2.begin(), vi2.size(), 0);
    fill_n(back_inserter(vi), 10, 0);
    cout << "vi: " << " ";
    for(const auto i: vi)
        cout << i << " ";
    cout << endl;
    cout << "vi2: " << " ";
    for(const auto i: vi2)
        cout << i << " ";
    cout << endl;
    
}

ostream &print(ostream &os, const vector<string> &vs) {
    for(const auto &s: vs)
        os << s << " ";
    os << endl;
    return os;
}

ostream &print(ostream &os, const vector<int> &vi) {
    for(const auto &i: vi)
        os << i << " ";
    os << endl;
    return os;
}

void elimDups(vector<string> &vi) {
    // vector<int> vi{1, 2, 2, 4, 3, 4, 5, 8, 9, 5, 6, 5};
    sort(vi.begin(), vi.end());
    cout << "before unique: " << " ";
    print(cout, vi);
    auto it = unique(vi.begin(), vi.end());
    cout << "after unique:" << " ";
    print(cout, vi);
    vi.erase(it, vi.end());
    cout << "after erase:" << " ";
    print(cout, vi);
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

bool isLonger5(const string &s, vector<string>::size_type sz) {
    return s.size() >= sz;
}

auto f = [](const int i1, const int i2) { return i1 + i2; };

int calcuSum(const int i, const int i2) {
    auto f = [i](const int i3) { return i + i3; };
    return f(i2);
}

void biggies(vector<string> &vs, vector<string>::size_type sz) {
    elimDups(vs);
    stable_sort(vs.begin(), vs.end(),
                [](const string &a, const string &b)
                    { return a.size() < b.size(); });
    auto wc = partition(vs.begin(), vs.end(),
                        [sz](const string s)
                            { return s.size() < sz; });
    auto count = vs.end() - wc;
    cout << count << " words of length " << sz << " or longer " << endl;
    
    auto count2 = count_if(vs.begin(), vs.end(),
                           [sz](const string &s)
                           {return s.size() > sz;});
    cout << count2 << " words of length " << sz << " or longer " << endl;
    
    auto count3 = count_if(vs.begin(), vs.end(), bind(isLonger5, _1, sz));
    cout << count3 << " words of length " << sz << " or longer " << endl;
    
    for_each(vs.begin(), vs.end(),
             [](const string &s)
                { cout << s << " ";});
    cout << endl;
}

void uniqueCopy(vector<int> &vi1, vector<int> &vi2, vector<int> &vi3, vector<int> &vi4) {
    sort(vi1.begin(), vi1.end());
    unique_copy(vi1.cbegin(), vi1.cend(), back_inserter(vi2));
    // unique_copy(vi1.begin(), vi1.end(), front_inserter(vi3));
    unique_copy(vi1.cbegin(), vi1.cend(), inserter(vi4, vi4.end()));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // countTimes();
    // accumulateSum();
    // rest();
    // elimDups();
    
    /*vector<string> vs{
        "this", "is", "cpp", "now", "demo", "is", "I", "am", "learning", "generic", "algorithm", "now"
    };
    elimDups(vs);
    stable_sort(vs.begin(), vs.end(), isShorter);
    print(cout, vs) << endl;
    
    auto ptr = partition(vs.begin(), vs.end(), isLonger5);
    for(auto i = vs.cbegin(); i != ptr; ++i)
        cout << *i << " ";
    cout << endl;*/
    
    // cout << f(1, 2) << endl;
    // cout << calcuSum(3, 4) << endl;
    
    /*vector<string> vs{
        "this", "is", "cpp", "now", "demo", "is", "I", "am", "learning", "generic", "algorithm", "now"
    };
    biggies(vs, 5);*/
    
    /*int n = 5;
    auto isZero = [&n]() -> bool {
        --n;
        return n > 0 ? false : true;
    };
    while(!isZero()) {
        cout << n << endl;
    }*/
    
    vector<int> vi1 {1, 3, 4, 5, 6, 3, 4, 7, 5};
    vector<int> vi2;
    vector<int> vi3;
    vector<int> vi4;
    uniqueCopy(vi1, vi2, vi3, vi4);
    print(cout, vi2);
    print(cout, vi3);
    print(cout, vi4);
    return 0;
}
