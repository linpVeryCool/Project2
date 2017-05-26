#pragma once
#include<string>
#include<iostream>
#ifndef EMPLOYEE
#define EMPLOYEE
class Employee {
	std::string name;
	int id;
	static int _id;
public:
	Employee();
	Employee(const std::string&);
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	void display() {
		std::cout << id << std::endl;
		std::cout << name << std::endl;
	}
};


#endif