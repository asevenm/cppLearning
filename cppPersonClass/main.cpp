//
//  main.cpp
//  cppPersonClass
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
using std::istream;
using std::ostream;

class Person;
istream &read(istream&, Person&);

class Person {
    friend ostream &print(ostream&,const Person&);
    friend istream &read(istream&, Person&);
public:
    Person() = default;
    Person(const string &n): name(n) {};
    Person(const string &n, const string &a): name(n), address(a) {};
    explicit Person(istream &is) {
        read(is, *this);
    }
    string getName() const { return name; };
    string getAddress() const { return address; };
private:
    string name;
    string address;
};

std::istream &read(std::istream &is, Person &item) {
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item) {
    os << item.name << " " << item.address << " ";
    return os;
}

int main(int argc, const char * argv[]) {
    Person person;
    print(cout, person) << endl;
    Person aseven("aseven");
    Person wang("jiamin", "shanghai");
    Person luo(cin);
    print(cout, aseven) << endl;
    print(cout, wang) << endl;
    print(cout, luo) << endl;
//    while(read(cin, person)) {
//        print(cout, person);
//        cout << endl;
//    }
    return 0;
}
