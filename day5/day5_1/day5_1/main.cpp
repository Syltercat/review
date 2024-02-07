// Inheritance

// �̷�
/*
���(is-a ����): ����Ʈ���� ������ ���� ȿ������ ����̴�.
	- ���� Ŭ������ ���� ���ο� Ŭ���� ����
	(���� Ŭ������ ������ ����� ��� �Լ��� ���, ���ο� ������ ����� �Լ��� �߰��Ͽ� ��üȭ �� �� �ִ�.)

	- �⺻ Ŭ����(base class)�κ��� ��ӹ޾� �Ļ� Ŭ����(Derived class)�� �����ȴ�.
	- tree ������ ���� ������ �����Ѵ�.

is-a�� has-a�� ����
	* is-a ���� - ���
		�Ļ� Ŭ������ ��ü�� �⺻ Ŭ������ ��üó�� ���
		ex) ���� Ż ���̴�.
	* has-a ���� - ���� ����
		��ü�� �ٸ� class�� ��ü�� ����� ����
		ex) ������ �����밡 �ִ�.
		has-a ����� �������� �ʱ�ȭ list���� �ʱ�ȭ ����� �Ѵ�.

base class�� derived class
	- �⺻ Ŭ������ �Ļ� Ŭ�������� �� ���� ������ ��ü�� ǥ���Ѵ�. Ż ��(base) > ��(derived)

public ���
	- class AShape:public Shape -> AShape is a Shape
	  AShape Ŭ������ Shape Ŭ�����κ��� ��ӹ���.
	- private ������� ���������� ������ �� ������ ���� ��ӵǱ� ������ ��ӵ� public ��� �Լ��� ���� ���� �����ϴ�.

protected member
	- public�� private�� �߰� �ܰ�
	- �⺻ Ŭ������ �Ļ� Ŭ���� ����� ���� ���� ������ �����ϴ�.
*/

// inheritance hierarchy and (using protected data / private data)
/*
CommissionEmployee - BasePulsCommissionEmployee ��� ����

CommissionEmployee
	- firstname, lastname, SSN, commission_rate(�Ǹ� ����), gross_sale_amount(������)

BasePlusCommissionEmployee
	- firstname, lastname, SSN, commission_rate, gross_sale_amount
	- �⺻ ����

<CommissionEmployee Class>
   [header]
	- public
		> ������
		> get / set
		> ��� �Լ�: earnings(commission_rate * gross_sale_acount), print
	-private
		> firstname, lastname, SSN, commission_rate(�Ǹ� ����), gross_sale_amount(������)

����� ������� �ʴ´ٸ�
<BasePlusCommissionEmployee>
   [header]
	- public
		> ������
		> get / set
		> ��� �Լ�: earnings(commission_rate * gross_sale_acount), print
	-private
		> firstname, lastname, SSN, commission_rate(�Ǹ� ����), gross_sale_amount(������), baseSalary
	
	=> �̰� �� ó������ �ۼ��ϰ� �����ؾ� ��. (duplicating)

����� ����ϸ� ���� ������ ���� ���� (��, ������, �Ҹ��ڴ� ��ӵ��� ����.)
	=> ��� �Ŀ��� �߰��� ��� �Լ��� ��� �����͸� �ۼ��ϸ� ��. 
	(�Ļ� Ŭ�������� �Լ��� ������(override)�ϰ� �ʹٸ� "�⺻Ŭ�����̸�::�Լ��̸�"���� ȣ���ؾ� ��)

public ����� �ϸ� protected data�� ����ϴ� ���� private data�� ����ϴ� ��� �� ������ ������.
���� ���� private�� ������ ����� �����߱� ������ private data�� inheritance hierarchy�� ����ϴ� ����̴�.

protected ���: �⺻ Ŭ���� public�� protected ��� -> �Ļ� Ŭ������ protected ���
private ���: �⺻ Ŭ���� public�� protected ��� -> �Ļ� Ŭ������ private ���

�Ϲ������� private data�� ����ϱ� ������ protected data�� �ڵ忡 �������� �ʾҴ�.
private data�� ����ϴ� ������ ������ ����.

* protected data ����� ��/����
   (����)
	- �Ļ� class���� �⺻ class�� ������ ����� ���� ������ �����ϴ�.
	- ���� ������ �����ϹǷ� set / get ȣ���� �ʿ� ���� ������ ���� �ӵ��� ���� ���ȴ�.
   (����)
	- set / get �Լ��� ������� �ʱ� ������ ��ȿ�� üũ�� �Ұ����ϴ�.
	  (�Ϲ������� set, get�� ��ȿ���� �˻��ϴ� �ڵ带 �����ϴµ� �� �κ��� ���� ������ �Ļ� Ŭ������ ���������� ���� �Ҵ�� �� �ִ�.)
	- �Ļ� Ŭ���� �Լ��� �⺻ Ŭ���� ������ �� �������̰� �Ǿ� �⺻ Ŭ������ �����ϸ� �Ļ� Ŭ���� ���� �����ؾ� �Ѵ�.
	  (�μ����� ����(fragile) ����Ʈ��� �ȴ�.

=> ���� ������� ���� proected data�� ����ϸ� encapsulation�� ��Ģ�� ��ų �� ���� �ȴ�.	  

	+)encapsulation => ���� ����: Ŭ������ ��Ű¡�Ͽ� ���� ������ ���ܼ� ��ü�� �������� �������� ���� �� �ִ�.
								  �̸� ��ü�� ���ȭ��� �ϴµ� ��ü�� ���ȭ�� �� �Ǿ��ִٸ� ��� ������ ������ �����ϴ�.

�׷��� �⺻ Ŭ������ private ����� ���� ������ �Ұ����ϴ�.
�⺻ Ŭ������ public ��� �Լ��� ���ؼ� �����ؾ� �Ѵ�.
								  
*/

#include <iostream>
#include <iomanip>	// setprecision(�Ҽ��� ��� ���� ����) ����� ���� include
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main() {
	CommissionEmployee employee("aa", "Bob", "123-123", 10000, 0.06);
	cout << fixed << setprecision(2);

	employee.setCommissionRate(8000);
	employee.setGrossSale(0.1);
	
	employee.print();
	cout << employee.earnings() << endl;
	cout << endl;

	// �Ļ� class
	BasePlusCommissionEmployee employee2("aa2", "Bob2", "234-234", 5000, 0.04, 300);
	employee2.print();
	cout << employee2.earnings() << endl;

	employee2.setBaseSalary(1000);
	cout << endl;
	employee2.print();
	cout << employee2.earnings() << endl;

	return 0;
}