#include <iostream>
using namespace std;

// Stack�� �� á�� ���� ����� ��� ���� ó���� �ϱ� ���� class
class StackEmpty {
public:
	StackEmpty(const string& err) { }
};

class StackFull {
public:
	StackFull(const string& err) { }
};

// template���� �Լ��� ������ ��� ���¸� �����ؼ� �ۼ��ؾ� ��.
// �Ϲ������� template�� ����ϸ� ������� �ζ��� �����ϴ� ���� �Ϲ����̴�.

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
	int capacity;	// ���� �뷮 
	int t;			// top ������ index
};

// �迭�� ������ ����� ������ S�� TŸ���� ũ�� cap �迭�� �ʱ�ȭ
// top�� index�� ��� -1�� �ϴ� ���� �򰥸��� ���� (���� �����ϸ� index 0 �����ε� �ʱ⿣ ���� �����Ƿ� 0���� ���� -1)
template <typename T> ArrayStack<T>::ArrayStack(int cap)
	: S(new T[cap]), capacity(cap), t(-1) {

}

// index + 1 = size �̱� ����
template <typename T> int ArrayStack<T>::size() const {
	return (t + 1);
}

// t�� 0���� ������ ��������Ƿ� true, 0���� ũ�� ���Ұ� ���� ���̹Ƿ� false
template <typename T> bool ArrayStack<T>::empty()const {
	return (t < 0);
}

// top ���� Ȯ��
template <typename T> const T& ArrayStack<T>::top() const {
	// stack�� ����ִ� ���
	if (empty()) {
		// �� ������ ����ó���� message ����
		throw StackEmpty("Top of empty Stack\n");
	}
	// ������� �ʴٸ� ��ȯ
	return S[t];
}

// push �Լ�
template <typename T> void::ArrayStack<T>::push(const T& e) {
	// ������ ���� á�ٸ�
	if (size() == capacity) {
		// ������ ���� á�� ����� ����ó���� message ����
		throw StackFull("Push to full Stack\n");
	}
	// ���ÿ� ������ �����ִٸ�
	else {
		// *����
		// top�� �� �� ������Ų �� �� ��ġ�� e ���� ����
		// ���� ���� �����ڸ� ����Ͽ� S[t++]�� �ۼ��� ��� 
		// e�� �������� ���� ���� top ���� ���ԵǾ� ���� top��ġ�� ���� �ҽǵȴ�.
		// �� �� top�� ��ġ t�� �����Ͽ� t�� top�� �ƴ� �� ���� ������ ���� ��ġ�� ����Ű�� �ȴ�.
		S[++t] = e;
	}
}

// pop �Լ�
template <typename T> void ArrayStack<T>::pop() {
	// ������ ����� ���
	if (empty()) {
		// �� ���Ұ� �����Ƿ� ����ó��
		throw StackEmpty("Pop to empty Stack\n");
	}

	// �� �κп����� ���� �����ڵ� ��� ����. ���Ŀ� t�� ����ϴ� ������ ���� �����̴�.
	--t;
}