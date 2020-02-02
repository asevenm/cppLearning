//
//  Message.cpp
//  MessageAndFolder
//
//  Created by 罗林峰 on 11/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include "Message.hpp"

Message::Message(const Message &m)
 : contents(m.contents), folders(m.folders) {
     add_to_folder(m);
}

Message& Message::operator=(const Message &m) {
    remove_from_folder();
    folders = m.folders;
    contents = m.contents;
    add_to_folder(m);
    return *this;
}

Message::~Message() {
    remove_from_folder();
}


void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folder(const Message &m) {
    for(const auto &f: m.folders)
        f->addMsg(this);
}

void Message::remove_from_folder() {
    for(const auto &f: folders)
        f->remMsg(this);
}

void swap(Message &lhs,  Message &rhs) {
    using std::swap;
    for(const auto &f: lhs.folders)
        f->remMsg(&lhs);
    for(const auto &f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for(const auto &f: lhs.folders)
        f->addMsg(&lhs);
    for(const auto &f: rhs.folders)
        f->addMsg(&rhs);
}

void Message::addFdr(Folder *f) {
    folders.insert(f);
}

void Message::remFdr(Folder *f) {
    folders.erase(f);
}

void Message::print() {
    std::cout << "Message <" << this << ">:<" << contents << "> in "
    << folders.size() << " folders:\n";
    for (const auto &fp : folders)
        std::cout << "\t<" << fp << ">\n";
}
