#include <iostream>
#include "BST.h"
using namespace std;

TreeNode::TreeNode() :elt(), parent(NULL), left(NULL), right(NULL) {

}

TreeNode::TreeNode(Elem e) :elt(e), parent(NULL), left(NULL), right(NULL) {

}

Position::Position(TreeNode* _v = NULL) :v(_v) {

}

Elem& Position::operator*() {
	return v->elt;
}

Position Position::left()const {
	return Position(v->left);
}

Position Position::right()const {
	return Position(v->right);
}

Position Position::parent()const {
	return Position(v->parent);
}

bool Position::isNULL() {
	return v == NULL;
}

bool Position::isRoot()const {
	return v->parent == NULL;
}

bool Position::isExternal()const {
	return v->left == NULL && v->right == NULL;
}

BST::BST() :_root(NULL), n(0) {

}

int BST::size()const {
	return n;
}

bool BST::empty()const {
	return size() == 0;
}

Position BST::root()const {
	return Position(_root);
}

PositionList BST::positions()const {
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}

// preorder traversal
void BST::preorder(TreeNode* v, PositionList& pl) const {
	pl.push_back(Position(v)); // pl�� �ڿ� v ����
	if (v->left != NULL) {
		preorder(v->left, pl);	// traverse left subtree
	}
	if (v->right != NULL) {
		preorder(v->right, pl);	// traverse right subtree
	}
}

int BST::is_Internal(Position p) {
	TreeNode* v = p.v;
	if (v->left != NULL || v->right != NULL) {
		return 1;
	}
	else return 0;
}

int BST::is_External(Position p) {
	TreeNode* v = p.v;
	if (v->left == NULL && v->right == NULL) {
		return 1;
	}
	else return 0;
}

void BST::addRoot() {
	_root = new TreeNode;
	n = 1;
}

void BST::expandExternal(const Position& p, int i) {
	TreeNode* v = p.v;
	v->elt = i;
	v->left = new TreeNode;
	v->right = new TreeNode;
	v->left->parent = v;
	v->right->parent = v;
	n += 2;
}

Position BST::removeAboveExternal(const Position& p) {
	TreeNode* w = p.v;
	TreeNode* v = w->parent;
	TreeNode* sib = (w == v->left ? v->right : v->left);

	if (v == _root) {
		_root = sib;
		sib->parent = NULL;
	}
	else {
		TreeNode* g = v->parent;
		if (v == g->left) {
			g->left = sib;
		}
		else {
			g->right = sib;
		}
		sib->parent = g;
	}
	delete w;
	delete v;
	n -= 2;
	return Position(sib);
}

// i���� ������ ��� ����
void BST::insert(Position root, int i) {
	// root���� ���� k�� ���� ��ġ�� ã�� �� ���� p��� �Ѵ�.
	Position p = treeSearch(root, i);
	// p�� ����Ű�� ��带 v��� �Ѵ�.
	TreeNode* v = treeSearch(root, i).v;

	// internal ����̸� �̹� ���� �־��� ���̹Ƿ� ���� �ٽ� ������ �ʴ´�.
	if (is_Internal(p)) {
		return;
	}
	// external ����̸� ���� ���� ���̹Ƿ� i�� �־���� �Ѵ�.
	else {
		// p ��ġ�� k�� �ְ� 
		expandExternal(p, i);
		// ũ�⸦ ������Ų��.
		n++;
		return;
	}
}

