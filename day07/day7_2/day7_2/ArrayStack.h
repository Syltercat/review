#include <iostream>
using namespace std;

class StackEmpty {
public:
	StackEmpty(const string& err) { }
};

class StackFull {
public:
	StackFull(const string& err) { }
};

template <typename T>
class ArrayStack {
	enum { DEF_CAPACITY = 100 };	// 기본 stack 용량
public:
	ArrayStack(int cap = DEF_CAPACITY);		// 스택 생성자
	int size() const;						// 스택 크기
	bool empty() const;						// 스택이 비었는지 판단
	const T& top() const throw(StackEmpty);	// 스택의 top 원소를 가져오는 함수, stack에 아무것도 없으면 StackEmpty로 에러 처리
	void push(const T&) throw(StackFull);	// 스택의 원소를 push하는 함수, 스택이 꽉 차있으면 StackFull로 에러 처리
	void pop() throw(StackEmpty);			// 스택의 원소를 pop하는 함수, 스택이 비어있으면 StackEmpty로 에러 처리 

private:
	T* S;			// 스택의 주소 -> S[i] 같은 형식으로 스택의 원소를 불러올 수 있게 함.
	int capacity;	// 스택 용량 
	int t;			// top 원소의 index
};

template <typename T> ArrayStack<T>::ArrayStack(int cap)
	: S(new T[cap]), capacity(cap), t(-1) {

}

template <typename T> int ArrayStack<T>::size() const {
	return (t + 1);
}

template <typename T> bool ArrayStack<T>::empty()const {
	return (t < 0);
}

// top 원소 확인
template <typename T> const T& ArrayStack<T>::top() const {
	if (empty()) {
		throw StackEmpty("Top of empty Stack\n");
	}
	return S[t];
}

// push 함수
template <typename T> void::ArrayStack<T>::push(const T& e) {
	if (size() == capacity) {
		throw StackFull("Push to full Stack\n");
	}
	else {
		S[++t] = e;
	}
}


template <typename T> void ArrayStack<T>::pop() {
	if (empty()) {
		throw StackEmpty("Pop to empty Stack\n");
	}
	--t;
}