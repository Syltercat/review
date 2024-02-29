// ����(has-a) ����
//class�� �ٸ� class�� ��ü�� ����� ������ ����

#include <iostream>
#include "Employee.h"	// Employee �� include
using namespace std;

int main() {
	Date birth(7, 24, 1994);
	Date hire(3, 12, 2020);
	Employee manager("A", "B", birth, hire);	// ����

	cout << endl;
	manager.print();

	cout << endl;
	manager.print();

	cout << "\nTest Data constructor with invalid values\n";
	Date lastd(14, 52, 1994);
	cout << endl;
	return 0;
}

/*
�ڵ带 ������Ѻ��� AB�� �� �� �����ߴµ� Date�� �����ڰ� ���ϰ� ����Ͽ� �°� �� �� ����� �� Employee �����ڰ� �� �� ����Ǿ���.
�׷���  Employee �Ҹ��ڴ� ¦�� ���� �� ����� �ݸ�, Date�� ��쿡�� ���ϰ� ����ϸ��� ���� �� ���� �Ҹ��ڰ� ����� ���� Ȯ���� �� �־���.
�̴� defalut �����ڰ� �� �� ����Ǿ��� �����̴�.
main.cpp�� 11�� �ٿ��� birth�� hire�� ���ڷ� �޾ƿ��鼭 default ���� �����ڰ� �ҷ����� ������
ó���� ��µ� Date �Ҹ��ڴ� �� default �����ڿ� ���Ͽ� ����� ���̰�
�� ���� �Ҹ��ڴ� ó�� Date�� �����ڷ� ���� �ҷ��� ���̴�.
���� Date �Ҹ��ڴ� �� �� �ҷ�����.
*/