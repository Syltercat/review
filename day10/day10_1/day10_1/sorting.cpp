// Sorting
/*
Sorting Algorithem
	1) complexity
	2) in-place
		- ���ҵ��� ������ ���ؼ� ����� ������ ���� ���� �������� ����ϴ°��� ���� ��
	3) stable
		- �ߺ� Ű�� ������� �����ϴ°��� ���� ��
		- ���� ���� �� �ߺ� �� ������ ������ ������ ������ stable �����̶� �Ѵ�.

//////////////////////////////////////////////////////////
algorithm		 Time		 Stable		 In-plase
//////////////////////////////////////////////////////////
bubble			O(n^2)			O			O
insertion		O(n^2)			O			O
selection		O(n^2)			X			O
merge		   O(nlogn)			O			X
quick		   O(nlogn)		 X or O		  O or X
//////////////////////////////////////////////////////////

*bubble sort (��ǰ ����)
- array�� �� �տ������� ������ �� ���Ҹ� ���ϸ鼭 ū ������ �迭�� ���� �����ϴ� ����

*insertion sort (���� ����)
- ù��° ���Ҹ� ���ĵ� ���·� �� �� ���� ���Ҹ� ���ĵ� �� �迭�� insert�ϴ� ������� ����

*selection sort (���� ����)
- ù��° ���Ҹ� �ּڰ��̶�� �����ϰ� �迭�� �� ��ĵ�ϸ鼭 ������ �ּڰ��� ���Ͽ� ��ȯ�ϴ� ������� ����

*merge sort (�պ� ����)
- ���� ���� ������ �ɰ��� ������ �� �ٽ� ��ġ�� ���� ���

*quick sort (�� ����)
- ������ ���� �������� �׺��� ū ���� ������ �������� �������� �ξ� �����ϴ� ���
*/

#include <iostream>
#include <ctime>
using namespace std;

void create_arr(int*);
void print(int*);
void swap(int*, int, int);
void bubble(int*, int);
void insertion(int*, int);
void selection(int*, int);
void merge(int*, int*, int, int, int);
void merge_sort(int*, int*, int, int);
void quick(int*, int, int);

int main() {
	srand(unsigned(time(NULL)));

	int arr[100];
	create_arr(arr);
	//Bubble sort
	bubble(arr, 100);

	create_arr(arr);
	//Insertion sort
	insertion(arr, 100);

	create_arr(arr);
	//selection sort
	selection(arr, 100);

	create_arr(arr);
	cout << "merge sort\n";
	//merge sort
	// ���ο� �迭 ���� ����
	int arr2[100] = { 0 };
	// �迭 ���� �ε����� 100�� �ƴ� 99�ӿ� ����
	merge_sort(arr, arr2, 0, 99);
	print(arr);
	cout << endl << endl;

	create_arr(arr);
	cout << "quick sort\n";
	//quick sort
	quick(arr, 0, 99);
	print(arr);
	cout << endl << endl;
}

void create_arr(int arr[]) {
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 1000 + 1;
	}
}

void print(int arr[]) {
	for (int i = 0; i < 100; i++) {
		cout << arr[i] << "\t";
	}
}

void Swap(int arr[], int i, int k) {
	int temp = arr[i];
	arr[i] = arr[k];
	arr[k] = temp;
}

void bubble(int arr[], int size) {
	cout << "bubble\n";
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr, j, j+1);
			}
		}
	}
	print(arr);
	cout << endl;
	cout << endl;
}

void insertion(int arr[], int size) {
	cout << "insertion\n";
	int j(0), key(0);
	for (int i = 1; i < size; i++) {
		key = arr[i];
		for (j = i-1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	print(arr);
	cout << endl;
	cout << endl;
}

void selection(int arr[], int size) {
	cout << "selection\n";
	int min = 0;
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (i != min) {
			Swap(arr, i, min);
		}
	}
	print(arr);
	cout << endl;
	cout << endl;
}

void merge(int arr[], int arr2[], int mid, int left, int right) {
	// �ϴ� ���� ����
	int i = left, j = mid + 1, k = left;

	//mid�� �������� i�� ���ʿ� �ְ� j�� �����ʿ� ���� ��
	while (i <= mid && j <= right) {
		// i�� j�� ����ִ� �� �� ���� ���� ���� ���� �迭 ������ �־��ش�.
		if (arr[i] <= arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}

	// ���̻� ���� i�� j�� ���ٸ� �����ִ� ���� ���� �̾ �־��ش�.
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			arr2[k++] = arr[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			arr2[k++] = arr[l];
		}
	}

	// �ӽ� �迭�� ���ĵ� ������ ������ �迭�� �ٽ� �����Ѵ�.
	for (int l = left; l <= right; l++) {
		arr[l] = arr2[l];
	}
}

void merge_sort(int arr[], int arr2[], int left, int right) {
	int mid(0);
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(arr, arr2, left, mid);
		merge_sort(arr, arr2, mid + 1, right);
		merge(arr, arr2, mid, left, right);
	}
}

void quick(int arr[], int left, int right) {
	if (left < right) {
		int pivot = arr[(left + right) / 2]; // �ǹ� �� ����
		int l = left, r = right;

		while (l <= r) {
			while (arr[l] < pivot) l++; // �ǹ����� ū ���� ã��
			while (arr[r] > pivot) r--; // �ǹ����� ���� ���� ã��
			if (l <= r) {
				Swap(arr, l, r); // l�� r ��ġ�� ���� ��ȯ
				l++;
				r--;
			}
		}
		// ���ҵ� �κ� �迭�� ���� ��������� ���� ����
		quick(arr, left, r);
		quick(arr, l, right);
	}
}
