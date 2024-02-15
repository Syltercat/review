#include <iostream>
#include "BinaryTree.h"
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

BinaryTree::BinaryTree() :_root(NULL), n(0) {

}

int BinaryTree::size()const {
	return n;
}

bool BinaryTree::empty()const {
	return size() == 0;
}

Position BinaryTree::root()const {
	return Position(_root);
}

PositionList BinaryTree::positions()const {
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}

void BinaryTree::addRoot() {
	_root = new TreeNode;
	n = 1;
}

void BinaryTree::expandExternal(const Position& p, int i) {
	TreeNode* v = p.v;
	v->elt = i;
	v->left = new TreeNode;
	v->right = new TreeNode;
	v->left->parent = v;
	v->right->parent = v;
	n += 2;
}

Position BinaryTree::removeAboveExternal(const Position& p) {
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

// cout과 재귀 함수의 순서 차이로 최종 출력 순서가 달라진다.
void BinaryTree::printTreeInOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreeInOrder(p.left());
	cout << *p << " ";
	printTreeInOrder(p.right());
}

void BinaryTree::printTreePreOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	cout << *p << " ";
	printTreePreOrder(p.left());
	printTreePreOrder(p.right());
}

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
	pl.push_back(Position(v)); // pl의 뒤에 v 넣음
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

	// 빈 노드가 아닐 경우
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