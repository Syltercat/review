// Shell sort
/*
k개의 sublist로 분할하여 삽입 정렬한다. (기존 삽입정렬 보완)
멀리 떨어진 원소끼리 교환이 가능하게 하여 정렬 속도를 향상시킨다.

1. 데이터를 k만큼 듬성듬성 나누어 삽입 정렬한다.
2. 데이터를 다시 잘게 나누어 삽입 정렬한다.
3. 이를 반복하면 정렬된다.

간격 = k로 할 때의 부분 리스트를 정렬
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

	// 간격에 따라 수행 시간이 다른 것을 확인하기 위해 chrono를 사용하였다.
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

// 정렬되었는지 확인용
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

// 간격을 다르게한 shellsort
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