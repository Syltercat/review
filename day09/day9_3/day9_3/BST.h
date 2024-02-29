// 이전에 만들었던 binary tree를 응용하여 작성했다.

#pragma once
#ifndef BST_H
#define BST_H

#include <iostream>
#include <list>
using namespace std;

typedef int Elem;

struct TreeNode {
	TreeNode();
	TreeNode(Elem);
	Elem elt;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
};

class Position {
	friend class BST;
public:
	Position(TreeNode*);
	Elem& operator*();
	Position left()const;
	Position right()const;
	Position parent()const;
	bool isNULL();
	bool isRoot()const;
	bool isExternal()const;
private:
	TreeNode* v;
};
typedef list<Position> PositionList;

class BST {
public:
	BST();
	int size()const;
	bool empty()const;
	Position root()const;
	PositionList positions()const;

	void preorder(TreeNode*, PositionList&)const;

	int is_Internal(Position);					
	int is_External(Position);

	void addRoot();
	void expandExternal(const Position&, int);
	Position removeAboveExternal(const Position&);

	void insert(Position, int);				// BST 규칙에 따라 노드 삽입
	void delete_ele(Position, int);			// 노드 삭제

	Position find(Position, int);			// int i 원소의 위치찾기
	Position treeSearch(Position, int);		// 결정적으로 위치를 찾아서 insert할 때 이 함수를 사용한다.

	Position inOrderSucc(Position);			// 중위순회 계승자 (Inorder Successor, 중위 후행자) 구하는 함수

	void printTree(Position, int);			
	void printTreeInOrder(Position);			
		
	
private:
	TreeNode* _root;
	int n;
};
#endif // !BST_H
