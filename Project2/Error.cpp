#include<string>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int ThrowError() {
	int i = 10;
	int j = 9;
	if (i != j) {
		throw runtime_error("Data Error");
	}
	return 0;
}
void funcError() {
	try {
		int i = 0, j = 0;

		if (j == 0)
			throw runtime_error("divide 0");
		cout << i / j << endl;
	}
	catch (range_error e) {
		cout << e.what() << endl;
	}
	catch (overflow_error) {
		cout << "overflow_error" << endl;
	}
	catch (out_of_range) {
		cout << "out_of_range" << endl;
	}
	catch (exception) {
		cout << "exception" << endl;
	}
	catch (bad_cast) {
		cout << "bad_cast" << endl;

	}
}