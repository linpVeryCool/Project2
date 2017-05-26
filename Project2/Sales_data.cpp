#include "Sales_data.h"
using namespace std;
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}
 istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;

}
 Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
	 units_sold += rhs.units_sold;
	 revenue += rhs.revenue;
	 return *this;
 }
 Sales_data operator+(const Sales_data& s1, const Sales_data& s2) {
	 Sales_data sd = s1;
	 sd += s2;
	 return sd;
 }

std::istream &operator>>(std::istream& is, Sales_data& item){
    double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price*item.units_sold;
	else {
		item = Sales_data();
	}
	return is;
}
 ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_prive();
	return os;
}
std::ostream &operator<<(std::ostream& os, const Sales_data& item){
	os << item.isbn() << " " << item.units_sold << " " 
		<< item.revenue << " " << item.avg_prive();
	return os;
}
 Sales_data add(const Sales_data& s1, const Sales_data& s2) {
	Sales_data sd=s1;
	sd = sd.combine(s2);
	return sd;
}
 string Sales_data::isbn() const {
	  return bookNo; 
 }
 double Sales_data::avg_prive() const {
	 return units_sold ? revenue / units_sold : 0;
 }
 Sales_data &Sales_data::operator=(const Sales_data& sd) {
	 this->bookNo = sd.bookNo;
	 units_sold = sd.units_sold;
	 revenue = sd.revenue;
	 return *this;
 }
 bool operator==(const Sales_data& s1, const Sales_data& s2) {
	 return s1.bookNo == s2.bookNo&&
		 s1.revenue == s2.revenue&&
		 s1.units_sold == s2.units_sold;
 }
 Sales_data & Sales_data::operator=(const std::string& s) {
	 bookNo = s;
	 return *this;
 }
