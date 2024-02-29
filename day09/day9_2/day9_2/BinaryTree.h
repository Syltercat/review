#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <list>			// PositionList�� ���� include
using namespace std;

typedef int Elem;

// linked list �������� tree�� ���� ���̴�.
struct TreeNode
{
	TreeNode();			// ������
	TreeNode(Elem);		// ���� ������
	Elem elt;			// ����
	TreeNode* parent;	// parent node
	TreeNode* left;		// left node
	TreeNode* right;	// right node
};

class Position {
	friend class BinaryTree;	// Tree�� ���� ������ ��
public:
	Position(TreeNode*);	// ������
	Elem& operator*();		// ������ �����ε�
	Position left()const;	// ���� �ڽ� ���
	Position right()const;	// ������ �ڽ� ���
	Position parent()const;	// �θ� ���
	bool isNULL();			// ��尡 ������� Ȯ��
	bool isRoot() const;	// ��尡 ��Ʈ���� Ȯ��
	bool isExternal()const;	// ��尡 leaf ����̴� Ȯ��
private:
	TreeNode* v;			// ��� ������
};
typedef list<Position> PositionList;	// point list 


// tree class �ȿ� tree�� ������ ������ �ϴ� Position class ��� 
class BinaryTree {
public:
	BinaryTree();									// ������
	int size() const;								// node ��

	bool empty() const;								// tree�� ������� Ȯ��
	Position root() const;							// ��尡 root���� Ȯ��
	PositionList positions() const;					// Treenode�� list

	void addRoot();									// �� tree�� root �߰�
	void expandExternal(const Position&, int);		// leaf ��� Ȯ�� -> tree Ȯ��
	Position removeAboveExternal(const Position&);	// Ư�� ���� �� ����� �θ��� ����

	void printTreeInOrder(Position);				// inorder�� ���
	void printTreePreOrder(Position);				// preoder�� ���
	void printTreePostOrder(Position);				// postorder�� ���

	void preorder(TreeNode*, PositionList&) const;		// preorder utillity

	int is_Internal(Position);						// internal ������� Ȯ��
	int is_External(Position);						// leaf ������� Ȯ��
	void printTree(Position, int);					// tree������� ���
	// �̸� �����ϱ� ���� null�� ���־���.(���� 0�� null�� �����ϸ� �ȴ�.)
private:
	TreeNode* _root; // root ������
	int n;			 // ����� ��
};
#endif // !BINARYTREE_H
