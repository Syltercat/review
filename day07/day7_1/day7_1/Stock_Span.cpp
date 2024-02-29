// Span
/*
n�ϼ� ��ŭ�� �Ϸ��� �ֽ� �ü�ǥ�� �־����� ��� Ư������ �ְ����� �۰ų�
���� �ְ��� ���� ��� ���ӵǴ� ���� ��

index	0	1	2	3	4
value	1	3	4	2	1
span	1	2	3	2	5

/////////////////////////////////////////////
for loop�� ���ؼ��� �ذ��� �� �ִ�.

Algorithm Span_for(P)
	Input array P[n]
	Output array S[n], S[i]�� j=i-k+1, ..., i�� ���� P[j] =< P[i]�̰�, k<=i+1�� ���� ū k�̴�.
	for i=0 to n-1 do
		k=1
		done <- false
		repeat
			if P[i-k] =< p[i]
				k = k+1
			else
				done <- true
		until (k>i) or done
		S[i] = k
	return S

=> for���� ����Ͽ� �ذ��� ��� �ð� ���⵵�� O(n^2)�̴�.
   �ܺ� �ݺ��� 0 ~ n-1, ���� �ݺ��� �־��� ���(�������� ����) i�� �ݺ��Ǵµ� i�� n�� �����ϹǷ�
   �뷫 n*n�� �ð��� O(n^2)�� �ð� ���⵵�� �ȴ�.

/////////////////////////////////////////////

�׷��� ������ �̿��ϸ� linear-time�� Ǯ �� �ִ�. O(n)

Algorithm Span_Stack(P)
	Input P[n], empty stack D
	Output S[n], S[i]�� j=i-k+1, ..., i�� ���� P[j] =< P[i]�̰�, k<=i+1�� ���� ū k�̴�.
	for i=0 to n-1 do
		done <- false
		while not(D.isEmpty() or done)do
			if P[D.top()] =< P[i] then
				D.pop()
			else 
				done <- true
		if D.isEmpty()then
			h = -1
		else
			h = D.top()
		S[i] <- i-h
		D.push
	return S

	P�� ��� ���Ҹ� ��ȸ�ϸ鼭 P[D.top()]�� ���Ͽ� 
	P[i]���� ū���� ���� ������ �ε����� �����Ѵ�.
	������ ��ų� P[i]���� ũ�ų� ���� ���� ���� ���Ҹ� ã�� ������ pop

*/

// ������ Ư¡
/*
1) ù���� stock span�� ������ 1
2) �迭���� �ڽ��� �ε������� �ռ� �� �� ���κ��� ũ�鼭 
   ���� ����� index�� �����ϱ� �������� �迭 ���� �� ���� stock span <- �����
*/

#include <iostream>
#include "ArrayStack.h"
#pragma warning(disable:4996)

using namespace std;

int main() {
	ArrayStack<int> mystack;
	int arr[50];	// �׷��� �� �迭 (�Ϻ� ���Ҹ� ������� �迭)
	int arr_size;	// ����ڰ� ������ �׷��� ũ�� -> �� ��
	int result[50];	// stock span ����� ������ �迭

	cout << "day size: ";
	cin >> arr_size;	// ����ڷκ��� �׷��� ũ�⸦ �Է� �޴´�.
	
	cout << "value: ";
	for (int i = 0; i < arr_size; i++) {	// ���ں� ���� �޴´�. (�׷����� ���Ҹ� ����)
		cin >> arr[i];
	}
	
	// �� ó�� ���� �Ǵ��� �ʿ���� stock span = 1 �̴�.
	result[0] = 1;
	// �׷����� �� ó�� ���� �ڽ��� �ִ밪�̱� ������ ó�� index�� 0�� push
	mystack.push(0);

	for (int i = 1; i < arr_size; i++) {
		// ������ ������� ���� ��� �׷����� ���鼭 ������ top ���ҿ� ������ ��
		// �׷����� ���� �� �۴ٸ� top�� ���� pop���� ������.
		// �� �� ����� top���� �ٽ� ���ؾ��ϱ� ������ while�� ������ �������� ���� ������ �ݺ��Ѵ�.
		while (!mystack.empty() && arr[mystack.top()] <= arr[i]) {
			mystack.pop();
		}

		// �迭���� ���κ��� �ռ� �� �� �ڽŰ� ���ų� ũ�� ���� ���� stock span�̶�� �ϴ� ���� �̿��Ѵ�.
		// ���� while�� ������ arr[i]����ū ���� top�� �Ǳ� ������ ���� ������ �Ʒ� �ڵ�� ���� �����ϴ�.
		if (!mystack.empty()) {
			result[i] = i - mystack.top();
		}
		// ���� ���� ���� �� �� ���� ū ���̱� ������ ���� index�� +1�� ���� ����
		else {
			result[i] = i + 1;
		}
		// ���� ���� stock span�� ����ϱ� ���� ���� index�� push �Ѵ�.
		mystack.push(i);
	}

	// ����������  result�� ����Ѵ�. (0�� = ù ��° ��)
	for (int i = 0; i < arr_size; i++) {
		cout << i << "��, " << "value: " << arr[i] << ", span: " << result[i] << endl;
	}
	
}