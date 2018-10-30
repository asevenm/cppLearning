//
//  TextQuery.hpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/20/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef TextQuery_hpp
#define TextQuery_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include "StrBlob.hpp"


using namespace std;

class QueryResult;
class StrBlob;

class TextQuery {
public:
//    typedef vector<string>::size_type line_no;
    typedef StrBlob::size_type line_no;
    TextQuery(ifstream &is);
    QueryResult query(const string&) const;
private:
//    shared_ptr<vector<string>> file;
    shared_ptr<StrBlob> file;
    map<string, shared_ptr<set<line_no>>> wm;
    
};

#endif /* TextQuery_hpp */
