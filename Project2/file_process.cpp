#include<iostream>
#include"streamProcess.h"
#include<fstream>
using namespace std;
vector<string> fileRead1(const string& str) {
	vector<string> vec;
	string temp;
	ifstream in(str);
	if (in) {
		while (getline(in, temp)) {
			vec.push_back(temp);
		}
	}
	else {
		cout << "open file fail" << endl;
	}
	in.close();
	return vec;
}
vector<string> fileRead2(const string& str) {
	vector<string> vec;
	string temp;
	ifstream in(str);
	if (in) {
		while (in>>temp) {
			vec.push_back(temp);
		}
	}
	else {
		cout << "open file fail" << endl;
	}
	in.close();
	return vec;
}