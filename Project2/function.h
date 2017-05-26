#pragma once
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "ErrCode.h"
typedef int arrt[10];
using namespace std;
void Exchange(int*, int*);
void Exchange(int &r1, int &r2);
bool isContainCapital(const string &r);
void ToLower(string &s);
void aprint(const int *beg, const int *end);
void ExchangeP(int **p1, int **p2);
void error_msg(initializer_list<string> lst);
void foo(int i, ...);
string &manip();
string *man_ip();
int &get(int *arry, int index);
void outputVector(vector<int> vec);
int factorial(int val);
arrt* func1(int v);
int(*func2(int v))[10];
extern int Array[10];
decltype(&Array) func5(int v);