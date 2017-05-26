#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class Example1 {
	static double rate;
	static const int vecSize = 20;
	static std::vector<double> vec1;
};
double Example1::rate = 6.5;
std::vector<double> Example1::vec1;