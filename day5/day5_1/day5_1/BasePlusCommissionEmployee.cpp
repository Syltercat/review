#include <iostream>
#include "BasePlusCommissionEmployee.h"

using namespace std;

// �θ�Ŭ���� �����ڸ� ȣ���ؼ� �ʱ�ȭ
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& Ssn, double rate, double sale, double salary)
:CommissionEmployee(first, last, Ssn, rate, sale) {
	// �߰��� ������ ����� ���� �ʱ�ȭ
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary()const {
	return baseSalary;
}

// ������
double BasePlusCommissionEmployee::earnings()const {
	// �⺻ Ŭ�������� ��°�� ȣ��
	return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print()const {
	// �ҼӰ��� ��Ȯ�� �ؾ� ��. �⺻ Ŭ�������� �ҷ����� ������ ������� �ʴ´ٸ� ���⼭ ���ȣ��� ���� ������ ����.
	CommissionEmployee::print();

	cout << "base salary: " << getBaseSalary() << endl;
}

// +) �Ļ� class�� ������, �Ҹ��� ȣ�� ����
/*
������:	�Ļ� ������ call -> �⺻ ������ call -> �⺻ ������ execute -> �⺻ ������ return -> �Ļ� ������ execute -> �Ļ� ������ return
�Ҹ���: �Ļ� �Ҹ��� call -> �Ļ� �Ҹ��� execute -> �⺻ �Ҹ��� call -> �⺻ �Ҹ��� execute -> �⺻ �Ҹ��� return -> �Ļ� �Ҹ��� return
*/