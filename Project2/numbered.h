#pragma once
#include<vector>
#include<iostream>
#include<list>
#ifndef NUMBERED
#define NUMBERED
class numbered {
private:
	int number;
	static std::list<int> numbers;
public:
	double value;
	numbered():value(10) {
		int i = 0;
		bool isinclude = false;
		while (true) {
			for (int v : numbers) {
				if (v == i) {
					isinclude = true;
					break;
				}					
			}
			if (isinclude == false) {
				numbers.push_back(i);
				number = i;
				break;			
			}
			i++;
			isinclude = false;
		}
	}
	numbered(const numbered&);
	static void display_numbers();
	numbered &operator=(const numbered& n);
	~numbered() {
		numbers.remove(number);
	}

};
std::list<int> numbered::numbers;
void numbered::display_numbers() {
	std::cout << "numbers:" << endl;
	for (int v : numbers) {
		std::cout << v << std::endl;
	}
}
numbered::numbered(const numbered& n):numbered() {
	this->value = n.value;
}
numbered& numbered::operator=(const numbered& n) {//初始化时已经编号了，因此号码不需要什么改变
	this->value = n.value;
	return *this;
}
#endif