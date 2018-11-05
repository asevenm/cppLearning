//
//  main.cpp
//  Chapter13.2
//
//  Created by 罗林峰 on 11/5/18.
//  Copyright © 2018 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) { };
    HasPtr(HasPtr &hp): ps(new string(*hp.ps)), i(hp.i) { };
    HasPtr& operator=(const HasPtr &hp);
    ~HasPtr() { delete ps; };
    
    const string &get() const { return *ps; };
    void set(const string &s) { *ps = s; };
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &hp) {
    auto newps = new string(*hp.ps);
    delete ps;
    ps = newps;
    i = hp.i;
    return *this;
}

class HasPtr2 {
public:
    HasPtr2(const string &s = string()):
        ps(new string(s)), i(0), use(new size_t(1)) { };
    HasPtr2(const HasPtr2 &hp):
        ps(hp.ps), i(hp.i), use(hp.use) { ++*use; };
    HasPtr2& operator=(const HasPtr2&);
    ~HasPtr2();
    
    const string &get() const { return *ps; };
    void set(const string &s) { *ps = s; };
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr2& HasPtr2::operator=(const HasPtr2 &hp) {
    ++*hp.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = hp.ps;
    i = hp.i;
    use = hp.use;
    return *this;
}

HasPtr2::~HasPtr2() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

class TreeNode {
public:
    TreeNode(): value(), count(0), left(nullptr), right(nullptr) { };
    TreeNode(const string &s, int i = 0):
        value(s), count(i), left(nullptr), right(nullptr) {};
    TreeNode(const TreeNode &rn);
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &tn):
    value(tn.value), count(tn.count), left(nullptr), right(nullptr) {
        if (tn.left)
            left = new TreeNode(*tn.left);
        if (tn.right)
            right = new TreeNode(*tn.right);
}

TreeNode& TreeNode::operator=(const TreeNode &tn) {
    value = tn.value;
    count = tn.count;
    
    TreeNode *temp = nullptr;
    if (tn.left)
        temp = new TreeNode(*tn.left);
    delete left;
    left = temp;
    
    temp = nullptr;
    if (tn.right)
        temp = new TreeNode(*tn.right);
    delete right;
    right = temp;
    
    return *this;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

class BinStrTree {
public:
    BinStrTree(const TreeNode &tr = TreeNode()):
        root(new TreeNode(tr)), use(new size_t(1)) {};
    BinStrTree(const BinStrTree&);
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree();
    
private:
    TreeNode *root;
    size_t *use;
};

BinStrTree::BinStrTree(const BinStrTree &bst):
    root(bst.root), use(bst.use) {
        ++*use;
}

BinStrTree& BinStrTree::operator=(const BinStrTree &bst) {
    ++*bst.use;
    if (--*use == 0) {
        delete root;
        delete use;
    }
    root = bst.root;
    use = bst.use;
    return *this;
}

BinStrTree::~BinStrTree() {
    if (--*use == 0) {
        delete root;
        delete use;
    }
}

class BinStrTreeValueLike {
public:
    BinStrTreeValueLike(const TreeNode &tr = TreeNode()): root(new TreeNode(tr)) { };
    BinStrTreeValueLike(const BinStrTreeValueLike &bstvl):
        root(new TreeNode(*bstvl.root)) { };
    BinStrTreeValueLike& operator=(const BinStrTreeValueLike&);
    ~BinStrTreeValueLike() { delete root; } ;
    
private:
    TreeNode *root;
};

BinStrTreeValueLike& BinStrTreeValueLike::operator=(const BinStrTreeValueLike &bstvl) {
    auto temp = new TreeNode(*bstvl.root);
    delete root;
    root = temp;
    return *this;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    HasPtr2 hp1;
    HasPtr2 hp2("aseven");
    HasPtr2 hp3 = hp2;
    
    hp1.set("hello");
    
    cout << hp1.get() << endl;
    cout << hp2.get() << endl;
    cout << hp3.get() << endl;
    
    hp1 = hp2;
    cout << hp1.get() << endl;
    return 0;
}
