//
//  TextQuery.cpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/20/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include "StrBlob.hpp"



//TextQuery::TextQuery(ifstream &is): file(new vector<string>) {
//    string text;
//    while (getline(is, text)) {
//        file->push_back(text);
//        line_no n = file->size() - 1;
//        istringstream line(text);
//        string word;
//        while(line >> word) {
//            auto &lines = wm[word];
//            if (!lines)
//                lines.reset(new set<line_no>);
//            lines->insert(n);
//
//        }
//    }
//}

//QueryResult TextQuery::query(const string &sought) const {
//    static shared_ptr<set<line_no>> nodata(new set<line_no>);
//    auto loc = wm.find(sought);
//    if (loc == wm.end())
//        return QueryResult(sought, file, nodata);
//    else
//        return QueryResult(sought, file, loc->second);
//}

TextQuery::TextQuery(ifstream &is): file(new StrBlob), wm() {
    string text;
    while(getline(is, text)) {
        file->push_back((text));
        line_no n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
        
    }
}

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, file, nodata);
    else
        return QueryResult(sought, file, loc->second);
}
