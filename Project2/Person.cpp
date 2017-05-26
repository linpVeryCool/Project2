#include "Person.h"
std::istream &read(std::istream& is, Person &p) {
	
	is >> p.setName() >> p.setAddress();
	return is;
}
std::ostream &print(std::ostream& os, const Person& p) {
	os << p.getName() << ' ' << p.getAddress();
	return os;
}