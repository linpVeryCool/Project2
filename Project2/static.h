#pragma once
#include<vector>
using std::vector;
class Example {
private:
	Example() {}
public:
	
	static double rate;
	static constexpr int vecSize = 20;//�������ʽ
	static vector<double> vec;
	static Example exe;//��̬��Ա�ǲ���ȫ����
	double arr[vecSize];
	void showExe(double d=rate) {
		cout << d << endl;
	}
	
};
constexpr int Example::vecSize;
double Example::rate = 6.5;//����
vector<double> Example::vec(10);
Example Example::exe;
