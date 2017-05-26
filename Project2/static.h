#pragma once
#include<vector>
using std::vector;
class Example {
private:
	Example() {}
public:
	
	static double rate;
	static constexpr int vecSize = 20;//常量表达式
	static vector<double> vec;
	static Example exe;//静态成员是不完全类型
	double arr[vecSize];
	void showExe(double d=rate) {
		cout << d << endl;
	}
	
};
constexpr int Example::vecSize;
double Example::rate = 6.5;//定义
vector<double> Example::vec(10);
Example Example::exe;
