//
//  main.cpp
//  chapter13
//
//  Created by 罗林峰 on 11/1/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(HasPtr &hp): ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
    const string &get() const { return *ps; }
private:
    int i;
    string *ps;
};

HasPtr& HasPtr::operator=(const HasPtr &hp) {
    delete ps;
    ps = new string(*hp.ps);
    i = hp.i;
    return *this;
};

HasPtr::~HasPtr() {
    delete ps;
}

struct X {
    X() { ++i; j = i; cout << "X() " << j << endl; }
    X(const X&) { ++i; j = i; cout << "X(const X&) " << j << endl; }
    X& operator=(const X&);
    ~X();
    
    static int i;
    int j;
};

X& X::operator=(const X &x) {
    
    cout << "operator= " << j << endl;
    return *this;
}

X::~X() {
    cout << "~X() " << j << endl;
}

int X::i = 0;

void f1(X x) {};

void f2(X &x) {};

X f3() { return X(); };

X f4(X &x) { return x; };

X f5() {
    X x;
    return x;
}

void testX() {
    cout << "\n------ X x1\n";
    X x1;
    cout << "\n------ f1(x1)\n";
    f1(x1);
    cout << "\n------ f2(x1)\n";
    f2(x1);
    cout << "\n------ X x3 = f3()\n";
    X x3 = f3();
    cout << "\n------ X x4 = f4(x1)\n";
    X x4 = f4(x1);
    cout << "\n------ X x5 = f5()\n";
    X x5 = f5();
    cout << "\n------ X f5()\n";
    f5();
    cout << "\n------ X *x2 = new X\n";
    X *x2 = new X;
    cout << "\n------ vector<X> vx\n";
    vector<X> vx;
    cout << "\n------ vx.push_back(x1)\n";
    vx.push_back(x1);
    cout << "\n------ vx.push_back(*x2)\n";
    vx.push_back(*x2);
    cout << "\n------ list<X> lx\n";
    list<X> lx;
    cout << "\n------ list<X> lx.push_back(x1)\n";
    lx.push_back(x1);
    cout << "\n------ lx.push_back(x2)\n";
    lx.push_back(*x2);
    cout << "\n------ delete x2\n";
    delete x2;
    cout << "\n------- \n";
    
}

class numbered {
public:
    numbered(): mysn(++sn) {};
    numbered(const numbered&): mysn(++sn) {};
    int mysn;
    
private:
    static int sn;
};

int numbered::sn = 0;

void fNumbered(numbered s) { cout << s.mysn << endl; }

void fnumbered2(numbered &s) { cout << s.mysn << endl; }

void testNumbered1() {
    numbered a, b = a, c = b; // a.mysn = 1, b.mysn = 2, c.mysn = 3;
    fNumbered(a);
    fNumbered(b);
    fNumbered(c);
    numbered d; // d.mysn = 7; `
    fNumbered(d);
}

void testNumbered2() {
    numbered a, b = a, c = b;
    fnumbered2(a);
    fnumbered2(b);
    fnumbered2(c);
}

class Employee {
public:
    Employee(): name(), mysn(++sn) {};
    explicit Employee(const string &s): name(s), mysn(++sn) {};
    Employee(Employee &e): name(e.name), mysn(++sn) {};
    Employee operator=(const Employee&);
    
    string getName() { return name; };
    int getId() { return mysn; };
private:
    static int sn;
    int mysn;
    string name;
};

int Employee::sn = 0;

Employee Employee::operator=(const Employee &e) {
    name = e.name;
    return *this;
}

void testEmployee() {
    Employee e1;
    Employee e2("aseven");
    cout << e1.getId() << " " << e1.getName() << endl;
    cout << e2.getId() << " " << e2.getName() << endl;
    Employee e3 = e2;
    cout << e3.getId() << " " << e3.getName() << endl;
    e1 = e2;
    cout << e1.getId() << " " << e1.getName() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    HasPtr hp1("hello world");
//    HasPtr hp2(hp1);
//    HasPtr hp3;
//    hp3 = hp1;
//
//    cout << hp2.get() << endl;
//    cout << hp3.get() << endl;
//    testX();
//    testNumbered1();
//    testNumbered2();
    testEmployee();
    return 0;
}
