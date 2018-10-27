//
//  ConstStrBlobPtr.cpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/13/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "ConstStrBlobPtr.hpp"
#include "StrBlob.hpp"

ConstStrBlobPtr::ConstStrBlobPtr(): wptr(), curr(0) {};
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_type pos):
    wptr(sb.data), curr(pos) {};

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_type pos, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if (pos > ret->size())
        throw out_of_range(msg);
    return ret;
}

const string &ConstStrBlobPtr::deref() const {
    auto ret = check(curr, "derefrence pass end of ConstStrBlobPtr");
    return (*ret)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::inc() {
    check(curr, "increment pass end of ConstStrBlobPtr");
    ++curr;
    return *this;
}
