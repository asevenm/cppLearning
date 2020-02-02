//
//  Folder.hpp
//  MessageAndFolder
//
//  Created by 罗林峰 on 11/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#ifndef Folder_hpp
#define Folder_hpp

#include <stdio.h>
#include <iostream>
#include <set>
#include "Message.hpp"

using namespace std;

class Message;

class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    
    void remove(Message&);
    void save(Message&);
    
    void print();
private:
    set<Message*> msgs;
    
    void addMsg(Message*);
    void remMsg(Message*);
};

#endif /* Folder_hpp */
