// Shell sort
/*
k���� sublist�� �����Ͽ� ���� �����Ѵ�. (���� �������� ����)
�ָ� ������ ���ҳ��� ��ȯ�� �����ϰ� �Ͽ� ���� �ӵ��� ����Ų��.

1. �����͸� k��ŭ �뼺�뼺 ������ ���� �����Ѵ�.
2. �����͸� �ٽ� �߰� ������ ���� �����Ѵ�.
3. �̸� �ݺ��ϸ� ���ĵȴ�.

���� = k�� �� ���� �κ� ����Ʈ�� ����
*/

#include <iostream>
#include <chrono>
#define N 1000

using namespace std;

void checkSort(int a[], int size);
void shellSort1(int a[], int size);
void shellSort2(int a[], int size);
void shellSort3(int a[], int size);

int main() {
	int arr[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}
	int size = sizeof(arr) / sizeof(int);
	checkSort(arr, size);

	// ���ݿ� ���� ���� �ð��� �ٸ� ���� Ȯ���ϱ� ���� chrono�� ����Ͽ���.
    auto start = chrono::high_resolution_clock::now();
	shellSort1(arr,size);
	checkSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Runtime: " << duration.count() << " seconds." << endl << endl;


	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}
	checkSort(arr, size);

	start = chrono::high_resolution_clock::now();
	shellSort2(arr, size);
	checkSort(arr, size);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Runtime: " << duration.count() << " seconds." << endl << endl;


	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}
	checkSort(arr, size);

	start = chrono::high_resolution_clock::now();
	shellSort3(arr, size);
	checkSort(arr, size);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Runtime: " << duration.count() << " seconds." << endl << endl;
    return 0;
}

// ���ĵǾ����� Ȯ�ο�
void checkSort(int a[], int n) {
	int i, sorted;
	sorted = 1;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			sorted = 0;
		}
		if (!sorted) {
			break;
		}
	}
	if (sorted) {
		printf("complete.\n");
	}
	else {
		printf("error\n");
	}
}

// ������ �ٸ����� shellsort
void shellSort1(int a[], int n) {
	int k(0), v(0);
	for (int h = n / 2; h > 0; h /= 2) {
		for (int i = 0; i < h; i++) {
			for (int j = i + h; j < n; j += h) {
				v = a[j];
				k = j;
				while (k > h - 1 && a[k - h] > v) {
					a[k] = a[k - h];
					k -= h;
				}
			}
			a[k] = v;
		}
	}
}

void shellSort2(int a[], int n) {
	int i, j, h, v;
	for (h = 1; h < n; h = 3 * h + 1);
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			v = a[i];
			j = i;
			while (j >= h && a[j - h] > v) {
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}
}

void shellSort3(int a[], int n) {
	int i, j, h, v;
	for (h = 1; h < n; h = 11 * h + 1);
	for (; h > 0; h /= 11) {
		for (i = h; i < n; i++) {
			v = a[i];
			j = i;
			while (j >= h && a[j - h] > v) {
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}
}