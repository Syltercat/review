// Binary Search Tree
/*
이진 탐색 트리 (정렬된 이진 트리이다.)
1) 노드의 왼쪽 subtree에는 노드의 원소보다 작은 값이 있는 노드만 포함한다.
2) 노드의 오른쪽 subtree에는 노드의 원소보다 큰 값이 있는 노드만 포함한다.
3) 중복 키(원소)를 허용하지 않는다.
4) 왼쪽과 오른쪽 subtree도 이진 탐색 트리이다.
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