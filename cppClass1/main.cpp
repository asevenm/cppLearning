//
//  main.cpp
//  cppClass1
//
//  Created by 罗林峰 on 2018/7/14.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, const char * argv[]) {
    Sales_data total;
    double price;
    if(cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            if(total.bookNo == trans.bookNo) {
                trans.revenue = trans.units_sold * price;
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << total.bookNo << " "
                << total.units_sold << " "
                << total.revenue << " "
                << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " "
        << total.units_sold << " "
        << total.revenue << " "
        << endl;
    } else {
        std::cerr << "no data!" << endl;
        return -1;
    }
    return 0;
}
