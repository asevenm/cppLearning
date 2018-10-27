//
//  StrBlobPtr.cpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlobPtr::StrBlobPtr(): wptr(), curr(0) {}
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_type pos): wptr(sb.data), curr(pos) {}

shared_ptr<vector<string>>
StrBlobPtr::check(size_type pos, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (pos >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const {
    auto sp = check(curr, "defrence past end of StrBlobPtr");
    return (*sp)[curr];
}

StrBlobPtr &StrBlobPtr::inc() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
