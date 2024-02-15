#include <iostream>
#include "BinaryTree.h"
using namespace std;

TreeNode::TreeNode() :elt(), parent(NULL), left(NULL), right(NULL) {

}

TreeNode::TreeNode(Elem e) :elt(e), parent(NULL), left(NULL), right(NULL) {

}

Position::Position(TreeNode* _v = NULL) :v(_v) {

}

// ��尡 ������ element�� ��ȯ
Elem& Position::operator*() {
	return v->elt;
}

// left child�� �����´�.
Position Position::left()const {
	return Position(v->left);
}

// right child�� �����´�.
Position Position::right()const {
	return Position(v->right);
}

// parent�� �����´�.
Position Position::parent()const {
	return Position(v->parent);
}

// ��� ��ġ�� ������� Ȯ���Ѵ�.
bool Position::isNULL() {
	return v == NULL;
}

// ��� ��ġ�� root���� Ȯ���Ѵ�.
bool Position::isRoot()const {
	return v->parent == NULL;
}

// ��� ��ġ�� external���� Ȯ���Ѵ�.
bool Position::isExternal()const {
	// leaf node�� ������ external�̹Ƿ� ���ʰ� ������ child ��尡 �Ѵ� ������ Ȯ��
	return v->left == NULL && v->right == NULL;
}

BinaryTree::BinaryTree() :_root(NULL), n(0) {

}

// ����� �� ��ȯ
int BinaryTree::size()const {
	return n;
}

// tree�� ������� Ȯ���Ѵ�.
bool BinaryTree::empty()const {
	return size() == 0;
}

// root ���� ��ȯ
Position BinaryTree::root()const {
	return Position(_root);
}

// ��� ����� list
PositionList BinaryTree::positions()const {
	PositionList pl;
	// ���� ��ȸ
	preorder(_root, pl);
	// ��ȸ�� ��� ������ list ��ȯ
	return PositionList(pl);
}

// root�� ��带 �߰��Ѵ�.
void BinaryTree::addRoot() {
	_root = new TreeNode;
	n = 1;
}

// external ��忡 child�� �޾��ش�. (tree Ȯ��)
void BinaryTree::expandExternal(const Position& p, int i) {
	TreeNode* v = p.v;			// p ��ġ�� ��� v
	v->elt = i;					// element =  i
	v->left = new TreeNode;		// left, right�� NULL child ����
	v->right = new TreeNode;
	v->left->parent = v;		// ������ child�� parent node�� v�� ����
	v->right->parent = v;
	n += 2;						// left, right child�� �������� ũ�� 2��ŭ ����
}

Position BinaryTree::removeAboveExternal(const Position& p) {
	TreeNode* w = p.v;				// p��ġ ��� = w
	TreeNode* v = w->parent;		// w�� �θ� ��� = v
	TreeNode* sib = (w == v->left ? v->right : v->left);	// v�� ���� ��� = sib

	// �����ϰ� ���� ��尡 root���
	if (v == _root) {
		// �����ϰ� ���� ����� ���� ��带 root�� �ϰ�
		_root = sib;
		// ��������� �θ� null�� ��
		sib->parent = NULL;
	}
	// �ƴ϶��
	else {
		// p�� ���θ� ��带 g
		TreeNode* g = v->parent;
		// �����ϰ� ���� ����� �θ� ��尡 g�� left child���
		if (v == g->left) {
			// �����ϰ� ���� ���(w)�� �θ� ��带 w�� �������� �ٲ۴�.
			g->left = sib;
		}
		// right child���
		else {
			// ���θ� ����� right child�� �������� �ٲ۴�.
			g->right = sib;
		}
		// �� �� ���� ����� �θ��尡 ������ ���θ� ��尡 �ȴ�.
		sib->parent = g;
	}
	// �����ϰ� ���� ���� �� �θ� ��带 �����Ѵ�.
	delete w;
	delete v;
	// ũ�⸦ 2��ŭ ���δ�.
	n -= 2;
	return Position(sib);
}

// cout�� ��� �Լ��� ���� ���̷� ���� ��� ������ �޶�����.
// ���� ��ȸ
void BinaryTree::printTreeInOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreeInOrder(p.left());
	cout << *p << " ";
	printTreeInOrder(p.right());
}

// ���� ��ȸ
void BinaryTree::printTreePreOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	cout << *p << " ";
	printTreePreOrder(p.left());
	printTreePreOrder(p.right());
}

// ���� ��ȸ
void BinaryTree::printTreePostOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreePostOrder(p.left());
	printTreePostOrder(p.right());
	cout << *p << " ";
}

// preorder traversal
void BinaryTree::preorder(TreeNode* v, PositionList& pl) const {
	pl.push_back(Position(v)); // pl�� �ڿ� v ����
	if (v->left != NULL) {
		preorder(v->left, pl);	// traverse left subtree
	}
	if (v->right != NULL) {
		preorder(v->right, pl);	// traverse right subtree
	}
}

int BinaryTree::is_Internal(Position p) {
	TreeNode* v = p.v;
	if (v->left != NULL || v->right != NULL) {
		return 1;
	}
	else return 0;
}

int BinaryTree::is_External(Position p) {
	TreeNode* v = p.v;
	if (v->left == NULL && v->right == NULL) {
		return 1;
	}
	else return 0;
}

void BinaryTree::printTree(Position p, int level) {
	TreeNode* v = NULL;

	// �� ��尡 �ƴ� ���
	if (p.v != NULL) {
		if (level == 0) {
			cout << "\nRoot (data: ";
		}
		cout << *p << ")" << endl;
		v = (p.left()).v;
		for (int i = 0; i < level; i++) {
			cout << "\t";
		}
		if (v != NULL) {
			cout << "L(data: ";
			printTree(v, level + 1);
		}
		else {
			cout << "L(data: NULL)" << endl;
		}
		v = (p.right()).v;
		for (int i = 0; i < level; i++) {
			cout << "\t";
		}
		if (v != NULL) {
			cout << "R(data: ";
			printTree(v, level + 1);
		}
		else {
			cout << "R(data: NULL)" << endl;
		}
	}
}