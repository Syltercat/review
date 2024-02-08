// Stack

/*
push()�� pop()���� ����
LIFO �����̴�. (Last In First out���� ���������� �� �Է��� ���� ���� ��µȴٴ� �ǹ��̴�.)
top�̶�� �ϴ� ���� �������� ���԰� ������ �Ͼ��.

�迭�̳� list�� Stack�� ���� �� �ִ�. (�ڿ��� �� Queue�� ��쿡�� �����ϴ�.)
�� �߿����� �迭�� ����� ���� �����ϴ�.

Stack���� Ǯ �� �ִ� ������ ������ ����.
1. Parentheses Matching (��ȣ ��Ī)
2. Stock Span Problem (�ְ� ����)
3. Postfix Notation (���� ǥ��� ����)
4. Maze Problem (�̷� ����)

�켱 day6_1 ������ Array�� Stack�� ���� ���̰� �� �Ŀ� ���� ������ �ϳ��� �ذ��� �� ���̴�.
*/

#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main() {
	// int�� ������ �� �ִ� stack ����
	ArrayStack<int> mystack;
	cout << mystack.size() << endl;

	mystack.push(1);
	mystack.push(2);
	cout << mystack.top() << endl;
	
	mystack.pop();
	cout << mystack.top() << endl;
	cout << mystack.size() << endl;

	// �� �迭���ÿ����� pop�� �� ��� �����͸� �����ϴ� ���� �ƴ϶�
	// t��� �ε����� �������� ������ �� �ִ� ���� ������ �� �ֱ� ������
	// ���� �Ҵ�� ������ ���ҵ��� ��ȯ�ϴ� delete�� ��������� �ʾҴ�.
	// �� ���� �Ҵ��� ��ȯ�ϴ� �κ��� �Ҹ��ڸ� �ҷ����鼭 ����Ǵµ� �Ʒ��� ���� �Ҹ��ڷ� ���� �����ϴ�.
	/*
	template <typename E> ArrayStack<E>::~ArrayStack() {
	  delete[] S;
	}
	*/

	return 0;
}