#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
void fileToString(string file) {
	ifstream fin(file);
	if (!fin)
		return;
	string line;
	ostringstream ostr;
	while (getline(fin, line)) {
		ostr << line << " ";
	}
	istringstream istr(ostr.str());
	istr.str("dfdf");
	string temp;
	while (istr >> temp)
		cout << temp << endl;
	fin.close();
}