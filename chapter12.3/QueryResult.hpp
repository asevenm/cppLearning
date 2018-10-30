//
//  QueryResult.hpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/20/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef QueryResult_hpp
#define QueryResult_hpp

#include <stdio.h>
#include <istream>
#include <vector>
#include <string>
#include <set>
#include "StrBlob.hpp"

using namespace std;

class StrBlob;

class QueryResult {
    friend ostream &print(ostream&, const QueryResult&);
public:
//    typedef vector<string>::size_type line_no;l
//    QueryResult(string s, shared_ptr<vector<string>> f, shared_ptr<set<line_no>> p):
//        sought(s), file(f), lines(p){ };
    
    
    typedef StrBlob::size_type line_no;
    QueryResult(string s, shared_ptr<StrBlob> f, shared_ptr<set<line_no>> p):
        sought(s), file(f), lines(p){};
    
    set<line_no>::iterator begin() { return lines->begin(); };
    set<line_no>::iterator end() { return lines->end(); };
    
    set<line_no>::const_iterator cbegin() { return lines->cbegin(); };
    set<line_no>::const_iterator cend() { return lines->cend(); };
    
    shared_ptr<StrBlob> get_file() { return file; };
    
private:
    //    shared_ptr<vector<string>> file;
    
    string sought;
    shared_ptr<StrBlob> file;
    shared_ptr<set<line_no>> lines;
};

#endif /* QueryResult_hpp */
