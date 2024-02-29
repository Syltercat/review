#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
	// ���� �Լ�
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);

#pragma region +�� ���� �Լ��� ������ ����
	// +�� ��� ����Լ��� �����ϸ� ������ ù ��° �ǿ����ڿ� ���� ȣ��ȴ�.
	// �׷��� ���� �Լ��� ������ ��� �� �迭�� ������� �Ű������� ���� �� �ִ�.
	// �̴� �� �迭�� ���꿡�� ������ ������ �Ѵٴ� ������ �� �� �ݿ��� �� �ִ�.
	
	// ���� ������ ���� ��� �Լ����� �ٸ� �����ڵ��� ���� �Լ��� ������ �� �ִ�.
#pragma endregion
	friend Array operator+(const Array&, const Array&);

public:
	Array(int = 10);
	Array(const Array&); //���� ������
	~Array();
	int getsize()const;

#pragma region ��� �Լ��� ������ +, ���/���� �Լ������� const
	// Array& operator+(const Array&) const; ���·� �ۼ��ϸ� ��� �Լ��ε� ������ �� �ִ�.
	// �������� const�� ���̴� ������ �Լ��� ȣ��Ǵ� ��ü�� ���¸� �������� ���ϰ� �ϱ� �����̴�.

	// friend �Լ��� ����� ���� �Լ��� ��� �Լ� ���� const�� ���� �� ���� ������ ������ �ʾҴ�.
	// �����Լ��� friend �Լ��� Ư�� ��ü�� �޼��尡 �ƴϱ� ������ ȣ��Ǵ� "��ü"�� �������� �ʾƼ�
	// �����Լ����� ��ü�� �������� �ʰڴٴ� �ǵ��� �Ű������� const Ű���带 ��������ν� ǥ���Ѵ�.
#pragma endregion

	const Array& operator=(const Array&);	// ���� ������, �迭�� ��ȯ

	bool operator==(const Array&) const;	// �� ������, �� or ���� ��ȯ
	bool operator!=(const Array&) const;

	// indexing ������, �迭 ���� Ư�� ���� ��ȯ
	int& operator[](int);					// l-value	
	int operator[](int)const;				// r-value, r-value�� ����ڰ� ������ �� ���� ������ const �ٿ���.
	
	// 43, 44 line ������
	/*
	 -  int& operator[](int);�� ��쿡�� �ش� ��Ҹ� ���� ������ �� �ְ� ���ش�.
		Array myArray; myArray[0] = 10;�� ���� ��� �����ϴ�.

	-   int operator[](int)const;�� ��쿡�� �迭�� Ư�� ��ҿ� ���� ���纻�� �����Ѵ�.
		�б⸸ �����ϰ� ������ �Ұ��ϴ�. const Array myArray; int val = myArray[0];�� ���� ��� �����ϴ�.
	*/

private:
	int size;	// �迭 size
	int* ptr;	// �迭 ù ���� �ּ�
};

#endif // !ARRAY_H
