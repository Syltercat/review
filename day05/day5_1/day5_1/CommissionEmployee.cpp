#include <iostream>
#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& Ssn, double rate, double sale) {
	setfirstName(first);
	setlastName(last);
	setSSN(Ssn);
	setGrossSale(sale);
	setCommissionRate(rate);
}

void CommissionEmployee::setfirstName(const string& first) {
	firstName = first;
}

string CommissionEmployee::getfirstName()const {
	return firstName;

}

void CommissionEmployee::setlastName(const string& last) {
	lastName = last;
}

string CommissionEmployee::getlastName()const {
	return lastName;
}

void CommissionEmployee::setSSN(const string& Ssn) {
	SSN = Ssn;
}

string CommissionEmployee::getSSN()const {
	return SSN;
}

void CommissionEmployee::setCommissionRate(double rate) {
	commissionRate = rate;
}

double CommissionEmployee::getCommissionRate()const {
	return commissionRate;
}

void CommissionEmployee::setGrossSale(double sale) {
	grossSale = sale;
}

double CommissionEmployee::getsaleGrossSale()const {
	return grossSale;
}

double CommissionEmployee::earnings()const {
	return commissionRate * grossSale;
}

void CommissionEmployee::print()const {
	cout << "commission employee: " << getfirstName() << ' ' << getlastName()
		<< "\nSSN: " << getSSN() << "\ncommission rate: " << getCommissionRate()
		<< "\ngross sale: " << getsaleGrossSale() << endl;
}