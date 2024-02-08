// Parenthneses Matching
/*
day6_1���� �ۼ��ߴ� �迭 ������ �̿��Ͽ� ��ȣ ��Ī �ڵ带 �ۼ��� ���̴�.

���ڿ��� ��ȣ�� ���ʷ� �����ϸ鼭 open ��ȣ�� ������ push, close ��ȣ�� ������
��ȣ�� ¦�� �´��� Ȯ�� �� pop�� �����ϴ� ���·� �ۼ��� ���̴�.

�����󿡼� ������ ��
	stack�� ������� Ȯ���� ��
	��ȣ�� ¦�� �´��� ���� ��
	��ȣ�� ¦�� ���� �ʴ� ��츦 ��Ƴ� ��

��ȣ�� ¦�� ���� �ʴ� ���(false)
1. close ��ȣ�� �������� stack�� top�� ��ȣ�� ¦�� ���� �ʴ� ���
2. close ��ȣ�� �������� stack�� ����ִ� ���
3. ���ڿ��� ������ ���������� stack�� ��ȣ�� ���� ���
*/

#include <iostream>
#include "ArrayStack.h"

// map ��� ����
/*
map�� key�� value�� ������ �̷���� tree�̴�.
�˻� ��ɵ� ������ �ֱ� ������ ��ȣ ���� key�� value�� �ΰ� ����ϱ⿡ �����ϴ�.
*/
#include <map>	


using namespace std;

int main() {
	ArrayStack<char> mystack;
	char arr[50];	// ���� �Է¹��� �迭
	int arr_size = sizeof(arr);
	
	// key = close ��ȣ, value = open ��ȣ��� ����.
	// close�� �������� ��Ī�Ǵ� open ��ȣ�� ã�� ���̱� ������ key�� close�� �Ǿ�� �Ѵ�.
	map <char, char> bucket = { {')','('}, {'}','{'},{']', '['} };

	cout << "���� �Է��ϼ���.\n";
	cin >> arr;

	// �˻�
	for (int i = 0; arr[i] != '\0'; i++) {
		// open ��ȣ�� ������ ��� => push
		if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') {
			mystack.push(arr[i]);
		}
		// close ��ȣ�� ������ ��� => open ��ȣ�� ���缭 pop
		if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') {
			
			// close ��ȣ�� �����ִµ� ������ �� ���
			if (mystack.empty()) {
				// ¦�� �´� open ��ȣ�� ���� ������ false
				cout << "Ʋ�� ��ȣ ��Ī�Դϴ�.\n";
				return 0;
			}

			// ���ÿ� ���Ұ� �����ִ� ���
			else {
				// ¦�� �´� open ��ȣ�� �ƴ� ���
				if (bucket.find(arr[i])->second != mystack.top()) {
					cout << "Ʋ�� ��ȣ ��Ī�Դϴ�.\n";
					return 0;
				}

				// ¦�� �´� open ��ȣ�� ���
				else {
					mystack.pop();
				}
			}
		}
	}

	// �˻縦 ���� ���� �� ������ ������� �˻�
	if (mystack.empty()) {
		cout << "�ùٸ� ��ȣ ��Ī�Դϴ�.\n";
		return 1;
	}
	else {
		cout << "Ʋ�� ��ȣ ��Ī�Դϴ�.\n";
		return 0;
	}
}
