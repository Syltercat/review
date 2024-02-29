// ������ ������� binary tree�� �����Ͽ� �ۼ��ߴ�.

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

	void insert(Position, int);				// BST ��Ģ�� ���� ��� ����
	void delete_ele(Position, int);			// ��� ����

	Position find(Position, int);			// int i ������ ��ġã��
	Position treeSearch(Position, int);		// ���������� ��ġ�� ã�Ƽ� insert�� �� �� �Լ��� ����Ѵ�.

	Position inOrderSucc(Position);			// ������ȸ ����� (Inorder Successor, ���� ������) ���ϴ� �Լ�

	void printTree(Position, int);			
	void printTreeInOrder(Position);			
		
	
private:
	TreeNode* _root;
	int n;
};
#endif // !BST_H
