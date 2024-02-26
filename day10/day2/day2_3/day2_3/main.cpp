// ������ �Ҹ���
/*
��ü�� ������ �Ҹ�� ���������� �����ڿ� �Ҹ��ڴ� �ڵ� ȣ��ȴ�.

�Ϲ������� �������� ȣ�� ������ �������� �Ҹ��ڰ� ȣ��ȴ�.

��ü�� ���� �����̸� main �Լ� �������� �����Ǿ� ���α׷� ���� ���� ����ִٰ�
main �Լ��� ����� �Ŀ� �Ҹ��ڸ� ȣ���Ͽ� �Ҹ�ȴ�.

��ü�� �ڵ� ���� ������ ��� ��ü�� ������ �� �����ڸ� ȣ���Ͽ� �����ȴ�.
�� �� ��ü�� ���Ե� scope�� ��� �� �Ҹ��ڸ� ȣ���Ͽ� �Ҹ��Ѵ�.

���� ���� ������ ��� �� �ѹ� �����Ǿ� ���α׷� ���� ���� ����ִ�.
�����ڴ� ��ü�� ó�� ������ �� �� �ѹ� ȣ��Ǹ� main �Լ��� ����Ǹ� �Ҹ��ڸ� ȣ���Ͽ� �Ҹ��Ѵ�.

*/

#include <iostream>
#include "Createanddestroy.h"

using namespace std;

void create(void);
CreateAndDestroy first(1, "(global before main)");				// 1. ��������

int main() {
	cout << "\nMain Function: Execution Begins" << endl;
	CreateAndDestroy second(2, "(local automatic in main)");	// 2. �ڵ� ���� ����
	static CreateAndDestroy third(3, "(local static in main)");	// 3. ���� ���� ����

	create();													// 5. �ڵ� ���� ����, 6. ���� ��������, 7. �ڵ� ���� ����

	cout << "\Main Funtion: Excution Resumes" << endl;
	CreateAndDestroy fourth(4, "(local automatic in main)");	// 4. �ڵ� ���� ����
	cout << "\nMain Function: Excution Ends" << endl;
	return 0;
}

void create(void) {
	cout << "\Create Funtion: Excution Begins" << endl;
	CreateAndDestroy fifth(5, "(local( automatic in create)");
	static CreateAndDestroy sixth(6, "(local static in create)");
	CreateAndDestroy seventh(7, "(local automatic in create)");
	cout << "\nCreate Funtion: Excution Ends" << endl;
}

/*
������(n) �Ҹ���(~n) ȣ�� ����
1 -> (main �Լ�) -> 2 -> 3 -> (create �Լ�) -> 5 -> 6 -> 7 -> ~7 -> ~5 -> (create �Լ� ����) -> 4 -> ~4 -> ~2 -> ~6 -> ~3 -> ~1

���� ������ ���� ������� �� �� ���� ������ ������� �Ϳ� ����
*/