// i ���� ������ ��� ����
void BST::delete_ele(Position root, int i) {
	// i���� ������ ����� ��ġ�� ã�Ƽ� p��� �Ѵ�.
	Position p = treeSearch(root, i);

	// external�̸� ���� �������� �ʴ� ���̱� ������ �������� �ʾƵ� �ȴ�.
	if (is_External(p)) {
		cout << "X\n";
		return;
	}

	// ������ ��尡 ������ ��� ������ ����� ���� �ڽ��� z�� �Ѵ�.
	Position z = p.left();

	// z�� internal�̸� p�� ������ �ڽ� ���带 z�� �ٲ۴�.
	if (!is_External(z)) {
		z = p.right();
	}

	// z�� external�̸� �׳� z ���� �θ��带 �����Ѵ�.
	if (is_External(z)) {
		removeAboveExternal(z);
		return;
	}
	
	/// �ƴϸ� ���� ��ȸ ����ڸ� �̿��Ѵ�.
	else {
		Position y = inOrderSucc(p);	// ����ڸ� y�� �Ѵ�
		z = y.left();					// ����� ����� ���� ��带 z�� �Ѵ�.
		TreeNode* v = p.v;				// p��ġ�� ��带 v��� �Ѵ�.
		TreeNode* w = y.v;				// y��ġ�� ��带 w��� �Ѵ�.
		v->elt = w->elt;				// v�� elt�� w�� elt�� �Ѵ�
		removeAboveExternal(z);			// z ���� y ��带 �����Ѵ�.
		return;
	}
}

// i��� data�� ã�� ���� �� ����ϴ� �Լ�
Position BST::find(Position root, int i) {
	// root���� ���鼭 i���� ��ġ�� ã�´� ã�� k ��ġ�� p��� �Ѵ�.
	Position p = treeSearch(root, i);
	// p�� ����Ű�� ��带 v��� �Ѵ�.
	TreeNode* v = treeSearch(root, i).v;

	// internal�̸� �״�� p�� ����ϰ�
	if (is_Internal(p)) {
		return p;
	}
	// external�̸� ���� ���ٴ� �ǹ��̱� ������ null�� ����ϴ�.
	else return NULL;
}

// i�� �� �ְų� ������ ��ġ�� ã�� �Լ�
Position BST::treeSearch(Position p, int i) {
	// p�� ����Ű�� ��带 v��� ����
	TreeNode* v = p.v;

	// external�̸� ã�� ���� ���̹Ƿ� �� ��ġ�� i�� ������ �� �ְ� �ϱ�����
	// p�� �״�� return �Ѵ�.
	if (is_External(p)) {
		return p;
	}
	// ���� i�� ���� ����� ���� elt�� ������ �̹� �����ϴ� ���̴�
	// �� ��ġ�� return �Ѵ�.
	if (i == v->elt) {
		return p;
	}
	// ã�����ϴ� i�� elt���� �۴ٸ� elt ���� �ִ� ����� ���ʿ� �����ϴ� ���̹Ƿ�
	// p.left()�� ���ȣ���Ѵ�.
	else if (i < v->elt) {
		return treeSearch(p.left(), i);
	}
	// ã�����ϴ� i�� elt���� ũ�ٸ� elt ���� �ִ� ����� �����ʿ� �����ϴ� ���̹Ƿ�
	// p.right()�� ���ȣ���Ѵ�.
	else {
		return treeSearch(p.right(), i);
	}
}

// ������ �� ����� ��带 ã�� ���� �����ڸ� ã�� �Լ�
Position BST::inOrderSucc(Position p) {
	// �����ڸ� ã������ �켱 ���� ��ġ���� ������ �ڽ����� �Ѿ���Ѵ�.
	Position z = p.right();

	// z��忡�� ������ ���� �� �������� �ȴ�.
	// z�� �̹� External ����� �����ڰ� z�� ���̱� ������ z�� return �Ѵ�.
	if (is_External(z)) {
		return z;
	}

	// z�� internal ����� �ٽ� ������ ���� ��� ������ ��
	while (is_Internal(z.left())) {
		z = z.left();
	}
	// �� �������� external ��带 ������ �Ǹ� �� ��ġ�� ���� �������̹Ƿ� ����ڰ� �Ǳ� ������ return �Ѵ�.
	return z;
}


void BST::printTree(Position p, int level) {
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

// cout�� ��� �Լ��� ���� ���̷� ���� ��� ������ �޶�����.
void BST::printTreeInOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreeInOrder(p.left());
	cout << *p << " ";
	printTreeInOrder(p.right());
}
