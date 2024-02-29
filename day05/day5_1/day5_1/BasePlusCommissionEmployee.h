#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h"
#include <string>

using namespace std;

// 아래와 같은 형식으로 상속
class BasePlusCommissionEmployee:public CommissionEmployee {

// 추가하고 싶거나 재정의하고 싶은 멤버 함수와 데이터 멤버를 작성
public:
	// 생성자, 소멸자의 경우 상속되지 않으니 주의
	BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
	void setBaseSalary(double);
	double getBaseSalary()const;
	
	// 재정의
	double earnings()const;
	void print()const;
private:
	double baseSalary;
};
#endif // !BASEPLUS_H
