#include <iostream>
#include "ArrayVector.h"
using namespace std;

ArrayVector::ArrayVector(): capacity(0),n(0), A(NULL) {	 // ������, �� array vector ����

}

int ArrayVector::size() const {
	return n;
}

bool ArrayVector::empty() const {
	return size() == 0;
}

// Array Vector index�� �ٷ� �� �ְ� ��
Elem& ArrayVector::operator[](int i) {
	return A[i];
}

// Array Vector�� element�� �����ִ� �Լ�
Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
	if (i < 0 || i >= n) {
		throw IndexOutOfBounds("illegal index in fuction at().");
	}
	return A[i];
}

// ArrayVector�� ���� �ϳ� ����
void ArrayVector::erase(int i) {
	// ������ ������ �� index�� ������ �ϳ��� ���
	for (int j = i + 1; j < n; j++) {
		A[j - 1] = A[j];
	}
	// ũ�⸦ ���ҽ�Ų��.
	n--;
}

// insert�ÿ� �迭�� ������ �����ϸ� �� �Լ��� �Ѿ���� �ȴ�.
void ArrayVector::reserve(int N) {	// N���� ������ �����Ѵٰ� �ϸ�
	// �Ҵ��� ũ���� N���� ���� arrayvector�� ũ�Ⱑ ũ�ų� ���ٸ� �뷮�� �ø� �ʿ���� return
	if (capacity >= N) {
		return;
	}
	// �Ҵ��� N�� ������ capacity���� ũ�ٸ�
	Elem* B = new Elem[N];	// N ũ���� ���ο� ���͸� ���� ��
	// ���� arrayvector�� �����Ѵ�.
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
	}
	// ���縦 �������� ���� arrayvector A�� �����Ѵ�.
	if (A != NULL) {
		delete[] A;
	}
	// ���θ��� B�� arrayvector class�� A�� ������ְ�
	A = B;
	// �뷮�� N���� �ٲ��ش�.
	capacity = N;
}

void ArrayVector::insert(int i, const Elem& e) {
	// ���Ҹ� �߰��ϰ� ������ ���� ArrayVector�� �뷮�� ������ ���
	if (n >= capacity) {
		// reserve �Լ��� �뷮�� 2��� �ø� �� �߰�
		reserve(max(1, 2 * capacity));
	}
	// ������ �κ�(i)�� index���� �ڷ� ��ĭ�� �δ�.
	for (int j = n - 1; j >= i; j--) {
		A[j + 1] = A[j];
	}
	// ���Ҹ� �����Ѵ�.
	A[i] = e;
	// ũ�⸦ ������Ų��.
	n++;
}
