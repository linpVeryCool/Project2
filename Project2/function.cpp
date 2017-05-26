#include"function.h";
void Exchange(int *p1, int *p2) {

	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void ExchangeP(int **p1, int **p2) {
	int *t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void Exchange(int &r1, int &r2) {
	int t = r1;
	r1 = r2;
	r2 = t;
}
bool isContainCapital(const string &r) {
	for (char c : r) {
		if (isupper(c))
			return true;
	}
	return false;
}
void ToLower(string &s) {
	for (char &c : s) {
		c = tolower(c);
	}
}
void aprint(const int *beg, const int *end) {
	while (beg != end) {
		cout << *beg++ << endl;
	}
}
void print(int(&arr)[10]) {

}
void print(int matrix[2][10], int rowSize) {/*….*/ }
void error_msg(initializer_list<string> lst) {
	for (auto beg = lst.begin(); beg != lst.end(); beg++) {
		cout << *beg << " ";
	}
	cout << endl;
}
void error_msg(ErrCode e, initializer_list<string> lst) {
	cout << e.msg() << endl;
	for (auto beg = lst.begin(); beg != lst.end(); beg++) {
		cout << *beg << " ";
	}
	cout << endl;
}
void foo(int i, ...) {
	cout << i << endl;
}
string &manip() {
	string ret = "ss";
	return ret;
}
string *man_ip() {
	string ret = "ss";
	return &ret;
}
int test(bool bo) {
	if (bo)
		return 0;
}
int &get(int *arry, int index) { return arry[index]; }
void outputVector(vector<int> vec) {
	if (vec.begin() == vec.end()) {
		return;
	}
	cout << *(vec.end()-1)<< endl;
	vec.pop_back();
	outputVector(vec);
}
int factorial(int val) {
	if (val != 0)
		return factorial(val - 1)*val;
	return 1;
}

int Array[10] = { 10,23,4,45,6,7,8 };
arrt* func1(int v) {
	return &Array;
}
int(*func2(int v))[10]
{
	return &Array;
}
auto func3(int v)->int(*)[10]{//使用尾置返回类型
	return &Array;
}
decltype(Array) *func4(int v) {
	return &Array;
}
decltype(&Array) func5(int v) {
	return &Array;
}
using strs10 = string[10];
string strs[10] = { "hello","world" };
string(&func_string())[10]
{
	return strs;
}
strs10 &func_string1() {
	return strs;
}
decltype(strs) &func_string2() {
	return strs;
}
auto func_string3()->string(&)[10]{
	return strs;
}
constexpr size_t scale(size_t cnt) {
	return cnt;
}
void f(int&, int&) {
	cout << "f(int&, int&)" << endl;
}
void f(double, double) {
	cout << " f(double, double)" << endl;
}
void f(const int&, const int &) {
	cout << "f(const int&, const int &) " << endl;
}
void f(char*) {
	cout << "f(char*)" << endl;
}
int add(int i, int j) {
	return i + j;
}
bool(*fun(int i))(const string&, const string &) {
	return [](const string&, const string &) {
		cout << "hello" << endl;
		return true;
	};
}
//int string_len_equal(vector<string>::iterator b, vector<string>::iterator e, StringLen SL) {
//	int sum = 0;
//	for (int i = 0; i != e - b; i++) {
//		sum += (int)SL(*(b + i));
//	}
//	return sum;
//}