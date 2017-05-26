#include"Employee.h"
int Employee::_id = 0;
Employee::Employee():id(_id++) {
	
}
Employee::Employee(const std::string& str): Employee(){
	name = str;
}
Employee::Employee(const Employee& em):name(em.name),id(_id++) {
	
}
Employee& Employee::operator=(const Employee& em) {
	name = em.name;
	return *this;
}