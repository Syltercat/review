// Tree
/*
data structure
	1) Sequential Data structure: array, list -> Ž���ð� O(n)
	2) Hierarchical Data structure: �躸�� ����ó�� ��� ���迡 �ִ� �ڷ� ���� -> Ž���ð� O(logn)
		-> tree, �׷��� ������ ������ ����

Tree -> degree = 1�� ���°� list�� ��
degree -> �ڽ� -> degree�� �ʹ� �þ�� Ž���� O(n)�� �� �� ����

Tree ���
- Root: parent�� ���� ���
- Child: parent�� �ִ� ���
- Siblingss: �������� ���� parent�� ���� ��� ����
- Internal node: �ּ� �ϳ��� child�� ���� ���
- External node (leaf node): dhild�� ���� ���
- Ancestors of a node: ���� ���
- Depth of a node: ���� ����� ���� (root�� ��� Depth = 0)
- Height of tree: depty�� �ִ밪
- Descendant of node: �ڼ� ���
- Subtree : tree �ȿ� ���� ���� tree
- Degree: �ڽ� ����� ��

=> degree�� n�̸� Ž�� O(n)�̹Ƿ� Ž�� O(logn)�� �����ϱ� ���ؼ��� degree = 2���� �Ѵ�.

*/

// Tree Traversal order
/*
1) Preorder (���� ��ȸ)
		1
	2		3
4		5
����: 1 -> 2 -> 4 -> 5 -> 3

2) Inorder	(���� ��ȸ)
		1
	2		3
4		5
����: 4 -> 2 -> 5 -> 1 -> 3

3) Postorder(���� ��ȸ)
		1
	2		3
4		5
����: 4 -> 5 -> 2 -> 3 -> 1

*/

// Binary Tree (BT) / Binary Search Tree (BST)
/*
degree = 2�� tree
				1
	  2						3
4			5			6		7
		8		9

leaf node = �ǿ�����, ������ node = �������� ����Ʈ���� ��� �Ʒ��� ���� Ž���ϸ�
Preorder (���� ��ȸ) => ���� ǥ����� ���� �� �ִ�.
Inorder	(���� ��ȸ) => ���� ǥ����� ���� �� �ִ�.
Postorder(���� ��ȸ) => ���� ǥ����� ���� �� �ִ�.
*/

#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main() {
	// tree ����
	BinaryTree* t1 = new BinaryTree;

	int data1 = 1;
	int data2 = 13;
	int data3 = 14;
	int data4 = 21;
	int data5 = 41;
	int data6 = 51;
	int data7 = 21;
	int data8 = 11;
	int data9 = 112;
	int data10 = 131;

	// �� tree�� root �����
	t1->addRoot();

	// expendExternal�� ����
	t1->expandExternal(t1->root(), data1);
	t1->expandExternal(t1->root().left(), data2);
	t1->expandExternal(t1->root().right(), data3);
	t1->expandExternal(t1->root().left().left(), data4);
	t1->expandExternal(t1->root().left().right(), data5);
	t1->expandExternal(t1->root().right().left(), data6);
	t1->expandExternal(t1->root().right().right(), data7);
	t1->expandExternal(t1->root().left().left().left(), data8);
	t1->expandExternal(t1->root().left().left().right(), data9);
	t1->expandExternal(t1->root().right().right().left(), data10);

	// tree ������� ���
	cout << "print: " << endl;
	t1->printTree(t1->root(), 0);
	cout << endl;

	// preorder
	cout << "preorder: " << endl;
	t1->printTreePreOrder(t1->root());
	cout << endl;

	// inorder
	cout << "inorder: " << endl;
	t1->printTreeInOrder(t1->root());
	cout << endl;

	// postorder
	cout << "postorder: " << endl;
	t1->printTreePostOrder(t1->root());
	cout << endl;

	// tree ����
	delete t1;
}