//
//  StrBlobPtr.hpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/29/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef StrBlobPtr_hpp
#define StrBlobPtr_hpp

#include <stdio.h>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlob;

class StrBlobPtr {
public:
    typedef vector<string>::size_type size_type;
    
    StrBlobPtr();
    explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);
    
    string &deref() const;
    StrBlobPtr &inc();
private:
    weak_ptr<vector<string>> wptr;
    size_type curr;
    shared_ptr<vector<string>> check(size_type pos, const string &string) const;
};

#endif /* StrBlobPtr_hpp */
