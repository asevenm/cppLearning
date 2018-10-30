//
//  ConstStrBlobPtr.hpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/29/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef ConstStrBlobPtr_hpp
#define ConstStrBlobPtr_hpp

#include <stdio.h>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlob;

class ConstStrBlobPtr {
public:
    typedef vector<string>::size_type size_type;
    
    ConstStrBlobPtr();
    explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos);
    
    const string &deref() const;
    ConstStrBlobPtr &inc();
private:
    weak_ptr<vector<string>> wptr;
    size_type curr;
    shared_ptr<vector<string>> check(size_type pos, const string &msg) const;
};

#endif /* ConstStrBlobPtr_hpp */
