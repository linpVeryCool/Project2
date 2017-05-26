#pragma once
#include<string>
#include<stdio.h>
#include<iostream>
#include<strstream>
using namespace std;
#ifndef Errcode
#define Errcode
class ErrCode {
public:
	ErrCode() {
		err_msg = 0;
	}
	ErrCode(int i) {
		this->err_msg = i;
	}
	string msg() const{
		string s;
		strstream ss;
		
		ss << err_msg;
		ss >> s;
		return s;
	}
private:
	int err_msg = 0;
};
#endif // Errcode
