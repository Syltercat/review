#include <iostream>
#include <iomanip>
#include "Array.h"

using namespace std;

// <멤버 함수>
// 생성자
Array::Array(int arraySize) {
	size = (arraySize > 0 ? arraySize : 10);
	ptr = new int[size];

	// 배열의 index 별 초기화
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

// 복사 생성자
Array::Array(const Array& arrayCopy) {
	size = arrayCopy.size;
	ptr = new int[size];

	// 배열의 index 별 복사
	for (int i = 0; i < size; i++) {
		ptr[i] = arrayCopy.ptr[i];
	}
}

// 소멸자 - 앞에 동적 메모리 할당해 준 ptr 메모리 반환 
Array::~Array() {
	delete[] ptr;
}

int Array::getsize()const {
	return size;
}

// 연산자 오버로딩
// 대입 연산자
const Array& Array::operator=(const Array& right) {
	
	// this pointer는 연산자를 부른 객체인 첫 번째 피연산자가 된다.
	if (&right != this) {

		// 배열의 크기 다를 경우를 상정
		if (size != right.size) {

			// 배열의 크기가 다르면 기존 배열을 삭제하고 새롭게 배열을 만들어 대입
			delete[]ptr;
			size = right.size;
			ptr = new int[size];
		}

		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i];
		}
	}

	// 반환값은 첫 피연산자의 값으로 한다.
	return *this;
}

// 비교 연산자
bool Array::operator==(const Array& right) const {

	// 배열의 크기가 다른지부터 판단
	if (size != right.size) {
		return 0;
	}

	// 배열 값 하나하나 비교
	for (int i = 0; i < size; i++) {
		if (ptr[i] != right.ptr[i]) {
			return 0;
		}
	}
	return 1;
}

bool Array::operator!=(const Array& right) const {
	return !(*this == right);
}

int& Array::operator[](int n) {
	// 배열이 지정한 크기를 넘어서면 error message 출력
	if (n < 0 || n >= size) {
		cerr << "out of range" << endl;
		exit(1);
	}

	return ptr[n];
}

int Array::operator[](int n) const {
	// 배열이 지정한 크기를 넘어서면 error message 출력
	if (n < 0 || n >= size) {
		cerr << "out of range" << endl;
		exit(1);
	}
	
	return ptr[n];
}

// <전역 함수>
// << 연산자
ostream& operator<<(ostream& output, const Array& a) {
	int i;
	for (i = 0; i < a.size; i++) {

		output << setw(5) << a.ptr[i];

		// 그냥 확인하기 편하기 위해 사용
		if ((i + 1) % 5 == 0)
			output << endl;
	}
	if (i %5 != 0)
		output << endl;

	return output;
}

istream& operator>>(istream& input, Array& a) {
	for (int i = 0; i < a.size; i++) {
		input >> a.ptr[i];
	}
	return input;
}

// 배열의 각 원소끼리 더하는 연산자
Array operator+(const Array& a, const Array& b) {
	// 두 배열의 크기가 다르다면 더하지 않음.
	if (a.size != b.size) {
		cout << "Error: different size." << endl;
		return Array(); // 빈 배열 반환
	}
	else {
		Array sum(a.size); // 두 배열을 더한 결과를 저장할 새로운 배열 생성
		cout << sum;
		for (int i = 0; i < a.size; i++) {
			cout << i << endl;
			sum[i] = a[i] + b[i];
			cout << sum[i] << endl;
		}
		return sum;
	}
}