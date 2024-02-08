#pragma once
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
using namespace std;

// Stack�� �� á�� ���� ����� ��� ���� ó���� �ϱ� ���� class
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
	enum { DEF_CAPACITY = 100};	// �⺻ stack �뷮
public:
	ArrayStack(int cap = DEF_CAPACITY);		// ���� ������
	int size() const;						// ���� ũ��
	bool empty() const;						// ������ ������� �Ǵ�
	const T& top() const throw(StackEmpty);	// ������ top ���Ҹ� �������� �Լ�, stack�� �ƹ��͵� ������ StackEmpty�� ���� ó��
	void push(const T&) throw(StackFull);	// ������ ���Ҹ� push�ϴ� �Լ�, ������ �� �������� StackFull�� ���� ó��
	void pop() throw(StackEmpty);			// ������ ���Ҹ� pop�ϴ� �Լ�, ������ ��������� StackEmpty�� ���� ó�� 

private:
	T* S;			// ������ �ּ� -> S[i] ���� �������� ������ ���Ҹ� �ҷ��� �� �ְ� ��.
	int capacity	// ���� �뷮 
	int t;			// top ������ index
};

#endif // !ARRAYSTACK_H
