//
//  QueryResult.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/20/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "QueryResult.hpp"
#include "StrBlobPtr.hpp"

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " ocucurs " << qr.lines->size() << " "
    << (qr.lines->size() > 1 ? "times" : "time") << endl;
    for (auto num: *qr.lines)
//        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
        os << "\t(line " << num + 1 << ") " << StrBlobPtr(*qr.file, num).deref() << endl;
    return os;
}
