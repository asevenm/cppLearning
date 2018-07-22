//
//  main.cpp
//  cppScreen
//
//  Created by 罗林峰 on 2018/7/16.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::cout;

class Screen;
class Window_mgr;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr();
private:
    vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos;
    using content_type = char;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(wd * ht, ' ') {};
    Screen(pos ht, pos wd, content_type str): height(ht), width(wd), contents(wd * ht, str) {};
    char get() const {
        return contents[cursor];
    }
    content_type get(pos, pos) const;
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    };
    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos width = 0, height = 0;
    string contents;
    void do_display(ostream &os) const {
        for (pos i = 0; i != contents.size(); ++i) {
            os << contents[i];
            if ((i + 1) % width == 0 && i + 1 != contents.size())
                os << "\n";
        }
    }
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width; //计算行的位置
    cursor = row + c; //在行内将光标移动到指定列
    return *this;
}

inline Screen::content_type Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

Window_mgr::Window_mgr(): screens{Screen(10, 10)} {};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.width * s.height, ' ');
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    
    //const Screen myScreen2(4, 4);
    //myScreen2.move(3, 0).set('#').display(cout);
    //cout << "\n";
    //myScreen2.display(cout);
    //cout << "\n";
    return 0;
}
