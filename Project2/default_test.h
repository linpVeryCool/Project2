#pragma once
#include<iostream>
using namespace std;
class defaultTest {
public:
	defaultTest() = default;
	defaultTest(const defaultTest&) = default;
	defaultTest& operator=(const defaultTest&) = default;
	~defaultTest() = delete;
};