#pragma once
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
using namespace std;

class CommissionEmployee {
public:
	CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
	
	void setfirstName(const string&);
	string getfirstName() const;

	void setlastName(const string&);
	string getlastName()const;

	void setSSN(const string&);
	string getSSN()const;

	void setCommissionRate(double); // 위에서는 참조를 통해(passed_by_reference) 인자를 받았지만 여기에서는 값을 받아서 (passed_by_value) const는 필요 없다.
	double getCommissionRate() const;

	void setGrossSale(double);
	double getsaleGrossSale()const;

	double earnings()const;
	void print()const;

private:
	string firstName;
	string lastName;
	string SSN;
	double commissionRate;
	double grossSale;
};

#endif // !COMMISSION_H
