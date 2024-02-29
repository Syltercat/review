#include <iostream>
#include "DLL.h"
using namespace std;

// 생성자, 초기화, 빈 DLL이기 때문에 header와 trailer 밖에 없다.
DLL::DLL(): header(new DNode), trailer(new DNode) {
	header->next = trailer;
	trailer->prev = header;
}

// 소멸자, DLL에 값이 남아있으면 전부 지워주고 빈 list가 됐다면 header과 trailer도 삭제해준다.
DLL::~DLL() {
	while (!empty()) {
		removeFront();
	}
	// new로 할당했으므로 delete로 반환한다.
	delete header;
	delete trailer;
}

// list가 비었는지 확인
bool DLL::empty() const {
	return header->next == trailer;
}

// 맨 앞 노드의 element 확인
const Elem& DLL::front() const {
	return header->next->elem;
}

// 맨 뒤 노드의 element 확인
const Elem& DLL::back() const {
	return trailer->prev->elem;
}

// 맨 앞에 노드 삽입
void DLL::addFront(const Elem& e) {
	add(header->next, e);
}

// 맨 뒤에 노드 추가
void DLL::addBack(const Elem& e) {
	add(trailer, e);
}

// 맨 앞에 노드 삭제
void DLL::removeFront() {
	remove(header->next);
}

// 맨 뒤의 노드 삭제
void DLL::removeBack() {
	remove(trailer->prev);
}

// v 노드 앞에 e라는 element를 가진 노드 추가
void DLL::add(DNode* v, const Elem& e) {
	DNode* u = new DNode;
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	u->prev->next = v->prev = u;
}

 // v 노드 삭제
void DLL::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}