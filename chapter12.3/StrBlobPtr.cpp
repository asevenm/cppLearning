//
//  StrBlobPtr.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/29/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "StrBlobPtr.hpp"
#include "StrBlob.hpp"

StrBlobPtr::StrBlobPtr(): wptr(), curr() {};
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_type pos): wptr(sb.data), curr(pos) {};

shared_ptr<vector<string>> StrBlobPtr::check(size_type pos, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        runtime_error("unbound StrBlobPtr");
    if (pos > ret->size())
        throw out_of_range(msg);
    return ret;
};

string &StrBlobPtr::deref() const {
    auto sp = check(curr, "deref pass end of StrBlobPtr");
    return (*sp)[curr];
};

StrBlobPtr &StrBlobPtr::inc() {
    check(curr, "increment pass end of StrBlobPtr");
    ++curr;
    return *this;
}

