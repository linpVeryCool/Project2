#pragma once
#ifndef XY
#define XY
class Y;
class X {
public:
	Y* y;
	void fun();
};
class Y {
	X x;
};
#endif // !XY


void X::fun() {

}