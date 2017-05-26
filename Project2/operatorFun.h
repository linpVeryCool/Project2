#pragma once
#include <iostream>
struct absInt {
	int operator()(int i) {
		return i > 0 ? i : -i;
	}
};
class PrintString {
public:
	PrintString(std::ostream& o = std::cout, char c = ' ') :
		os(o),ch(c){}
	void operator()(const std::string& s) const{
		os << s << ch;
	}
private:
	std::ostream& os;
	char ch;
};
class if_then_else {
	int operator()(int i1, int i2, int i3) {
		if (i1)
			return i1;
		else if (i2)
			return i2;
		else
			return i3;
	}
};
class inputString {
public:
	inputString(std::istream& i) :
		is(i) {}
	string operator()() {
		std::string str;
		if (getline(is, str))
			Vstr.push_back(str);		
		return str;			 
	}
private:
	std::istream& is;
	std::vector<std::string> Vstr;
};
class shorterString {
public:
	shorterString(int i) :v(i) {}
	bool operator()(const string &s1, const string& s2) {
		return s1.size() < s2.size();
	}
private:
	int v;
};
class StringLen {
private:
	std::string::size_type sizet;
public:
	StringLen(std::string::size_type t) :sizet(t) {}
	bool operator()(const std::string& s) {
		return s.size() == sizet;
	}
};