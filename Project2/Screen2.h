#pragma once
#include<vector>
#include<iostream>
class Screen;//1��Screen����������
class window_mgr {
public:

	using screenIndex = std::string::size_type;
	void clear(screenIndex);//2����Ա����������������Screen�ඨ��֮ǰ������˵��Ԫ����֮ǰ��������������
	void add(Screen s);
	void show(screenIndex);
private:
	std::vector<Screen> screens;
};
class Screen {
	friend void window_mgr::clear(screenIndex);//3�������Ա������Ԫ
public:
	typedef std::string::size_type pos;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	Screen() = default; Screen& move(pos h, pos w) {
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
	pos height = 0, width = 0;
	std::string contents;
};

void window_mgr::clear(screenIndex i) {//4�����庯����Screen����֮��
	Screen &s = screens[i];
	s.contents = std::string(s.height*s.width, ' ');
}
void window_mgr::add(Screen s){
	screens.push_back(s);
}
void window_mgr::show(screenIndex i) {
	screens[i].display(cout);
}
