#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee {	// ���� ��ü
public:
	// Data class�� ����� ���� ���ϰ� ����Ͽ��� ���ߵǱ� ������ �������� & ���
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
