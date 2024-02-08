#include <iostream>
#include "ArrayStack.h"

using namespace std;

StackEmpty::StackEmpty(const string& err) {
}

StackFull::StackFull(const string& err) {

}

// template으로 함수를 선언할 경우 형태를 주의해서 작성해야 함.
// 배열로 스택을 만들기 때문에 S를 T타입의 크기 cap 배열로 초기화
// top의 index의 경우 -1로 하는 것이 헷갈리지 않음 (값이 존재하면 index 0 부터인데 초기엔 값이 없으므로 0보다 작은 -1)
template <typename T> ArrayStack<T>::ArrayStack(int cap)
	: S(new T[cap]), capacity(cap), t(-1) {

}

// index + 1 = size 이기 때문
template <typename T> int ArrayStack<T>::size() const {
	return (t + 1);
}

// t가 0보다 작으면 비어있으므로 true, 0보다 크면 원소가 들어온 것이므로 false
template <typename T> bool ArrayStack<T>::empty()const {
	return (t < 0);
}

// top 원소 확인
template <typename T> const T& ArrayStack<T>::top() const {
	// stack이 비어있는 경우
	if (empty()) {
		// 빈 스택의 예외처리로 message 던짐
		throw StackEmpty("Top of empty Stack\n")
	}
	// 비어있지 않다면 반환
	return S[t];
}

// push 함수
template <typename T> void::ArrayStack<T>::push(const T& e) {
	// 스택이 가득 찼다면
	if (size() == capacity) {
		// 스택이 가득 찼을 경우의 예외처리로 message 던짐
		throw StackFull("Push to full Stack\n");
	}
	// 스택에 공간이 남아있다면
	else {
		// *주의
		// top을 한 번 증가시킨 후 그 위치에 e 원소 삽입
		// 만일 후위 연산자를 사용하여 S[t++]로 작성할 경우 
		// e가 증가되지 않은 이전 top 값에 삽입되어 이전 top위치의 값이 소실된다.
		// 그 후 top의 위치 t가 증가하여 t는 top이 아닌 그 위의 쓰레기 값의 위치를 가르키게 된다.
		S[++t] = e;
	}
}

// pop 함수
template <typename T> void ArrayStack<T>::pop() {
	// 스택이 비었을 경우
	if (empty()) {
		// 뺄 원소가 없으므로 예외처리
		throw StackEmpty("Pop to empty Stack\n");
	}

	// 이 부분에서는 후위 연산자도 사용 가능. 이후에 t를 사용하는 연산이 없기 때문이다.
	--t;
}