#include <iostream>
#include "BasePlusCommissionEmployee.h"

using namespace std;

// 부모클래스 생성자를 호출해서 초기화
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& Ssn, double rate, double sale, double salary)
:CommissionEmployee(first, last, Ssn, rate, sale) {
	// 추가한 데이터 멤버만 따로 초기화
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary()const {
	return baseSalary;
}

// 재정의
double BasePlusCommissionEmployee::earnings()const {
	// 기본 클래스에서 통째로 호출
	return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print()const {
	// 소속관계 명확히 해야 함. 기본 클래스에서 불러오고 있음을 명시하지 않는다면 여기서 재귀호출로 무한 루프에 빠짐.
	CommissionEmployee::print();

	cout << "base salary: " << getBaseSalary() << endl;
}

// +) 파생 class의 생성자, 소멸자 호출 순서
/*
생성자:	파생 생성자 call -> 기본 생성자 call -> 기본 생성자 execute -> 기본 생성자 return -> 파생 생성자 execute -> 파생 생성자 return
소멸자: 파생 소멸자 call -> 파생 소멸자 execute -> 기본 소멸자 call -> 기본 소멸자 execute -> 기본 소멸자 return -> 파생 소멸자 return
*/