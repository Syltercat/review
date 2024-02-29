#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee {	// 복합 객체
public:
	// Data class로 저장된 것이 생일과 고용일에도 들어가야되기 때문에 참조형인 & 사용
	Employee(const char* const, const char* const, const Date&, const Date&);
	void print()const;
	~Employee();

private:
	char firstName[10];
	char lastName[10];

	const Date birthDate;
	const Date hireDate;
};
#endif // !EMPLOYEE_H
