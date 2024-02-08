#pragma once
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
using namespace std;

// Stack이 다 찼을 경우와 비었을 경우 예외 처리를 하기 위한 class
class StackEmpty {
public:
	StackEmpty(const string&);
};

class StackFull {
public:
	StackFull(const string&);
};

template <typename T>
class ArrayStack {
	enum { DEF_CAPACITY = 100};	// 기본 stack 용량
public:
	ArrayStack(int cap = DEF_CAPACITY);		// 스택 생성자
	int size() const;						// 스택 크기
	bool empty() const;						// 스택이 비었는지 판단
	const T& top() const throw(StackEmpty);	// 스택의 top 원소를 가져오는 함수, stack에 아무것도 없으면 StackEmpty로 에러 처리
	void push(const T&) throw(StackFull);	// 스택의 원소를 push하는 함수, 스택이 꽉 차있으면 StackFull로 에러 처리
	void pop() throw(StackEmpty);			// 스택의 원소를 pop하는 함수, 스택이 비어있으면 StackEmpty로 에러 처리 

private:
	T* S;			// 스택의 주소 -> S[i] 같은 형식으로 스택의 원소를 불러올 수 있게 함.
	int capacity	// 스택 용량 
	int t;			// top 원소의 index
};

#endif // !ARRAYSTACK_H
