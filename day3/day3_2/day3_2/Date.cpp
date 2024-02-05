#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y) {
	if (m > 0 && m <= 12)
		month = m;
	else {
		month = 1;
		cout << "invalid month " << m << endl;
	}

	year = y;

	day = checkDay(d);

	cout << "constructor already runs" << endl;
	print();
}

void Date::print() const {
	cout << month << " / " << day << " / " << year << endl;
}

Date::~Date() {
	cout << "destructor for data" << endl;
	print();
}

int Date::checkDay(int d) const{
	static const int daysPerMonth[13] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	if (d > 0 && d <= daysPerMonth[month]) return d;
	if (month == 2 && d == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return d;	// À±³â
	cout << "Invalid day: " << d << endl;
	return 1;
}