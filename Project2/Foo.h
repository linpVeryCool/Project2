#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#ifndef FOO
#define FOO
class Foo {
public:
	Foo(const Foo& f) :data(f.data) {}
	Foo(const std::vector<int>& vec) :data(vec) {}
	Foo Sorted() && ;
	Foo Sorted() const &;
	void display() && {
		for (auto i : data) {
			std::cout << i << std::endl;
		}
	}
private:
	std::vector<int> data;
};
//Foo Foo::Sorted() && {
//	std::cout << "&&" << std::endl;
//	std::sort(data.begin(), data.end());
//	return *this;//ÓÒÖµ
//}
//Foo Foo::Sorted() const & {
//	std::cout << "&" << std::endl;
//	//Foo f(*this);
//	//sort(f.data.begin(), f.data.end());
//	return Foo(*this).Sorted();//·µ»ØÓÒÖµ
//
//}
#endif // !

