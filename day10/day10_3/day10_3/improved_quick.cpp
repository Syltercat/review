// improved quick
/*
���� ������ ����Ű�� ���ؼ� ������ �õ��غ� �� �ִ�.
1. ������ ����Ͽ� ��� ����
2. ���� �κ� ������ ��� ���� ���� ���
3. �߰��� ���� (pivot�� ���� �迭�� �߰� ������ �Ѵ�.)
*/

#include <iostream>
using namespace std;

#define N 50
int stack[N];
int top = 0;

// ��� ������ ���� stack 
void init_stack();
void push(int);
int pop();
int stackEmpty();

// ���� �������� ����� ���� ����
void insertion(int*, int);

// pivot�� �߰����̸鼭 ��͸� ������ quick sort �Ԥ�
void quick(int*, int);

int main() {
	int array[] = { 24, 17, 85, 13, 22, 16, 3, 5, 99, -4, 21 }; // ������ �迭
	int size = sizeof(array) / sizeof(array[0]);

	quick(array, size); // quick �Լ��� ����Ͽ� �迭 ����

	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

void init_stack() {
	top = 0;
}

void push(int i) {
	if (top >= N) {
		cout << "full.\n";
	}
	else {
		stack[top++] = i;
	}
}

int pop() {
	if (top == 0) {
		return 0;
	}
	else {
		return stack[--top];
	}
}

int stackEmpty() {
	if (top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void insertion(int a[], int size) {
	for (int i = 1; i < size; i++) {
		int t = a[i];
		int j = i;
		while(a[j - 1] > t && j > 0){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}

void quick(int a[], int size) {
	init_stack();
	int l(0), r(size-1), p, t, i, j;
	push(r);
	push(l);
	while (!stackEmpty()) {
		l = pop();
		r = pop();

		// �������� ����� ���� ���� ����
		if (r - l + 1 > 200) {
			t = (r + 1) >> 1; //shift �������� ������ 2�� ����
			if (a[l] > a[t]) {
				p = a[l];
				a[l] = a[t];
				a[t] = p;
			}
			if (a[l] > a[r]) {
				p = a[l];
				a[l] = a[r];
				a[r] = p;
			}
			if (a[t] > a[r]) {
				p = a[t];
				a[t] = a[r];
				a[r] = p;
			}
			p = a[t];
			a[t] = a[r - 1];
			a[r - 1] = p;

			i = l - 1;
			j = r;
			while (1) {
				while (a[++i] < p);
				while (a[--j] > p);
				if (i >= j) {
					break;
				}
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}

			t = a[i];
			a[i] = a[r];
			a[r] = t;

			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else {
			insertion(a + l, r - l + 1);
		}
	}
}