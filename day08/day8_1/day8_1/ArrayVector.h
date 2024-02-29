#ifndef ARRAYVECTOR_H
#define ARRAYVECTOR_H

#include <iostream>
using namespace std;

class IndexOutOfBounds {
public:
	IndexOutOfBounds(const string& err) { }
};

typedef int Elem;	// �ڷ��� ������ (�� �ڵ忡���� Array Vector�� �����ϱ� ���ϰ� �ϱ� ���� ���)
class ArrayVector {
public:
	ArrayVector();							// ������
	int size() const;						// element ��
	bool empty()const;						// Array vector�� ������� Ȯ��
	Elem& operator[](int);					// []������ �����ε� (vector index�� ���)
	Elem& at(int) throw(IndexOutOfBounds);	// Array Vector�� ���Ҹ� �����ִ� �Լ�
	void erase(int);						// ����
	void insert(int, const Elem&);			// ����
	void reserve(int);						// ũ�Ⱑ ���� A Array vector�� B�迭�� ������ �� A�� ����� ����
											// Array vector�� ������ �����ϸ鼭 ũ�⸦ �ø��� ���� �� ���
private:
	int capacity;	// �迭 ũ��
	int n;			// element ����
	Elem* A;		// element �����ϴ� Array
};

#endif // !ARRAYVECTOR_H
