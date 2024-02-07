//����ó��

// if-else ���� ���� ����ó���� �Ѱ谡 �ִ�.

//try & chatch
/*
- try & chatch
	try(
		// ���� �߻� ���� �κ�
	}
	catch (ó���Ǿ�� �ϴ� ������ ����){
		// ���ܸ� ó���ϴ� �ڵ�
	}

 => ���
	try {
		if(���� ��Ȳ1)
			throw ex1;	// ���� ��Ȳ1 �߻������� ���� ����
			...
		if(���� ��Ȳ2)
			throw ex2;
			...
	}
	catch (exception1 ex1) {
		// ���� ��Ȳ1�� ó���ϴ� �ڵ�
	}
	catch (exception2 ex2) {
		// ���� ��Ȳ2�� ó���ϴ� �ڵ�
	}

*/

#include <iostream>
using namespace std;

int divide(int a, int b);

int main() {
	int a = 0, b = 0;
	cout << "a, b insert: ";
	cin >> a >> b;

	try {
		cout << "a/b = " << divide(a, b) << endl;
	}
	catch (int ex) {
		cout << "�Է��� ���� " << ex << endl;
		cout << "Error: �߸��� �Է�\n";
	}
	// ���� ���� catch ����� �����ϴ�.
	return 0;
}

int divide(int a, int b) {
	if (b == 0)
		throw b;	// ���� ���ǿ� �����ϴ� ��� throw�� ���� ���� ���� catch�� ����
		//���⿡ ������ �߰��ϸ� �ϳ��� try�� ���� ���� catch�� ���� �� �ִ�.

	return a / b;
}