#include <iostream>
#include "ArrayStack.h"

using namespace std;

StackEmpty::StackEmpty(const string& err) {
}

StackFull::StackFull(const string& err) {

}

// template���� �Լ��� ������ ��� ���¸� �����ؼ� �ۼ��ؾ� ��.
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
		throw StackEmpty("Top of empty Stack\n")
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