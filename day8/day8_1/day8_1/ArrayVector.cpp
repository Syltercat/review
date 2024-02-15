#include <iostream>
#include "ArrayVector.h"
using namespace std;

ArrayVector::ArrayVector(): capacity(0),n(0), A(NULL) {	 // 생성자, 빈 array vector 생성

}

int ArrayVector::size() const {
	return n;
}

bool ArrayVector::empty() const {
	return size() == 0;
}

// Array Vector index를 다룰 수 있게 함
Elem& ArrayVector::operator[](int i) {
	return A[i];
}

// Array Vector의 element를 보여주는 함수
Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
	if (i < 0 || i >= n) {
		throw IndexOutOfBounds("illegal index in fuction at().");
	}
	return A[i];
}

// ArrayVector의 원소 하나 삭제
void ArrayVector::erase(int i) {
	// 삭제할 원소의 뒤 index를 앞으로 하나씩 당김
	for (int j = i + 1; j < n; j++) {
		A[j - 1] = A[j];
	}
	// 크기를 감소시킨다.
	n--;
}

// insert시에 배열의 공간이 부족하면 이 함수로 넘어오게 된다.
void ArrayVector::reserve(int N) {	// N개의 공간을 예약한다고 하면
	// 할당할 크기인 N보다 기존 arrayvector의 크기가 크거나 같다면 용량을 늘릴 필요없이 return
	if (capacity >= N) {
		return;
	}
	// 할당할 N의 공간이 capacity보다 크다면
	Elem* B = new Elem[N];	// N 크기의 새로운 벡터를 만든 후
	// 기존 arrayvector를 복사한다.
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
	}
	// 복사를 마쳤으니 기존 arrayvector A를 삭제한다.
	if (A != NULL) {
		delete[] A;
	}
	// 새로만든 B를 arrayvector class의 A로 만들어주고
	A = B;
	// 용량을 N으로 바꿔준다.
	capacity = N;
}

void ArrayVector::insert(int i, const Elem& e) {
	// 원소를 추가하고 싶은데 기존 ArrayVector의 용량이 부족할 경우
	if (n >= capacity) {
		// reserve 함수로 용량을 2배로 늘린 후 추가
		reserve(max(1, 2 * capacity));
	}
	// 삽입할 부분(i)의 index부터 뒤로 한칸식 민다.
	for (int j = n - 1; j >= i; j--) {
		A[j + 1] = A[j];
	}
	// 원소를 삽입한다.
	A[i] = e;
	// 크기를 증가시킨다.
	n++;
}
