#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<memory>
#ifndef STRBLOB
#define STRBLOB
//ʹ��Ĭ�ϰ汾�Ŀ�����ֵ������
class strBlobptr;
class ConstStrBlobPtr;
class StrBlob {
public:
	friend class strBlobPtr;
	friend class ConstStrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list <std::string> il);
	size_type size() { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { 
		data->push_back(t); }
	void push_back(std::string&& s) {
		data->push_back(std::move(s));
	}
	void pop_back();
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
	void showAllData() {
		for (auto s : *data)
			std::cout << s << std::endl;
	}
	strBlobPtr begin();
	strBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;	
};
//ָ��StrBlobԪ�ص�ָ���࣬ʵ���Ͼ���ָ��string�����ָ���ࡣ����ʹ��*���������string����operator->()��������stringָ��
class strBlobPtr {
public:
	strBlobPtr() :curr(0) {}
	strBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz){}
	std::string& deref() const {	
		return (*check(curr, ""))[curr];
	}
	strBlobPtr& incr() {
		auto p = check(curr, "");
		curr++;
		return *this;
	}
	strBlobPtr& operator++() {
		check(curr, "increment past end of strBlobPtr");
		++curr;
		return *this;
	}
	strBlobPtr& operator--() {
		curr--;
		check(curr, "decrement past begin of strBlobPtr");
		return *this;
	}
	strBlobPtr operator++(int) {
		strBlobPtr ret = *this;
		++(*this);
		return ret;
	}
	strBlobPtr operator--(int) {
		strBlobPtr ret = *this;
		--(*this);
		return ret;
	}
	std::string& operator*() const {
		auto p = check(curr, "");
		return (*p)[curr];
	}
	std::string* operator->() const {
		return &this->operator*();
	}
private:
	//���curr�Ƿ񳬹�������Ԫ�ص�����
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& deref() const {

		return (*check(curr, ""))[curr];
	}
	ConstStrBlobPtr& incr() {
		auto p = check(curr, "");
		curr++;
		return *this;
	}
	const std::string& operator*() const {
		auto p = check(curr, "");
		return (*p)[curr];//����
	}
	const std::string* operator->() const {
		return &this->operator*();
	}
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif // !STRBLOB
void memoryProcess();
void dyna_vector();
void shared_ptr_vector();
