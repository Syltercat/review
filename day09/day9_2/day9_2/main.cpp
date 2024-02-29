// Tree
/*
data structure
	1) Sequential Data structure: array, list -> 탐색시간 O(n)
	2) Hierarchical Data structure: 계보나 족보처럼 상속 관계에 있는 자료 구조 -> 탐색시간 O(logn)
		-> tree, 그러나 데이터 삽입이 복잡

Tree -> degree = 1인 형태가 list가 됨
degree -> 자식 -> degree가 너무 늘어나도 탐색이 O(n)이 될 수 있음

Tree 용어
- Root: parent가 없는 노드
- Child: parent가 있는 노드
- Siblingss: 형제사이 같은 parent를 가진 노드 관계
- Internal node: 최소 하나의 child를 가진 노드
- External node (leaf node): dhild가 없는 노드
- Ancestors of a node: 조상 노드
- Depth of a node: 조상 노드의 갯수 (root의 경우 Depth = 0)
- Height of tree: depty의 최대값
- Descendant of node: 자손 노드
- Subtree : tree 안에 속한 작은 tree
- Degree: 자식 노드의 수

=> degree가 n이면 탐색 O(n)이므로 탐색 O(logn)을 만족하기 위해서는 degree = 2여야 한다.

*/

// Tree Traversal order
/*
1) Preorder (전위 순회)
		1
	2		3
4		5
순서: 1 -> 2 -> 4 -> 5 -> 3

2) Inorder	(중위 순회)
		1
	2		3
4		5
순서: 4 -> 2 -> 5 -> 1 -> 3

3) Postorder(후위 순회)
		1
	2		3
4		5
순서: 4 -> 5 -> 2 -> 3 -> 1

*/

// Binary Tree (BT) / Binary Search Tree (BST)
/*
degree = 2인 tree
				1
	  2						3
4			5			6		7
		8		9

leaf node = 피연산자, 나머지 node = 연산자인 이진트리의 경우 아래와 같이 탐색하면
Preorder (전위 순회) => 전위 표기식을 만들 수 있다.
Inorder	(중위 순회) => 중위 표기식을 만들 수 있다.
Postorder(후위 순회) => 후위 표기식을 만들 수 있다.
*/

#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main() {
	// tree 생성
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

	// 빈 tree에 root 만들기
	t1->addRoot();

	// expendExternal로 삽입
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

	// tree 모양으로 출력
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

	// tree 삭제
	delete t1;
}