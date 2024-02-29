// static
/*
static data member
- Ŭ������ ��� ��ü�� �����ϴ� ������ ���纻, "Class-wide" ����
- Ŭ������ Ư���� ��ü �Ӽ��� �ƴ϶� Ŭ���� ��ü�� �Ӽ�
- ���� ����ó�� ���� �� ������ class scope�� ����

static member function
- static�� class member data�� function�� ���� ����
- this pointer�� ���� �ʴ´�.
- static data member�� ���������� �����Ѵ�. (class�� ��ü�� �������� �ʾƵ�, static ��� �Լ��� ȣ�� �� �� �ִ�.)
*/

#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
	Employee* e1ptr = new Employee("su", "ha");
	Employee* e2ptr = new Employee("A", "Bob");

	cout << "Number of Employee: " << e1ptr->getCount() << endl;
	// e2ptr->getCount() �� ����
	
	cout << "1: " << e1ptr->getFirstName() << " " << e1ptr->getLastName() << endl;
	cout << "2: " << e2ptr->getFirstName() << " " << e2ptr->getLastName() << endl;

	delete e1ptr;
	e1ptr = 0;	 // 0 = null, e1ptr = pointer, �ּҸ� null������ ��
	delete e2ptr;
	e2ptr = 0;

	cout << "count: " << Employee::getCount() << endl; // ���⼭�� e1ptr�� null���� �Ǿ����Ƿ� Employee�� �ҷ��;���.
	return 0;
}

#pragma region static �̻��
/*
count�� static ������ �������� �ʴ´ٸ� class ��ü�� ����� ������ ������ count�� ���� �����ǰ� �Ҹ�Ǿ
����� count�� �� �� ���� ������ �߻��Ѵ�.
���� class ��ü ��ο� ����Ǵ� ������ ����ϰ� �ʹٸ� static�� �ٿ��־�� �Ѵ�.
*/
#pragma endregion