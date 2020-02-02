//
//  Message.hpp
//  MessageAndFolder
//
//  Created by 罗林峰 on 11/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>
#include <set>
#include <string>
#include <memory>
#include "Folder.hpp"

using namespace std;

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const string &s = ""): contents(s) { };
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    
    void save(Folder&);
    void remove(Folder&);
    
    void print();
    
private:
    string contents;
    set<Folder*> folders;
    void add_to_folder(const Message&);
    void remove_from_folder();
    void addFdr(Folder*);
    void remFdr(Folder*);
};

#endif /* Message_hpp */
