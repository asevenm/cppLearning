//
//  main.cpp
//  cppClass1.3
//
//  Created by 罗林峰 on 2018/7/14.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Sales_data;
std::istream &read(std::istream&, Sales_data&);

class Sales_data {
    friend istream &read(istream&, Sales_data&);
    friend ostream &print(ostream&,const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    //Sales_data() = default; //default constructor
    //Sales_data(): bookNo(""), unit_sold(0), revenue(0) {}; // default constructor
    Sales_data(): Sales_data("", 0, 0) {
        cout << "Sales_data() is called"
        << endl;
    }; // delegate default constructor
    
    //Sales_data(const string &no): bookNo(no) {};
    Sales_data(const string &no): Sales_data(no, 0, 0) {
        cout << "Sales_data(const string &no) is called"
        << endl;
    }
    
    Sales_data(const string &no, unsigned n, double p): bookNo(no), unit_sold(n), revenue(n * p) {
        cout << "Sales_data(const string &no, usigned n, double p) is called"
        << endl;
    };
    Sales_data(std::istream &is){
        cout << "Sales_data(istream &is) is called " << endl;
        read(is, *this);
    };
    
    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
private:
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0;
    double avg_price() const;
};

inline
double Sales_data::avg_price() const {
    return unit_sold ? revenue / unit_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data &trans) {
    unit_sold += trans.unit_sold;
    revenue += trans.revenue;
    return *this;
};

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.unit_sold >> price;
    item.revenue = item.unit_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.unit_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &a, const Sales_data &b) {
    Sales_data sum = a;
    sum.combine(b);
    return sum;
}

//Sales_data::Sales_data(std::istream &is) {
//    read(is, *this);
//}

int main(int argc, const char * argv[]) {
    Sales_data book0;
    Sales_data book1("l123");
    Sales_data book2("zhao123", 10, 5);
    Sales_data book3(cin);
    cout << " book0" << " ";
    print(cout, book0);
    cout << endl;
    cout << " book1" << " ";
    print(cout, book1);
    cout << endl;
    cout << " book2" << " ";
    print(cout, book2);
    cout << endl;
    cout << " book3" << " ";
    print(cout, book3);
    cout << endl;
    
    /*//    Sales_data total;
    Sales_data total(cin); // use the constructor which need a istream parameter
//    if(read(cin, total)) {
    if(cin) {
        Sales_data trans;
        while(read(cin, trans)) {
            if(total.isbn() == trans.isbn())
//                add(total, trans);
                total.combine(trans);
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    } else {
        std::cerr << "No data!" << endl;
        return -1;
    }*/
    return 0;
}
