//
//  query.hpp
//  chapter12.3
//
//  Created by 罗林峰 on 10/28/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef query_hpp
#define query_hpp

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

typedef vector<string>::size_type line_no;

void runQueryWithoutClass(ifstream&);

void initText(ifstream &is, vector<string> &file, map<string, set<line_no>> &wordLines);


#endif /* query_hpp */
