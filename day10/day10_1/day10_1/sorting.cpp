// Sorting
/*
Sorting Algorithem
	1) complexity
	2) in-place
		- 원소들의 개수에 비해서 충분히 무시할 만한 저장 공간만을 사용하는가에 대한 것
	3) stable
		- 중복 키를 순서대로 정렬하는가에 대한 것
		- 정렬 했을 때 중복 된 값들의 순서가 변하지 않으면 stable 정렬이라 한다.

//////////////////////////////////////////////////////////
algorithm		 Time		 Stable		 In-plase
//////////////////////////////////////////////////////////
bubble			O(n^2)			O			O
insertion		O(n^2)			O			O
selection		O(n^2)			X			O
merge		   O(nlogn)			O			X
quick		   O(nlogn)		 X or O		  O or X
//////////////////////////////////////////////////////////

*bubble sort (거품 정렬)
- array의 맨 앞에서부터 인접한 두 원소를 비교하면서 큰 값부터 배열의 끝에 저장하는 정렬

*insertion sort (삽입 정렬)
- 첫번째 원소를 정렬된 상태로 본 후 다음 원소를 정렬된 앞 배열에 insert하는 방식으로 정렬

*selection sort (선택 정렬)
- 첫번째 원소를 최솟값이라고 가정하고 배열을 쭉 스캔하면서 현재의 최솟값과 비교하여 교환하는 방식으로 정렬

*merge sort (합병 정렬)
- 작은 정렬 문제로 쪼개어 정렬한 후 다시 합치는 정렬 방식

*quick sort (퀵 정렬)
- 임의의 값을 기준으로 그보다 큰 수는 오른쪽 작은수는 왼쪽으로 두어 정렬하는 방식
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
	// 새로운 배열 공간 생성
	int arr2[100] = { 0 };
	// 배열 끝의 인덱스가 100이 아닌 99임에 유의
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
	// 일단 반을 나눔
	int i = left, j = mid + 1, k = left;

	//mid를 기준으로 i가 왼쪽에 있고 j가 오른쪽에 있을 때
	while (i <= mid && j <= right) {
		// i와 j에 들어있는 값 중 작은 값을 새로 만든 배열 공간에 넣어준다.
		if (arr[i] <= arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}

	// 더이상 비교할 i나 j가 없다면 남아있는 값을 전부 이어서 넣어준다.
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

	// 임시 배열에 정렬된 값들을 원래의 배열로 다시 복사한다.
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
		int pivot = arr[(left + right) / 2]; // 피벗 값 저장
		int l = left, r = right;

		while (l <= r) {
			while (arr[l] < pivot) l++; // 피벗보다 큰 값을 찾음
			while (arr[r] > pivot) r--; // 피벗보다 작은 값을 찾음
			if (l <= r) {
				Swap(arr, l, r); // l과 r 위치의 값을 교환
				l++;
				r--;
			}
		}
		// 분할된 부분 배열에 대해 재귀적으로 정렬 수행
		quick(arr, left, r);
		quick(arr, l, right);
	}
}
