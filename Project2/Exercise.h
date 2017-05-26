#pragma once
#include<string>
using std::string;
typedef string Type;
//Type initVal();
class Exercise {
public :
	Exercise():val(20),con(rval), rval(val) {}
	typedef double Type;
	Type setVal(Type);

	Type val;
	Type& rval ;
	const int con ;
};
Exercise::Type Exercise::setVal(Type parm) {
	val = parm;
	return val;
}