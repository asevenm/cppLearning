//
//  main.cpp
//  cppAccountClass
//
//  Created by 罗林峰 on 2018/7/22.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Account {
    friend ostream &print(ostream&, const Account&);
public:
    Account() = default;
    Account(string s): owner(s) {}
    Account(string s, double a): owner(s), amount(a) {}
    
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    string owner;
    double amount;
    static constexpr double interestRate = 0.24;
    static double initRate();
};

constexpr double Account::interestRate;

double Account::initRate() {
    return 0.1;
};

ostream &print(ostream &os, const Account &a) {
    os << a.owner << " " << a.amount << " " << a.interestRate;
    return os;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Account luo;
    print(cout, luo);
    cout << endl;
    
    Account wang("wang dan");
    print(cout, wang);
    cout << endl;
    
    Account aseven("luo lin feng", 10);
    aseven.calculate();
    print(cout, aseven);
    cout << endl;
    
    
    return 0;
}
