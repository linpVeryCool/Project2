#include<iostream>
#include<string>
#ifndef SALES_DATA
#define SALES_DATA
class Sales_data {
public:
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p) { }
//	Sales_data() = default;
	explicit Sales_data(const std::string &s = "") : Sales_data(s, 0, 0) {}//ʹ����Ĭ��ʵ�Σ�Ҳ�ṩĬ�ϵĹ��캯��
	explicit Sales_data(std::istream &is):Sales_data() {
		std::cout << "input Sales data:" << std::endl;
		read(is, *this);
	} //������istream��Sales_data����ʽת����������ʹ����ʽת��


	std::string  isbn() const;
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::ostream &operator<<(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::istream &operator>>(std::istream&, Sales_data&);
	Sales_data &operator=(const Sales_data&);
	Sales_data &operator=(const std::string&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	explicit operator std::string() const {
		return bookNo;
	}
	explicit operator double() const {
		return revenue;
	}
	explicit operator bool() const {
		return bookNo == "";
	}
private:
	double avg_prive() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
#endif

