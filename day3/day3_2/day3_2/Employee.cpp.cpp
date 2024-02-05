#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Date.h"
#include "Employee.h"

using namespace std;

Employee::Employee(const char* const first, const char* const last, const Date& dateofB, const Date& dateofH)
	: birthDate(dateofB), hireDate(dateofH) {
	int length = strlen(first);
	length = (length < 10 ? length : 9);
	strncpy(firstName, first, length);
	firstName[length] = '\0';
	length = strlen(last);
	length = (length < 10 ? length : 9);
	strncpy(lastName, last, length);
	lastName[length] = '\0';

	cout << "Employee constructor: " << firstName << "  " << lastName << endl;
}

void Employee::print()const {
	cout << lastName << ", " << firstName << "  Hired: ";
	hireDate.print();
	cout << "  Birthday: ";
	birthDate.print();
	cout << endl;
}

Employee::~Employee() {
	cout << "Employee destructor: " << lastName << ", " << firstName << endl;
}