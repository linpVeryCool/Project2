#pragma once
#include<string>
#include<iostream>
class HasPtr {
public:
	HasPtr(const std::string& str = std::string()):
		ps(new std::string(str)),i(0){}
	HasPtr(const HasPtr& hp) 
		:ps(new std::string(*hp.ps)), i(hp.i) { 
		std::cout << "拷贝" << std::endl;
	}
	HasPtr(HasPtr&& hp) noexcept
		:ps(hp.ps), i(hp.i) { 
		hp.ps = 0; std::cout << "移动" << std::endl; 
	}
	/*HasPtr& operator=(const HasPtr& hp) {
		auto newp=new std::string(*hp.ps);
		delete ps;
		ps = newp;
		i = hp.i;
		return *this;
	}*/
	//HasPtr& operator=(HasPtr hp) {
	//	swap(*this, hp);
	//	return *this;
	//}
	HasPtr& operator=(HasPtr&& hp) {
		   ps=hp.ps; i=hp.i;
			hp.ps = 0; 
			std::cout << "移动" << std::endl;
			return *this;
	}
	bool operator<(const HasPtr& hp) {
		return *ps < *hp.ps;
	}
	friend void swap(HasPtr &lhs, HasPtr &rhs);
	~HasPtr() {
		delete ps;
	}
	void display() {
		cout << *ps << endl;
	}
private:
	std::string *ps;
	int i;
	
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {//特定版本的swap函数
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "HasPtr::swap" << std::endl;
}
class HasPtr2 {
public:
	HasPtr2(const std::string& str = std::string()) :
		ps(new std::string(str)), i(0) ,use(new int(1)){}
	HasPtr2(const HasPtr2& hp) :ps(hp.ps), i(hp.i),use(hp.use) {
		++*use;
	}
	HasPtr2& operator=(const HasPtr2& hp) {
		++*hp.use;
		if (--*use == 0) {
			delete use;
			delete ps;
		}
		use = hp.use;
		ps = hp.ps;
		i = hp.i;
		return *this;
	}
	~HasPtr2() {
		--*use;
		if (*use == 0) {
			delete use;
			delete ps;
		}

	}
private:
	std::string *ps;
	int i;
	int *use;
	
};
