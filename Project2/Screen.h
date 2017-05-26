#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
typedef double pos;
class Screen {
	friend class window_mgr;
public:
	typedef std::string::size_type pos;
	Screen(pos ht,pos wd):width(wd),height(ht),contents(ht*wd,' '){}
	Screen(pos ht,pos wd,char c):width(wd),height(ht),contents(ht*wd,c){}
	Screen() = default;
	Screen& move(pos h, pos w) {
		cursor = h*w;
		return *this;
	}
	Screen& set(char ch) {
		contents[cursor] = ch;
		return *this;
	}
	Screen& display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
private:
	void do_display(std::ostream &os) const {
		os << contents;
	}
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
};
class window_mgr {
public:

	using screenIndex = std::string::size_type;
	void clear(screenIndex);
	/*void add(Screen s) {
	screens.push_back(s);
	}*/
private:
	std::vector<Screen> screens{ Screen(12,12,' ') };
};
void window_mgr::clear(screenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height*s.width, ' ');
}
class Link_screen {
	Screen window;
	Link_screen* next;
	Link_screen* prev;
};