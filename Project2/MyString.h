#pragma once
#include<memory>
#include<iostream>
class String {
private:
	char* elements = 0;
	char* first_free = 0;
	char* cap = 0;
	static std::allocator<char> alloc;
	void free();
	void alloc_n(const char *,const char*);
public:
	String() {}
	String(const char*);
	String(const String&);
	String(String&&);
	String& operator=(const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	~String();
	void display();
	char* begin() const ;
	char* end() const ;
};

std::allocator<char> String::alloc;
String::String(String &&s):elements(s.elements),first_free(s.first_free),cap(s.cap){
	s.elements = s.first_free = s.cap = 0;
	std::cout << "ÒÆ¶¯"<<std::endl;
}
void String::free() {
	for (size_t i = 0; i < first_free - elements; i++)
		alloc.destroy(elements + i);
	alloc.deallocate(elements, cap - elements);
}
void String::alloc_n(const char *b, const char *e) {
	auto d = alloc.allocate(e - b);
	for (size_t i = 0; i < e - b; i++)
		alloc.construct(d + i, *(b + i));
	elements = d;
	first_free = cap = d + (e - b);
}
char* String::begin() const{
	return elements;
}
char* String::end() const {
	return first_free;
}
String::String(const char* p) {
	char *e = const_cast<char*>(p);
	char* b = e;
	while (*e != '\0') {
		e++;
	}
	alloc_n(b, e);
}
String::~String() {
	free();
}
void String::display() {
	for (auto p = elements; p != first_free; p++)
		std::cout << *p;
	std::cout << std:: endl;
}
String::String(const String& s) {
	alloc_n(s.begin(), s.end());
	std::cout << "¿½±´" << std::endl;
}
String& String::operator=(const String& s) {
	free();
	alloc_n(s.begin(), s.end());
	std::cout << "¿½±´=" << std::endl;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const String& s) {
	for (auto ele = s.elements; ele != s.first_free; ele++) {
		os << *ele;
	}
	return os;
}