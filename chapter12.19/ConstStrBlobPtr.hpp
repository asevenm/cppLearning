//
//  ConstStrBlobPtr.hpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/13/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef ConstStrBlobPtr_hpp
#define ConstStrBlobPtr_hpp

class StrBlob;

#include <stdio.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ConstStrBlobPtr {
public:
    typedef vector<string>::size_type size_type;
    
    ConstStrBlobPtr();
    explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos = 0);
    
    const string &deref() const;
    ConstStrBlobPtr &inc();
    
private:
    weak_ptr<vector<string>> wptr;
    size_type curr;
    
    shared_ptr<vector<string>>
    check(size_type pos, const string &msg) const;
};



#endif /* ConstStrBlobPtr_hpp */
