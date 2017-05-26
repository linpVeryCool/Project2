#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>


struct Person {
private:
	std::string name;
	std::string address;
	mutable int age;
//	static int num;
public:
	Person(const Person &p){}
	Person() = default;
	Person(const std::string &s1,const std::string &s2):name(s1),address(s2){}
	Person(std::istream& is) {
		std::istream &read(std::istream&, Person &);
		read(is, *this);
	}
	const std::string& getName() const {
		return name;
	}
	const std::string& getAddress() const {
		return address;
	}
	std::string& setName() {
		return name;
	}
	std::string& setAddress()  {
		return address;
	}
	void fun() const {
		age++;
	}

};
std::istream &read(std::istream&, Person &);
std::ostream &print(std::ostream&, const Person&);

