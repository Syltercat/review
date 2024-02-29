#include <iostream>
#include "BinaryTree.h"
using namespace std;

TreeNode::TreeNode() :elt(), parent(NULL), left(NULL), right(NULL) {

}

TreeNode::TreeNode(Elem e) :elt(e), parent(NULL), left(NULL), right(NULL) {

}

Position::Position(TreeNode* _v = NULL) :v(_v) {

}

// 노드가 가지는 element를 반환
Elem& Position::operator*() {
	return v->elt;
}

// left child를 가져온다.
Position Position::left()const {
	return Position(v->left);
}

// right child를 가져온다.
Position Position::right()const {
	return Position(v->right);
}

// parent를 가져온다.
Position Position::parent()const {
	return Position(v->parent);
}

// 노드 위치가 비었는지 확인한다.
bool Position::isNULL() {
	return v == NULL;
}

// 노드 위치가 root인지 확인한다.
bool Position::isRoot()const {
	return v->parent == NULL;
}

// 노드 위치가 external인지 확인한다.
bool Position::isExternal()const {
	// leaf node가 없으면 external이므로 왼쪽과 오른쪽 child 노드가 둘다 없는지 확인
	return v->left == NULL && v->right == NULL;
}

BinaryTree::BinaryTree() :_root(NULL), n(0) {

}

// 노드의 수 반환
int BinaryTree::size()const {
	return n;
}

// tree가 비었는지 확인한다.
bool BinaryTree::empty()const {
	return size() == 0;
}

// root 값을 반환
Position BinaryTree::root()const {
	return Position(_root);
}

// 모든 노드의 list
PositionList BinaryTree::positions()const {
	PositionList pl;
	// 전위 순회
	preorder(_root, pl);
	// 순회한 모든 노드들의 list 반환
	return PositionList(pl);
}

// root에 노드를 추가한다.
void BinaryTree::addRoot() {
	_root = new TreeNode;
	n = 1;
}

// external 노드에 child를 달아준다. (tree 확장)
void BinaryTree::expandExternal(const Position& p, int i) {
	TreeNode* v = p.v;			// p 위치의 노드 v
	v->elt = i;					// element =  i
	v->left = new TreeNode;		// left, right에 NULL child 생성
	v->right = new TreeNode;
	v->left->parent = v;		// 생성한 child의 parent node를 v로 설정
	v->right->parent = v;
	n += 2;						// left, right child가 생겼으니 크기 2만큼 증가
}

Position BinaryTree::removeAboveExternal(const Position& p) {
	TreeNode* w = p.v;				// p위치 노드 = w
	TreeNode* v = w->parent;		// w의 부모 노드 = v
	TreeNode* sib = (w == v->left ? v->right : v->left);	// v의 형제 노드 = sib

	// 삭제하고 싶은 노드가 root라면
	if (v == _root) {
		// 삭제하고 싶은 노드의 형제 노드를 root로 하고
		_root = sib;
		// 형제노드의 부모를 null로 함
		sib->parent = NULL;
	}
	// 아니라면
	else {
		// p의 조부모 노드를 g
		TreeNode* g = v->parent;
		// 삭제하고 싶은 노드의 부모 노드가 g의 left child라면
		if (v == g->left) {
			// 삭제하고 싶은 노드(w)의 부모 노드를 w의 형제노드로 바꾼다.
			g->left = sib;
		}
		// right child라면
		else {
			// 조부모 노드의 right child를 형제노드로 바꾼다.
			g->right = sib;
		}
		// 그 후 형제 노드의 부모노드가 기존의 조부모 노드가 된다.
		sib->parent = g;
	}
	// 삭제하고 싶은 노드와 그 부모 노드를 삭제한다.
	delete w;
	delete v;
	// 크기를 2만큼 줄인다.
	n -= 2;
	return Position(sib);
}

// cout과 재귀 함수의 순서 차이로 최종 출력 순서가 달라진다.
// 전위 순회
void BinaryTree::printTreeInOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	printTreeInOrder(p.left());
	cout << *p << " ";
	printTreeInOrder(p.right());
}

// 중위 순회
void BinaryTree::printTreePreOrder(Position p) {
	if (p.isNULL()) {
		return;
	}
	cout << *p << " ";
	printTreePreOrder(p.left());
	printTreePreOrder(p.right());
}

// 후위 순회
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