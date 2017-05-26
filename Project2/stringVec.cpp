#include "stringVec.h"

std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(const StrVec& s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	elements = data.first;
	cap = data.second;
	first_free = data.second;
	std::cout << "拷贝" << std::endl;
}
StrVec::StrVec(std::initializer_list<std::string> lst) {
	auto pa = alloc_n_copy(lst.begin(), lst.end());
	elements = pa.first;
	cap = pa.second;
	first_free = pa.second;
}
StrVec& StrVec::operator=(const StrVec& s) {//要防止自己拷贝自己
	auto p = alloc_n_copy(s.begin(), s.end());//这里s是常量，只能调用常量函数
	free();
	elements = p.first;
	cap = p.second;
	first_free = p.second;
	std::cout << "拷贝" << std::endl;
	return *this;
}
void StrVec::push_back(const std::string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	//auto dest = newdata;
	//auto elem = elements;
	/*for (size_t i = 0; i < size(); i++)
	alloc.construct(dest++, std::move(*elem++));*/
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);
	free();
	elements = newdata;
	first_free = last;
	cap = elements + newcapacity;
}
void StrVec::chk_n_alloc() {
	if (size() == capacity())
		reallocate();
}
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
	std::string* data = alloc.allocate(e - b);//分配空间
	std::uninitialized_copy(b, e, data);
	return { data,data + (e - b) };//uninitialized_copy返回构造最后一个元素的后一个位置
}


StrVec::StrVec(StrVec &&s) noexcept
	:elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.cap = s.first_free = 0;
	std::cout << "移动" << std::endl;
}
StrVec& StrVec::operator=(StrVec&& s) noexcept {
	if (this != &s) {
		free();
		elements = s.elements;
		cap = s.elements;
		first_free = s.first_free;
		s.elements = s.cap = s.first_free = nullptr;
	}
	std::cout << "移动" << std::endl;
	return *this;
}
StrVec::~StrVec() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
void StrVec::push_back(std::string&& s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));//这里虽然s是右值引用，但是s是变量是左值，所以需要使用move函数,右值引用调用移动构造函数的机会只有一次
	std::cout << "移动" << std::endl;
}
StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
std::string& StrVec::operator[](std::size_t t) {
	return elements[t];
}
const std::string& StrVec::operator[](std::size_t t) const{
	return elements[t];
}