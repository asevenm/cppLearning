//
//  main.cpp
//  ioBookStroe
//
//  Created by 罗林峰 on 2018/8/7.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Sales_data;
istream &read(istream&, Sales_data&);

class Sales_data {
    friend istream &read(istream&, Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend ostream &print(ostream&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(string s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(istream &is) { read(is, *this); }
    
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};

istream &read(istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data &Sales_data::combine(const Sales_data &item) {
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn() < s2.isbn();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (argc < 3) {
        cerr << "Usage: <input filename> <output filename>" << endl;
        return -3;
    }
    ifstream in(argv[1]);
    if(!in) {
        cerr << "Fail to open file: " << argv[1] << endl;
        return -2;
    }
    
    if(argc >= 3) {
        
        ofstream out(argv[2]);
        // ofstream out2(argv[2], ofstream::app);
//
//        Sales_data total;
//        if(read(in, total)) {
//            Sales_data trans;
//            while(read(in, trans)) {
//                if(total.isbn() == trans.isbn()) {
//                    total.combine(trans);
//                } else {
//                    print(out2, total) << endl;
//                    total = trans;
//                }
//            }
//            print(out2, total) << endl;
//        } else {
//            cerr << "No Data!" << endl;
//            return -1;
//        }
        
        // 排序
        vector<Sales_data> vsd;
        for(Sales_data item; read(in, item); vsd.push_back(item));
//        sort(vsd.begin(), vsd.end(), compareIsbn);
        sort(vsd.begin(), vsd.end(),
             [](const Sales_data &a, const Sales_data &b) { return a.isbn() < b.isbn(); });
        for(const auto &sd: vsd)
            print(cout, sd) << endl;
    }
    return 0;
}
