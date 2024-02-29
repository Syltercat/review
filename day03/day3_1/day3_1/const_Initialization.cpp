#include <iostream>
#include "const_Initialization.h"
using namespace std;

Init::Init(int c, int i) : count(c), increment(i) {	//�ʱ�ȭ

}

void Init::print()const {
	cout << "count: " << count << ", increment: " << increment << endl;
}

#pragma region �߸��� �ʱ�ȭ ����, member initializer
/*
Init::Init(int c, int i) {
	count = c;
	increment = i;	// ERROR: const�� ������ ���� �ʱ�ȭ �� ���� member initializer�� �̿��ؾ� ��.
}

class::constructor():member initializer { } �� ���·� ���
member initializer �������� body ���� ���� ����ȴ�.
,�� ������ ������ member�� �ʱ�ȭ �� �� �ִ�.
*/
#pragma endregion