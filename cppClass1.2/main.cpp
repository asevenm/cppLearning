//
//  main.cpp
//  cppClass1.2
//
//  Created by 罗林峰 on 2018/7/14.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct Sales_data {
    string bookNo;
    unsigned units_sold;
    double revenue;
    string isbn() const {
        return bookNo;
    };
    Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data &trans) {
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
};

int main(int argc, const char * argv[]) {
    Sales_data total;
    double price;
    if(cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if(total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
//                total.bookNo = trans.bookNo;
//                total.units_sold = trans.units_sold;
//                total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        cerr << "No data!" << endl;
        return -1;
    }
    return 0;
}
