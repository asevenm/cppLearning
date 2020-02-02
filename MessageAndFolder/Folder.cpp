//
//  Folder.cpp
//  MessageAndFolder
//
//  Created by 罗林峰 on 11/6/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include "Folder.hpp"

Folder::Folder(const Folder &f): msgs(f.msgs) {
    for (const auto &m: f.msgs)
        m->folders.insert(this);
}

Folder& Folder::operator=(const Folder &f) {
    for(const auto &m: f.msgs)
        m->folders.erase(this);
    msgs = f.msgs;
    for(const auto &m: f.msgs)
        m->folders.insert(this);
    return *this;
}

Folder::~Folder() {
    for(const auto &m: msgs)
        m->folders.erase(this);
}

void Folder::remove(Message &m) {
    remMsg(&m);
    m.folders.insert(this);
}

void Folder::save(Message &m) {
    addMsg(&m);
    m.folders.erase(this);
}

void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

void Folder::remMsg(Message *m) {
    msgs.erase(m);
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    for(const auto &m: lhs.msgs)
        m->folders.erase(&lhs);
    for(const auto &m: rhs.msgs)
        m->folders.erase(&rhs);
    swap(lhs.msgs, rhs.msgs);
    for(const auto &m: rhs.msgs)
        m->folders.insert(&rhs);
    for(const auto &m: lhs.msgs)
        m->folders.insert(&lhs);
}

void Folder::print() {
    std::cout << "Folder <" << this << "> contains " << msgs.size()
    << " messages:\n";
    for (const auto &mp : msgs)
        std::cout << "\t<" << mp << ">:<" << mp->contents << ">\n";
}
