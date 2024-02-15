#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <list>			// PositionList를 위해 include
using namespace std;

typedef int Elem;

// linked list 형식으로 tree를 만들 것이다.
struct TreeNode
{
	TreeNode();			// 생성자
	TreeNode(Elem);		// 복사 생성자
	Elem elt;			// 원소
	TreeNode* parent;	// parent node
	TreeNode* left;		// left node
	TreeNode* right;	// right node
};

class Position {
	friend class BinaryTree;	// Tree의 접근 권한을 줌
public:
	Position(TreeNode*);	// 생성자
	Elem& operator*();		// 연산자 오버로딩
	Position left()const;	// 왼쪽 자식 노드
	Position right()const;	// 오른쪽 자식 노드
	Position parent()const;	// 부모 노드
	bool isNULL();			// 노드가 비었는지 확인
	bool isRoot() const;	// 노드가 루트인지 확인
	bool isExternal()const;	// 노드가 leaf 노드이니 확인
private:
	TreeNode* v;			// 노드 포인터
};
typedef list<Position> PositionList;	// point list 


// tree class 안에 tree의 포인터 역할을 하는 Position class 사용 
class BinaryTree {
public:
	BinaryTree();									// 생성자
	int size() const;								// node 수

	bool empty() const;								// tree가 비었는지 확인
	Position root() const;							// 노드가 root인지 확인
	PositionList positions() const;					// Treenode의 list

	void addRoot();									// 빈 tree에 root 추가
	void expandExternal(const Position&, int);		// leaf 노드 확장 -> tree 확장
	Position removeAboveExternal(const Position&);	// 특정 노드와 그 노드의 부모노드 삭제

	void printTreeInOrder(Position);				// inorder로 출력
	void printTreePreOrder(Position);				// preoder로 출력
	void printTreePostOrder(Position);				// postorder로 출력

	void preorder(TreeNode*, PositionList&) const;		// preorder utillity

	int is_Internal(Position);						// internal 노드인지 확인
	int is_External(Position);						// leaf 노드인지 확인
	void printTree(Position, int);					// tree모양으로 출력
	// 이를 보안하기 위해 null을 빼주었다.(끝의 0을 null로 생각하면 된다.)
private:
	TreeNode* _root; // root 포인터
	int n;			 // 노드의 수
};
#endif // !BINARYTREE_H
