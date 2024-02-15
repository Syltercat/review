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
	pl.push_back(Position(v)); // pl의 뒤에 v 넣음
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

// i값을 가지는 노드 삽입
void BST::insert(Position root, int i) {
	// root부터 값이 k인 곳의 위치를 찾아 그 곳을 p라고 한다.
	Position p = treeSearch(root, i);
	// p가 가리키는 노드를 v라고 한다.
	TreeNode* v = treeSearch(root, i).v;

	// internal 노드이면 이미 값이 넣어진 것이므로 값을 다시 넣지는 않는다.
	if (is_Internal(p)) {
		return;
	}
	// external 노드이면 값이 없는 것이므로 i를 넣어줘야 한다.
	else {
		// p 위치에 k를 넣고 
		expandExternal(p, i);
		// 크기를 증가시킨다.
		n++;
		return;
	}
}

// i 값을 가지는 노드 삭제
void BST::delete_ele(Position root, int i) {
	// i값을 가지는 노드의 위치를 찾아서 p라고 한다.
	Position p = treeSearch(root, i);

	// external이면 값이 존재하지 않는 것이기 때문에 삭제하지 않아도 된다.
	if (is_External(p)) {
		cout << "X\n";
		return;
	}

	// 삭제할 노드가 존재할 경우 삭제할 노드의 왼쪽 자식을 z라 한다.
	Position z = p.left();

	// z가 internal이면 p의 오른쪽 자식 ㄴ드를 z로 바꾼다.
	if (!is_External(z)) {
		z = p.right();
	}

	// z가 external이면 그냥 z 노드와 부모노드를 삭제한다.
	if (is_External(z)) {
		removeAboveExternal(z);
		return;
	}
	
	/// 아니면 중위 순회 계승자를 이용한다.
	else {
		Position y = inOrderSucc(p);	// 계승자를 y로 한다
		z = y.left();					// 계승자 노드의 왼쪽 노드를 z로 한다.
		TreeNode* v = p.v;				// p위치의 노드를 v라고 한다.
		TreeNode* w = y.v;				// y위치의 노드를 w라고 한다.
		v->elt = w->elt;				// v의 elt를 w의 elt로 한다
		removeAboveExternal(z);			// z 노드와 y 노드를 삭제한다.
		return;
	}
}

// i라는 data를 찾고 싶을 때 사용하는 함수
Position BST::find(Position root, int i) {
	// root부터 돌면서 i값의 위치를 찾는다 찾은 k 위치는 p라고 한다.
	Position p = treeSearch(root, i);
	// p가 가리키는 노드를 v라고 한다.
	TreeNode* v = treeSearch(root, i).v;

	// internal이면 그대로 p를 출력하고
	if (is_Internal(p)) {
		return p;
	}
	// external이면 값이 없다는 의미이기 때문에 null을 출력하다.
	else return NULL;
}

// i가 들어가 있거나 들어가야할 위치를 찾는 함수
Position BST::treeSearch(Position p, int i) {
	// p가 가리키는 노드를 v라고 하자
	TreeNode* v = p.v;

	// external이면 찾지 못한 것이므로 그 위치에 i를 삽입할 수 있게 하기위해
	// p를 그대로 return 한다.
	if (is_External(p)) {
		return p;
	}
	// 만일 i의 값이 노드의 원소 elt와 같으면 이미 존재하는 것이니
	// 그 위치를 return 한다.
	if (i == v->elt) {
		return p;
	}
	// 찾고자하는 i가 elt보다 작다면 elt 값이 있는 노드의 왼쪽에 존재하는 것이므로
	// p.left()로 재귀호출한다.
	else if (i < v->elt) {
		return treeSearch(p.left(), i);
	}
	// 찾고자하는 i가 elt보다 크다면 elt 값이 있는 노드의 오른쪽에 존재하는 것이므로
	// p.right()로 재귀호출한다.
	else {
		return treeSearch(p.right(), i);
	}
}

// 삭제할 때 계승할 노드를 찾기 위해 후행자를 찾는 함수
Position BST::inOrderSucc(Position p) {
	// 후행자를 찾으려면 우선 지금 위치에서 오른쪽 자식으로 넘어가야한다.
	Position z = p.right();

	// z노드에서 왼쪽을 따라 쭉 내려가면 된다.
	// z가 이미 External 노드라면 후행자가 z인 것이기 때문에 z를 return 한다.
	if (is_External(z)) {
		return z;
	}

	// z가 internal 노드라면 다시 왼쪽을 따라 계속 내려간 후
	while (is_Internal(z.left())) {
		z = z.left();
	}
	// 다 내려가서 external 노드를 만나게 되면 그 위치의 값이 후행자이므로 계승자가 되기 때문에 return 한다.
	return z;
}


void BST::printTree(Position p, int level) {
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

// cout과 재귀 함수의 순서 차이로 최종 출력 순서가 달라진다.
void BST::printTreeInOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreeInOrder(p.left());
	cout << *p << " ";
	printTreeInOrder(p.right());
}
