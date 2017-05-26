#pragma once
#include<new>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<iostream>
class StrVec {
public:
	static std::allocator<std::string> alloc;
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec& s);
	StrVec(std::initializer_list<std::string> lst);
	StrVec(StrVec &&s) noexcept;
	StrVec& operator=(const StrVec& s);
	StrVec& operator=(StrVec&& s) noexcept;
	StrVec& operator=(std::initializer_list<std::string> il);
	std::string& operator[](std::size_t);
	const std::string& operator[](std::size_t) const;
	~StrVec();
	void push_back(const std::string& s);
	void push_back(std::string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:

	std::string *elements = 0;
	std::string *first_free = 0;
	std::string *cap = 0;
	void free();
	void reallocate();
	void chk_n_alloc();
	//∑÷≈‰ø’º‰≤¢øΩ±¥
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string* b, const std::string* e);
};
