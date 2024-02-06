#pragma warning(disable:4996)
#include <iostream>
#include "Employee.h"
using namespace std;

int Employee::count = 0;	// static data member���� �ʱ�ȭ

int Employee::getCount() {
	return count;
}

Employee::Employee(const char* const first, const char* const last) {
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);

	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);

	count++;

	cout << "Employee constructor call: " << firstName << " " << lastName << endl;
}

Employee::~Employee() {
	cout << "Employee destructor call: " << firstName << " " << lastName << endl;

	// ���� �޸� ��ȯ
	delete[] firstName;
	delete[] lastName;

	count--;
}
const char* Employee::getFirstName() const {
	return firstName;
}	

const char* Employee::getLastName() const {
	return lastName;
}	