//
//  main.cpp
//  dynamicalMemory
//
//  Created by 罗林峰 on 2018/9/20.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string& front();
    string& front() const;
    string& back();
    string& back() const;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on epty StrBlob");
    data->pop_back();
}

string& StrBlob::front() const {
    check(0, "front on empty StrBlob: const ");
    return data->front();
}

string& StrBlob::back() const {
    check(0, "back on empty StrBlob: const");
    return data->back();
}

void testStrBlob(StrBlob &sb) {
    try {
        sb.push_back("abc");
        sb.push_back("edf");
        cout << sb.front() << " " << sb.back() << endl;
        sb.pop_back();
        cout << sb.front() << " " << sb.back() << endl;
        sb.pop_back();
        cout << sb.front() << " " << sb.back() << endl;
    } catch(out_of_range err) {
        cerr << err.what() << " out of rang" << endl;
    } catch(exception err) {
        cerr << err.what() << endl;
    }
}

void testStrBlob(const StrBlob &sb) {
    try {
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    } catch (std::out_of_range err) {
        std::cerr << err.what() << " out of range" << std::endl;
    } catch (std::exception err) {
        std::cerr << err.what() << std::endl;
    }
}

void runStrBlob() {
    StrBlob sb1;
    StrBlob sb2{"hello", "world"};
    StrBlob sb3{"bye", "world"};
    testStrBlob(sb1);
    testStrBlob(sb2);
    testStrBlob(sb3);
    cout << endl;
    const StrBlob csb1;
    const StrBlob csb2{"this", "blob"};
    testStrBlob(csb1);
    testStrBlob(csb2);
}

/********************************************************************/

typedef shared_ptr<vector<int>> share_vi_ptr;

vector<int>* factory_vi() {
    return new vector<int>();
}

share_vi_ptr factory_vi_2() {
    return make_shared<vector<int>>();
}

void set_vi(vector<int>* vi) {
    for(int i; cin >> i; vi->push_back(i)) {}
}

void set_vi(share_vi_ptr vi) {
    for(int i; cin >> i; vi->push_back(i)) { }
}

void print_vi(vector<int>* vi) {
    for(const auto &i: *vi) {
        cout << i << " ";
    }
    cout << endl;
}

void print_vi(share_vi_ptr vi) {
    for(const auto &i: *vi) {
        cout << i << " ";
    }
    cout << endl;
}

void viProgram() {
    // auto *vi = factory_vi();
    auto vi = factory_vi_2();
    set_vi(vi);
    print_vi(vi);
    // delete vi;
}

/***********************************************************************/

struct destination {
    unsigned id;
    explicit destination(unsigned des_id) : id(des_id) {}
};
struct connection {
    destination *dest;
};

connection connect(destination* dest) {
    connection new_connect;
    new_connect.dest = dest;
    cout << "setup connection to " << new_connect.dest->id << endl;
    return new_connect;
};

void disconnect(connection conn) {
    cout << "Stop connection to " << conn.dest->id << endl;
};

void end_connection(connection *p) {
    disconnect(*p);
}

void f(destination &d) {
    connection c = connect(&d);
    // shared_ptr<connection> p(&c, end_connection);
    shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
    cout << "Using connection " << c.dest->id << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // runStrBlob();
    //viProgram();
    
    destination d(5);
    f(d);
    return 0;
}
