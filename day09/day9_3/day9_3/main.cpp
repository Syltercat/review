// Binary Search Tree
/*
���� Ž�� Ʈ�� (���ĵ� ���� Ʈ���̴�.)
1) ����� ���� subtree���� ����� ���Һ��� ���� ���� �ִ� ��常 �����Ѵ�.
2) ����� ������ subtree���� ����� ���Һ��� ū ���� �ִ� ��常 �����Ѵ�.
3) �ߺ� Ű(����)�� ������� �ʴ´�.
4) ���ʰ� ������ subtree�� ���� Ž�� Ʈ���̴�.
*/

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
	BST* t1 = new BST;
	int data = 0;
	t1->addRoot();
	for (int i = 0; i < 10; i++) {
		data = rand() % 100;
		cout << "Adding " << data << " into Tree" << endl;
		t1->insert(t1->root(), data);
	}

	t1->printTree(t1->root(), 0);
	cout << endl;

	t1->delete_ele(t1->root(), 58);
	t1->printTree(t1->root(), 0);
	cout << endl;

	cout << "inorder: ";
	t1->printTreeInOrder(t1->root());
	cout << endl;

	delete t1;

}