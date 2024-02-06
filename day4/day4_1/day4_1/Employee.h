#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	Employee(const char* const, const char* const);	// paramenter ���� const: ������ �ȿ� ����ִ� ���� �ٲ� �� ���� ��.
													// ������ ���� const: paramenter�� �����͸� ��ĥ �� ���� ��.
	~Employee();
	const char* getFirstName() const;	// �Լ� �� const: ��� �Լ��� ��� ������ �ٲ� �� ���Ԥ��ϱ� ����.
										//				  �Լ��� � ��� �����͵� �������� �ʰڴٴ� ���� �ǹ�
	const char* getLastName() const;	// �Լ� �� const: ��� �Լ��� ��ȯ�� �����Ϳ� ����ִ�(�����Ͱ� ����Ű��) ���� �ٲ� �� ���� ��.
										//				  �б� ���Ѹ� �ο�
	static int getCount();				// static �����͸� ����ϴ� �Լ��� static ���

private:
	char* firstName;
	char* lastName;
	static int count;
};
#endif