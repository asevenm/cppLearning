//
//  StrBlob.cpp
//  chapter12.19
//
//  Created by 罗林峰 on 10/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type pos, const string &msg) const {
    if (pos >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty blob");
    data->pop_back();
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front on const empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}
