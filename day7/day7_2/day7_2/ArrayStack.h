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
	enum { DEF_CAPACITY = 100 };	// �⺻ stack �뷮
public:
	ArrayStack(int cap = DEF_CAPACITY);		// ���� ������
	int size() const;						// ���� ũ��
	bool empty() const;						// ������ ������� �Ǵ�
	const T& top() const throw(StackEmpty);	// ������ top ���Ҹ� �������� �Լ�, stack�� �ƹ��͵� ������ StackEmpty�� ���� ó��
	void push(const T&) throw(StackFull);	// ������ ���Ҹ� push�ϴ� �Լ�, ������ �� �������� StackFull�� ���� ó��
	void pop() throw(StackEmpty);			// ������ ���Ҹ� pop�ϴ� �Լ�, ������ ��������� StackEmpty�� ���� ó�� 

private:
	T* S;			// ������ �ּ� -> S[i] ���� �������� ������ ���Ҹ� �ҷ��� �� �ְ� ��.
	int capacity;	// ���� �뷮 
	int t;			// top ������ index
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

// top ���� Ȯ��
template <typename T> const T& ArrayStack<T>::top() const {
	if (empty()) {
		throw StackEmpty("Top of empty Stack\n");
	}
	return S[t];
}

// push �Լ�
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