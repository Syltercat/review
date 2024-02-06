#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
	// 전역 함수
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);

#pragma region +를 전역 함수로 선언한 이유
	// +의 경우 멤버함수로 선언하면 받으면 첫 번째 피연산자에 대해 호출된다.
	// 그러나 전역 함수로 선언할 경우 두 배열을 명시적인 매개변수로 받을 수 있다.
	// 이는 두 배열이 연산에서 동등한 역할을 한다는 개념을 더 잘 반영할 수 있다.
	
	// 같은 이유로 밑의 멤버 함수들을 다른 연산자들을 전역 함수로 선언할 수 있다.
#pragma endregion
	friend Array operator+(const Array&, const Array&);

public:
	Array(int = 10);
	Array(const Array&); //복사 생성자
	~Array();
	int getsize()const;

#pragma region 멤버 함수로 선언한 +, 멤버/전역 함수에서의 const
	// Array& operator+(const Array&) const; 형태로 작성하면 멤버 함수로도 선언할 수 있다.
	// 마지막에 const를 붙이는 이유는 함수가 호출되는 객체의 상태를 변경하지 못하게 하기 위함이다.

	// friend 함수로 선언된 전역 함수의 경우 함수 끝에 const를 붙일 수 없기 때문에 붙이지 않았다.
	// 전역함수나 friend 함수는 특정 객체의 메서드가 아니기 때문에 호출되는 "객체"가 존제하지 않아서
	// 전역함수에서 객체를 수정하지 않겠다는 의도는 매개변수에 const 키워드를 사용함으로써 표현한다.
#pragma endregion

	const Array& operator=(const Array&);	// 대입 연산자, 배열을 반환

	bool operator==(const Array&) const;	// 비교 연산자, 참 or 거짓 반환
	bool operator!=(const Array&) const;

	// indexing 연산자, 배열 안의 특정 값을 반환
	int& operator[](int);					// l-value	
	int operator[](int)const;				// r-value, r-value는 사용자가 변경할 수 없기 때문에 const 붙여줌.
	
	// 43, 44 line 차이점
	/*
	 -  int& operator[](int);의 경우에는 해당 요소를 직접 수정할 수 있게 해준다.
		Array myArray; myArray[0] = 10;와 같이 사용 가능하다.

	-   int operator[](int)const;의 경우에는 배열의 특정 요소에 대한 복사본을 제공한다.
		읽기만 가능하고 수정은 불가하다. const Array myArray; int val = myArray[0];와 같이 사용 가능하다.
	*/

private:
	int size;	// 배열 size
	int* ptr;	// 배열 첫 값의 주소
};

#endif // !ARRAY_H
