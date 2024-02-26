#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMin(m);
	setSec(s);
}

// hour, min, sec는 각각의 조건이 있어야 함.
void Time::setHour(int h) {
	if (0 <= h <= 24) {
		hour = h;
	}
	else hour = 0;
}

void Time::setMin(int m) {
	if (0 <= m <= 59) {
		min = m;
	}
	else min = 0;
}

void Time::setSec(int s) {
	if (0 <= s <= 59) {
		sec = s;
	}
	else sec = 0;
}

int Time::getHour() {
	return hour;
}

int Time::getMin() {
	return min;
}

int Time::getSec() {
	return sec;
}

void Time::printUniversal() {
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMin() << ":" << setw(2) << getSec() << endl;
}

void Time::printStandard() {
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << " : " << getMin() << " : " << getSec() << "  " << ((getHour() < 12) ? "Am" : "Pm")<< endl;
}

Time::~Time() {
	cout << "delete class" << endl;
}