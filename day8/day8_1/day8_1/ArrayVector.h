#ifndef ARRAYVECTOR_H
#define ARRAYVECTOR_H

#include <iostream>
using namespace std;

class IndexOutOfBounds {
public:
	IndexOutOfBounds(const string& err) { }
};

typedef int Elem;	// 자료형 재정의 (이 코드에서는 Array Vector를 구분하기 편하게 하기 위해 사용)
class ArrayVector {
public:
	ArrayVector();							// 생성자
	int size() const;						// element 수
	bool empty()const;						// Array vector가 비었는지 확인
	Elem& operator[](int);					// []연산자 오버로딩 (vector index에 사용)
	Elem& at(int) throw(IndexOutOfBounds);	// Array Vector의 원소를 보여주는 함수
	void erase(int);						// 삭제
	void insert(int, const Elem&);			// 삽입
	void reserve(int);						// 크기가 작은 A Array vector를 B배열에 복사한 후 A로 만드는 역할
											// Array vector의 내용은 복사하면서 크기를 늘리고 싶을 때 사용
private:
	int capacity;	// 배열 크기
	int n;			// element 개수
	Elem* A;		// element 저장하는 Array
};

#endif // !ARRAYVECTOR_H
