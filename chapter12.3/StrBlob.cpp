//
//  StrBlob.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/28/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
#include "ConstStrBlobPtr.hpp"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

StrBlob::StrBlob(const StrBlob &sb):
data(make_shared<vector<strgin>>(*sb.data)) { };

StrBlob& StrBlob::operator=(const StrBlob &sb) {
    // 不需要用临时变量因为smarter 指针自动释放
    data = make_shared<vector<string>>((*sb.data));
    return *this;
}
void StrBlob::check(size_type pos, const string &msg) const {
    if (pos > data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
};

string &StrBlob::front() {
    check(0, "read front on empty Blob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "read front on const empty Blob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "read back on empty Blob");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "read back on empty const Blob");
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

