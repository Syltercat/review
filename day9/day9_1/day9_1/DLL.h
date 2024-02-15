#pragma once
#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;

typedef string Elem;	// element type ������
class DNode {
	friend class DLL;
private:
	Elem elem;		// element
	DNode* prev;	// ���� node
	DNode* next;	// ���� node
};

class DLL {
public:
	DLL();							// ������
	~DLL();							// �Ҹ���
	bool empty()const;				// Double Linked List�� ������� Ȯ��
	const Elem& front() const;		// �� �� ����� elemnet
	const Elem& back() const;		// �� �� ����� element
	void addFront(const Elem&);		// �� �տ� ��� �߰�
	void addBack(const Elem&);		// �� �ڿ� ��� �߰�
	void removeFront();				// �� ���� ��� ����
	void removeBack();				// �� ���� ��� ����

// DLL Ư���� ����� �������� ���Ұ��� ������� �ʴ�.
private:
	DNode* header;					// list �� ��
	DNode* trailer;					// list �� ��
protected:
	void add(DNode*, const Elem&);	// v�տ� ���ο� ��� ����
	void remove(DNode*);			// ��� ����
};

#endif // !DLL_H
