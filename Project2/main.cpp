#define NDEBUG
#include<string>
#include<vector>
#include"iostream"
#include<cassert>
#include<fstream>
#include <new>
#include <algorithm> 
#include"memory"
#include"MyInclude.h"
#include <typeinfo>  
#include<functional>
#include<map>
using namespace std;
struct LongDouble {
	LongDouble(double d = 0):ld(d) {

	}
	operator double() const {
		cout << "LongDouble->double" << endl;
		return ld;
	}
	LongDouble operator+(const SmallInt& si) {
		cout << "LongDouble+SmallInt" << endl;
		return *this;
	}
private: 
	long double ld;
};
LongDouble operator+(LongDouble& ld, double d) {
	cout << "LongDouble+double" << endl;
	return d;
}
void calc(int i);
void calc(LongDouble ld);
int main()
{

	system("pause");
}
void calc(int i) {
	cout << "double->int" << endl;
}
void calc(LongDouble ld) {
	cout << "LongDouble->int" << endl;
}


