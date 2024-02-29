#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h"
#include <string>

using namespace std;

// �Ʒ��� ���� �������� ���
class BasePlusCommissionEmployee:public CommissionEmployee {

// �߰��ϰ� �Ͱų� �������ϰ� ���� ��� �Լ��� ������ ����� �ۼ�
public:
	// ������, �Ҹ����� ��� ��ӵ��� ������ ����
	BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
	void setBaseSalary(double);
	double getBaseSalary()const;
	
	// ������
	double earnings()const;
	void print()const;
private:
	double baseSalary;
};
#endif // !BASEPLUS_H
