//
//  StrBlob.hpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef StrBlob_hpp
#define StrBlob_hpp

class StrBlobPtr;
class ConstStrBlobPtr;

#include <stdio.h>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

using namespace std;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    
    size_type size() const { return data->size(); }
    bool empty() const { return data-> empty(); }
    
    void push_back(const string &s);
    void pop_back();
    
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    
    StrBlobPtr begin();
    StrBlobPtr end();
    
private:
    shared_ptr<vector<string>> data;
    void check(size_type pos, const string &msg) const;
};

inline void StrBlob::push_back(const string &s) {
    data->push_back(s);
}

#endif /* StrBlob_hpp */
