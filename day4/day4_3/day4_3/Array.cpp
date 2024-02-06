#include <iostream>
#include <iomanip>
#include "Array.h"

using namespace std;

// <��� �Լ�>
// ������
Array::Array(int arraySize) {
	size = (arraySize > 0 ? arraySize : 10);
	ptr = new int[size];

	// �迭�� index �� �ʱ�ȭ
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

// ���� ������
Array::Array(const Array& arrayCopy) {
	size = arrayCopy.size;
	ptr = new int[size];

	// �迭�� index �� ����
	for (int i = 0; i < size; i++) {
		ptr[i] = arrayCopy.ptr[i];
	}
}

// �Ҹ��� - �տ� ���� �޸� �Ҵ��� �� ptr �޸� ��ȯ 
Array::~Array() {
	delete[] ptr;
}

int Array::getsize()const {
	return size;
}

// ������ �����ε�
// ���� ������
const Array& Array::operator=(const Array& right) {
	
	// this pointer�� �����ڸ� �θ� ��ü�� ù ��° �ǿ����ڰ� �ȴ�.
	if (&right != this) {

		// �迭�� ũ�� �ٸ� ��츦 ����
		if (size != right.size) {

			// �迭�� ũ�Ⱑ �ٸ��� ���� �迭�� �����ϰ� ���Ӱ� �迭�� ����� ����
			delete[]ptr;
			size = right.size;
			ptr = new int[size];
		}

		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i];
		}
	}

	// ��ȯ���� ù �ǿ������� ������ �Ѵ�.
	return *this;
}

// �� ������
bool Array::operator==(const Array& right) const {

	// �迭�� ũ�Ⱑ �ٸ������� �Ǵ�
	if (size != right.size) {
		return 0;
	}

	// �迭 �� �ϳ��ϳ� ��
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
	// �迭�� ������ ũ�⸦ �Ѿ�� error message ���
	if (n < 0 || n >= size) {
		cerr << "out of range" << endl;
		exit(1);
	}

	return ptr[n];
}

int Array::operator[](int n) const {
	// �迭�� ������ ũ�⸦ �Ѿ�� error message ���
	if (n < 0 || n >= size) {
		cerr << "out of range" << endl;
		exit(1);
	}
	
	return ptr[n];
}

// <���� �Լ�>
// << ������
ostream& operator<<(ostream& output, const Array& a) {
	int i;
	for (i = 0; i < a.size; i++) {

		output << setw(5) << a.ptr[i];

		// �׳� Ȯ���ϱ� ���ϱ� ���� ���
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

// �迭�� �� ���ҳ��� ���ϴ� ������
Array operator+(const Array& a, const Array& b) {
	// �� �迭�� ũ�Ⱑ �ٸ��ٸ� ������ ����.
	if (a.size != b.size) {
		cout << "Error: different size." << endl;
		return Array(); // �� �迭 ��ȯ
	}
	else {
		Array sum(a.size); // �� �迭�� ���� ����� ������ ���ο� �迭 ����
		cout << sum;
		for (int i = 0; i < a.size; i++) {
			cout << i << endl;
			sum[i] = a[i] + b[i];
			cout << sum[i] << endl;
		}
		return sum;
	}
}