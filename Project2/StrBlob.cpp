#include<iostream>
#include<string>
#include<memory>
#include"StrBlob.h"
using namespace std;
void memoryProcess() {
	//传递的参数必须与string的某个构造函数相匹配
	shared_ptr<string> p = make_shared<string>(10, '0');
	shared_ptr<int> p1 = make_shared<int>();//使用默认值初始化

}
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared <vector<string>>(il)) {}
void StrBlob::pop_back() {
	check(0, "popback a empty StrBlob");
	data->pop_back();
}
std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
const std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}



shared_ptr<vector<string>> strBlobPtr::check(std::size_t i, const std::string& msg) const {
	shared_ptr<std::vector<std::string>> sp = wptr.lock();
	if (!sp)
		throw std::runtime_error(msg);
	if (i >= sp->size())
		throw std::out_of_range(msg);
	return sp;
}
strBlobPtr StrBlob::begin() {
	return strBlobPtr(*this);
}
strBlobPtr StrBlob::end() {
	return strBlobPtr(*this, data->size());
}



vector<int>& read(istream& r, vector<int> &vec);
void print(ostream& os, vector<int> &vec);
void dyna_vector() {
	vector<int> *p = new vector<int>;
	read(cin, *p);
	print(cout, *p);
	delete p;
}
void shared_ptr_vector() {
	shared_ptr<vector<int>> sp = make_shared<vector<int>>();
	read(cin, *sp);
	print(cout, *sp); 
}
vector<int>& read(istream& r, vector<int> &vec) {
	int i = 0;
	while (r >> i) {
		vec.push_back(i);
	}
	return vec;
}
void print(ostream& os, vector<int> &vec) {
	for (auto i : vec) {
		os<< i << endl;
	}
}