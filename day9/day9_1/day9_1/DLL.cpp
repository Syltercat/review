#include <iostream>
#include "DLL.h"
using namespace std;

// ������, �ʱ�ȭ, �� DLL�̱� ������ header�� trailer �ۿ� ����.
DLL::DLL(): header(new DNode), trailer(new DNode) {
	header->next = trailer;
	trailer->prev = header;
}

// �Ҹ���, DLL�� ���� ���������� ���� �����ְ� �� list�� �ƴٸ� header�� trailer�� �������ش�.
DLL::~DLL() {
	while (!empty()) {
		removeFront();
	}
	// new�� �Ҵ������Ƿ� delete�� ��ȯ�Ѵ�.
	delete header;
	delete trailer;
}

// list�� ������� Ȯ��
bool DLL::empty() const {
	return header->next == trailer;
}

// �� �� ����� element Ȯ��
const Elem& DLL::front() const {
	return header->next->elem;
}

// �� �� ����� element Ȯ��
const Elem& DLL::back() const {
	return trailer->prev->elem;
}

// �� �տ� ��� ����
void DLL::addFront(const Elem& e) {
	add(header->next, e);
}

// �� �ڿ� ��� �߰�
void DLL::addBack(const Elem& e) {
	add(trailer, e);
}

// �� �տ� ��� ����
void DLL::removeFront() {
	remove(header->next);
}

// �� ���� ��� ����
void DLL::removeBack() {
	remove(trailer->prev);
}

// v ��� �տ� e��� element�� ���� ��� �߰�
void DLL::add(DNode* v, const Elem& e) {
	DNode* u = new DNode;
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	u->prev->next = v->prev = u;
}

 // v ��� ����
void DLL::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}