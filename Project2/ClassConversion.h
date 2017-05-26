#pragma once
#include<iostream>
#include<string>
class SmallInt {
public:
	SmallInt(int i) :val(i) {
		if (i > 255 || i < 0) {
			throw std::out_of_range("bad SmallInt value");
		}
	}
	operator int() const {
		std::cout << "smallInt->int" << endl;
		return val;
	}
	friend std::ostream &operator<<(ostream &os,SmallInt sint) {
		os << sint.val;
		return os;
	}
private:
	int val;
};
std::ostream &operator<<(ostream &os, SmallInt sint);